#!/usr/bin/env python3

import asyncore
import argparse
import sys
import pickle


parser = argparse.ArgumentParser()
parser.add_argument('-v','--version', help='version of it', action='store_true')
parser.add_argument("-p", "--port", help="адрес и порт модуля NM для подключения",
                    metavar="адрес:порт",
                    default="localhost:10001")

class EchoHandler(asyncore.dispatcher_with_send):

    def __init__(self,sck,dic):
        asyncore.dispatcher_with_send.__init__(self,sck)
        self.clis = dic
        #self.socket = sck

    def handle_read(self):
        data = self.recv(1024)
        data = pickle.loads(data)
        #data = data.decode()
        print(data)
        self.parse_data(data)
        #if data:
            #if 'ls' in data :
                ##print(str(list(self.clis)))
                ##msg = str(list(self.clis)).encode()
                ##msg = pickle.dumps(list(self.clis))
                #self.send_message(str(list(self.clis)))# temporaly str()
            #else :
                #self.send_message(data)

            ##print('data => ',data)
        ##else :
            ##sys.exit()

    def send_message(self, message):
        msg = pickle.dumps(message)
        self.send(msg)

    def parse_data(self, data):
        ''' '''
        if '<msg>' in data:
            self.parse_msg(data)
        elif '<cmd>' in data:
            self.parse_cmd(data)
        else :
            return

    def parse_msg(self, data):
        ##todo delete 'msg tag here'
        if data:
            self.send_message(data)


    def parse_cmd(self, data):
        if data:
            if 'ls' in data :
                #print(str(list(self.clis)))
                #msg = str(list(self.clis)).encode()
                #msg = pickle.dumps(list(self.clis))
                self.send_message('<cmd> ls' + str(list(self.clis)))# temporaly str()

    def handle_error(self):
        print('some exception at %s' % self.__class__)
        del self.clis[self.addr]



class EchoServer(asyncore.dispatcher):


    def __init__(self, host, port):
        asyncore.dispatcher.__init__(self)
        self.create_socket()
        self.set_reuse_addr()
        self.bind((host, port))
        self.listen(5)
        self.clients = dict()

    def handle_accepted(self, sock, addr):
        print('Incoming connection from %s/%s' % (sock, repr(addr)) )
        handler = EchoHandler(sock,self.clients)
        #handler = EchoHandler(sock)
        self.clients[addr] = sock
        #print(list(asyncore.socket_map))
        #print(handler.__class__)

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
        print('server version : 1.0.0.1')
    else :
        server = EchoServer('localhost', 10001)



    asyncore.loop()





