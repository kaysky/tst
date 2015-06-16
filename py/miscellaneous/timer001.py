#!/usr/bin/python3

from threading import Timer
import time
import _thread as thread

def fun1():
    print('Test function #1 : % s ' % time.ctime())
    Timer(0.5,fun1).start()


#template function
def wrap_fun(delay, pfn):
    pfn()
    Timer(delay,wrap_fun,(delay, pfn)).start()

class MyScheduler :

    def __init__(self):
        self.dlst = dict()

    def append(self, name, fn, delay):
        self.dlst[name] = wrap_fun(delay,fn)

    def loop(self,s=None):
        for fn in self.dlst.values():
            #Timer(fn[1],fn[0]).start()
            fn()

    #def proceed(self):
        #for fn in self.dlst.values():
            #Timer(fn[1],fn[0]).start()


def funA():
    print(' A = >  ', time.ctime())


def funB():
    print(' B = >  ', time.ctime())


def funC():
    print(' C = >  ', time.ctime())


if __name__ == '__main__':

    sced = MyScheduler()
    sced.append('funA',funA,1)
    sced.append('funB',funB,2)
    sced.append('funC',funC,3)

    #thread.start_new_thread(sced.loop,(1,))
    #sced.loop()


    print('main thread work')
