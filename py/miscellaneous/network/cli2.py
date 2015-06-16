#!/usr/bin/env python3


import sys
from socket import *


if __name__ == '__main__':
    # переносимый интерфейс сокетов плюс константы
    serverHost = 'localhost' # имя сервера, например: 'starship.python.net'
    serverPort = 10001
    # незарезервированный порт, используемый сервером
    message = [b'Hello network world']
    # текст, посылаемый серверу обязательно
    # типа bytes: b'' или str.encode()
    if len(sys.argv) > 1:
        serverHost = sys.argv[1]
    # сервер в аргументе 1 командной строки
    if len(sys.argv) > 2:
        # текст в аргументах командной строки 2..n
        message = (x.encode() for x in sys.argv[2:])
    sockobj = socket(AF_INET, SOCK_STREAM)
    sockobj.connect((serverHost, serverPort))
    # создать объект сокета TCP/IP
    # соединение с сервером и портом
    for line in message:
        sockobj.send(line)
    # послать серверу строчку через сокет
    data = sockobj.recv(1024)
    # получить строку от сервера: до 1k
    print('Client received:', data) # строка bytes выводится в кавычках,
    # было `x`, repr(x)
    sockobj.close()
    # закрыть сокет, чтобы послать серверу eof


    #print('cli2')
