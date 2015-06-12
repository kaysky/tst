#!/usr/bin/env python3

import asyncore
import argparse
import _thread as th
from screener import ScreenShoot

# import pickle
# from threading import Timer

parser = argparse.ArgumentParser()
parser.add_argument('-v', '--version', help='version of it', action='store_true')
parser.add_argument("-p", "--port", help="адрес и порт модуля для подключения",
                    metavar="адрес:порт",
                    default="localhost:10001")


class Client(asyncore.dispatcher):

    def __init__(self, host, port):
        asyncore.dispatcher.__init__(self)
        self.create_socket()
        self.connect((host, port))

    def handle_close(self):
        self.close()

    def handle_connect(self):
        pass

    def handle_read(self):
        data = self.recv(1024)
        data = data.decode()
        print('received data :')
        print(data)

    def send_message(self, message):
        print('sending msg')
        msg = message.encode()
        self.send(msg)

#    def send_file(self, name):
#        print('Sending...', name)
#        for l in open(name, 'rb'):
#            self.send(l)
#        self.send_message('eof')
#        print('the file has just been sent')
#        self.close()

    def send_file(self, name):
        try:
            file = open(name, 'rb')
            while True:
                data = file.read(1024)
                if not data:
                    break
                sent = self.send(data)
                assert sent == len(data)
            print("file was sent")
            self.handle_close()
        except:
            print("Error downloading")
        self.close


if __name__ == '__main__':

    print('test client ')

    sh = ScreenShoot('tst.png')
    name = sh.makeFile()

    args = parser.parse_args()
    if args.port:
        cli = Client(args.port.split(':')[0], int(args.port.split(':')[1]))
    elif args.version:
        print('client version : 1.0.0.2')
    else:
        cli = Client('localhost', 10001)

    th.start_new_thread(cli.send_file, (name, ))

    asyncore.loop()
