#!/usr/bin/env python3
import os
import time
import signal

Loop = True

def handler(signum,frame):
    global Loop
    print('got signal : ', signum)
    Loop = False

signal.signal(signal.SIGINT,handler)


print('TEST ')

while(Loop):
    time.sleep(2)
    print(time.ctime())

print('END of the test')
