#!/usr/bin/env python2

#import functools


print reduce(lambda x, y: x+y, filter(lambda x: x%2, map(lambda x: x*x, xrange

        (10**6)))) == sum(x*x for x in xrange(1, 10**6, 2))



#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#firstCount = functools.reduce(lambda x, y: x+y, filter(lambda x: x%2, map(lambda x: x*x, range(10**6))))
#secondCount = sum(x*x for x in range(1, 10**6, 2))
#result = (firstCount == secondCount)
#print(firstCount,"    ",secondCount)
#print("result is:",result)
#
#range(N) возвращает последовательность элементов от 0 до N
#sum(x*x for x in xrange(1, 10**6, 2) сумма квадратовот последовательности [1,3,5,...999999]
#map(lambda x: x*x, xrange(10**6))) выполняет ф-ю для каждого элемента последовательности
#filter(lambda x: x%2, range(10)) отфильтрует все елементы для которых функция возвращает true
