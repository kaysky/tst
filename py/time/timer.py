#!/usr/bin/python3

from threading import Timer
import time

def fun1():
    print('Test function #1 : % s ' % time.ctime())
    Timer(0.5,fun1).start()

#def tmp_fun():
    #print('tmp_fun')

#def wraper(fn):
    #tmp_fun = fn
    #tmp_fun()
    #Timer(0.5,wraper,(fn,)).start()


#template function
def wrap_fun(delay, pfn):
    pfn()
    print(pfn.__name__,'  ', time.ctime())
    Timer(delay,wrap_fun,(delay, pfn)).start()

class MyScheduler :

    def __init__(self):
        self.dlst = dict()

    def append(self, name, fn, delay):
        self.dlst[name] = wrap_fun(delay,fn)

    def loop(self):
        for fn in self.dlst.values():
            #Timer(fn[1],fn[0]).start()
            fn()

    #def proceed(self):
        #for fn in self.dlst.values():
            #Timer(fn[1],fn[0]).start()


def funA():
    print('message from A fan')


def funB():
    print('message from B fan')


def funC():
    print('message from C fan')


if __name__ == '__main__':

    fun1()
    #wraper(tmp_fun)
    #sced = MyScheduler()
    #sced.append('funA',funA,6)
    #sced.append('funB',funB,8)
    #sced.append('funC',funC,12)

    #sced.loop()


    print('main thread work')
