#!/usr/bin/python3

from threading import Timer
import time

def fun1():

    #print('Test function #1')
    print(time.ctime())
    Timer(3,fun1).start()

#tm = Timer(7,fun1)

if __name__ == '__main__':

    #tm.start()
    fun1()
    print('main thread work')
