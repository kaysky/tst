#!/usr/bin/python3
# some introspection
#

import sys


class base():
    """docstring for """
    def __init__(self, arg):
        self.arg = arg

    def fun_base(self):
        pass


class A:

    def __init__(self):
            self.a = 'some string'
            self.b = 10
            print('class a')

    def fun1(self):
            print('fun1')

    def fun2(self):
            print('fun2')

if __name__ == '__main__':
    print('works')

    a = A()
    bb = base(10)

    for i in dir(a):
        print(i)

    print('=>>>')
    print(A.__dict__.items())

    print("test string")
    print("jedi print")
    print(sys.__name__)

    a.a = "tst"
    a.fun1()
    bb.fun_base()
