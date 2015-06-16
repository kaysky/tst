#!/usr/bin/env python3

import math

K = 3.14/180
R = 460
cX = 482
cY = 497

if __name__ == '__main__':

    print('Count x/y numbers:')
    for i in range(360):
        if (i%15 == 0):
            r = i*K
            x = R*math.cos(r) + cX
            y = R*math.sin(r) + cY
            print(i,' has x =',x," y = ",y)

