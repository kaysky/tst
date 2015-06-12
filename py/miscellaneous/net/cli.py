#!/usr/bin/env python3


import sys
from socket import *
from screener import ScreenShoot


if __name__ == '__main__':

    sh = ScreenShoot("n1.png")
    name = sh.makeFile()
    print(name)
    file = open(name, 'rb')
    serverHost = "localhost"  # имя сервера, например: 'starship.python.net'
    serverPort = 10001
    sockobj = socket(AF_INET, SOCK_STREAM)
    sockobj.connect((serverHost, serverPort))
    print ('Sending...')
    l = file.read(1024)
    while (l):
        print ('Sending...')
        sockobj.send(l)
        l = file.read(1024)

    file.close()

    socket.shutdown(socket.SHUT_WR)
    sockobj.close()

