#!/usr/bin/env python3

import subprocess
from threading import Timer


class Scheduler:

    def __init__(self):
        self.fnList = dict()

    def fnWrapper(self,delay,pfn):
        pfn()
        Timer(delay,self.fnWrapper,(delay,pfn)).start()

    #name-description of function fn-pointer to function, delay-period of time in seconds
    def append(self, name, fn, delay):
        self.fnList[name] = (fn,delay,lambda delay,fn : self.fnWrapper(delay,fn))

    def proceed(self,fn,delay,wraper):
        wraper(delay,fn)

    def loop(self):
        #print('fnList => ',list(self.fnList.values()))
        for param in self.fnList.values():
            self.proceed(*param)

def shut():
    cmd = 'xset dpms force off'
    subprocess.Popen(cmd, shell=True)

if __name__ == '__main__':
    scheduler = Scheduler()
    scheduler.append('display OFF service',shut,30)
    shut()
    scheduler.loop()
