#!/usr/bin/env python3
"""
выполняется на сервере, выводит разметку HTML для создания новой страницы;
url=http://localhost/cgi-bin/tutor0.py
"""


print('Content-type: text/html\n')
print('<HTML>')
print('<TITLE>CGI 101</TITLE>')
print('<BODY>')
print('<H1>A First CGI Script</H1>')
print('<P>Hello, CGI World!</P>')
#print('<A href="/home/konst/work/tests/python_tst/web/tutor0.html">tutor0 page</A>')
#print('<A href="tutor1.html">tutor1 page</A>')
print('</BODY></HTML>')
