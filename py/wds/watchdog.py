#!/usr/bin/env python3
'''
            WDS - Watch-Dog service by Kovshevnikov Konstantin
'''
import sys
import argparse
import subprocess
from threading import Timer


parser = argparse.ArgumentParser()

parser.add_argument('-c',
                    '--cw',
                    help='use this option if you have CW (color wrapper)',
                    action='store_true'
                    )

parser.add_argument('-f',
                    '--cfg',
                    help='use this option if you want to use some cfgFile ',
                    metavar="file=Namefile"
                    )


class Scheduler:
    '''this class allows to add functions for periodical calls'''

    def __init__(self):
        self.fnList = dict()

    def fnWrapper(self, delay, pfn):
        pfn()
        Timer(delay, self.fnWrapper, (delay, pfn)).start()

    # name-description of function fn-pointer to function,
    # delay-period of time in seconds
    def append(self, name, fn, delay):
        self.fnList[name] = (fn,
                             delay,
                             lambda delay, fn: self.fnWrapper(delay, fn)
                             )

    def proceed(self, fn, delay, wraper):
        wraper(delay, fn)

    def loop(self):
        # print('fnList => ',list(self.fnList.values()))
        for param in self.fnList.values():
            self.proceed(*param)


class AppController:
    '''this class allows to describe service functions for WDS'''

    def __init__(self, cfgFile=None, colorWrapper=False):
        self.pipe = subprocess.PIPE
        self.prgName = './somebot.py'
        self.flagCW = 'no'
        if(cfgFile):
            # user defined with cfgFile
            self.readCfg(cfgFile)
            if(self.flagCW == 'yes'):
                self.cmd = "ps %s axo pid,stat,command \
                        |egrep -e '%s$'" % ('+nc', self.prgName)
            else:
                self.cmd = "ps axo pid,stat,command \
                        |egrep -e '%s$'" % (self.prgName)
        else:
            # default:
            if(colorWrapper):
                # default: with CW and watch somebot.py
                self.cmd = "ps +nc axo pid,stat,command \
                        |egrep -e 'somebot.py$'"
            else:
                # default: there is no CW and watch somebot.py
                self.cmd = "ps axo pid,stat,command |egrep -e 'somebot.py$'"

    def checkSatuse(self):
        try:
            p = subprocess.Popen(self.cmd,
                                 shell=True,
                                 stdout=self.pipe,
                                 stderr=self.pipe,
                                 universal_newlines=True
                                 )
            ret = p.stdout.read()
            err = p.stderr.read()
            if(err):
                raise subprocess.SubprocessError(err)
            # print('ERR =>', err)
            print('=>', ret.split())
            if(ret):
                tmp_str = ret.split()
                # print(tmp_str)
                if tmp_str[1][0] in ('T', 'Z', 'X'):
                    print('restart : ', self.prgName)
                    subprocess.call('kill -9 %s' % (tmp_str[0]), shell=True)
                    return True
                else:
                    return False
            else:
                return True
        except subprocess.SubprocessError as er:
            print('Error: wrong option for ps try with or without option -c :',
                  er
                  )
            sys.exit(1)

    def readCfg(self, fileName):
        try:
            f = open(fileName)
            lst = (s.strip() for s in f if s[0] != '#')
            cfg = {k: v for k, v in map(lambda s: tuple(s.split()), lst)}
            # print(cfg)
            self.prgName = cfg['prgName']
            self.flagCW = cfg['flagCW']
        except IOError as er:
            print('Error: file was not found :', er)
            sys.exit(1)
        except KeyError as er:
            print('Error: wron format of the config file.')
            print('Error: the key %s was not found.' % er)
            sys.exit()

    def watchApp(self):
        status = self.checkSatuse()
        if(status):
            print('started new proc of ', self.prgName)
            try:
                p = subprocess.Popen(self.prgName,
                                     stderr=self.pipe,
                                     shell=True,
                                     start_new_session=True,
                                     universal_newlines=True
                                     )
                err = p.stderr.read()
                if(err):
                    raise subprocess.SubprocessError(err)
            except subprocess.SubprocessError as er:
                print('Error: %s' % er)
                sys.exit(1)


if __name__ == '__main__':

    args = parser.parse_args()

    if args.cw:
        # print('cw section')
        app = AppController(colorWrapper=True)
    elif args.cfg:
        # print(args.cfg.split('='))
        app = AppController(cfgFile=args.cfg.split('=')[1])
    else:
        app = AppController()

    scheduler = Scheduler()
    scheduler.append('watch dog service', app.watchApp, 5)
    scheduler.loop()
