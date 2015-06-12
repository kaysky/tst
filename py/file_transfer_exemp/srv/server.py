#!/usr/bin/env python3

import asyncore
import argparse
# import sys


parser = argparse.ArgumentParser()
parser.add_argument('-v', '--version', help='version of it', action='store_true')
parser.add_argument("-p", "--port", help="адрес и порт модуля для подключения",
                    metavar="адрес:порт",
                    default="localhost:10001")


class EchoHandler(asyncore.dispatcher_with_send):

    def __init__(self, sck):
        asyncore.dispatcher_with_send.__init__(self, sck)
        # self.socket = sck
        self.f = open('tst.png', 'wb')

# for messages
#    def handle_read(self):
#        # data = self.recv(1024)
#        # data = pickle.loads(data)
#        # data = data.decode()
#        # print(data)
#        # self.parse_data(data)

# olf version
#    def handle_read(self):
#        data = self.recv(1024)
#        if b'eof' != data[::-3]:
#            self.f.write(data)
#        else:
#            self.f.write(data)
#            self.f.close()
#            print('got file')
#            print('session may be closed')

    def handle_read(self):
        data = self.recv(1024)
        if data:
            self.f.write(data)
        else:
            self.f.close()
            print('got file')
            print('session may be closed')
            self.close()

    def send_message(self, message):
        msg = message.encode(message)
        self.send(msg)

    def handle_error(self):
        print('some exception at %s' % self.__class__)


class EchoServer(asyncore.dispatcher):

    def __init__(self, host, port):
        asyncore.dispatcher.__init__(self)
        self.create_socket()
        self.set_reuse_addr()
        self.bind((host, port))
        self.listen(5)

    def handle_accepted(self, sock, addr):
        print('Incoming connection from %s/%s' % (sock, repr(addr)))
        EchoHandler(sock)

    def handle_close(self):
        print('some client closed')

    def handle_error(self):
        print('some exception 1')

if __name__ == '__main__':

    print('test srv ')

    args = parser.parse_args()
    if args.port:
        server = EchoServer('localhost', int(args.port.split(':')[1]))
    elif args.version:
        print('server version : 1.0.0.2')
    else:
        server = EchoServer('localhost', 10001)

    asyncore.loop()
