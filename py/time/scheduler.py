#!/usr/bin/env python3


import sched, time
import _thread as thread

s = sched.scheduler(time.time, time.sleep)

def print_time(a='default'):
    print("From print_time", time.ctime(), a)

def print_some_times():
    print(time.ctime())
    s.enter(5, 1, print_time)
    s.enter(2, 2, print_time, argument=('positional',))
    s.enter(2, 1, print_time, kwargs={'a': 'keyword'})
    s.run()
    print(time.ctime())

def abs_print_some_times():
    print(time.ctime())
    s.enterabs(10, 1, print_time)
    s.enterabs(5, 2, print_time, argument=('positional',))
    s.enterabs(5, 1, print_time, kwargs={'a': 'keyword'})
    s.run()
    print(time.ctime())


def fun_loop(mode = None,q = 0):
    if mode == 'abs':
        abs_print_some_times()
    else :
        for i in range(q):
            print_some_times()

if __name__ == '__main__':

    thread.start_new_thread(fun_loop,(0,2))
    #thread.start_new_thread(fun_loop,('abs',))

    print('main start at: ',time.ctime())
    time.sleep(8)
    print('main end at: ',time.ctime())
