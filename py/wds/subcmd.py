#!/usr/bin/env python3

import subprocess

if __name__ == '__main__':

    cmd = "ps +nc axo pid,stat,command |egrep -e 'somebot.py$'"
    #cmd = "ps axo pid,stat,command |egrep -e 'somebot.py$'"    #just in case if there is no CW
    PIPE = subprocess.PIPE

    p = subprocess.Popen(cmd, shell=True, stdout=PIPE, universal_newlines=True)
    ret = p.stdout.read()
    if(ret):
        tmp = ret.split(' ')
        print(tmp)
        print(len(tmp))
        print(tmp[1][0])
        #print(ret.split(' ')[2])

    #subprocess.Popen("./somebot.py", shell=True, start_new_session=True)

    #print('main process works')
    #for i in range(4):
        #time.sleep(2)
    #print('main process ends')
