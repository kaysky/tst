#!/usr/bin/env python3

import asyncore
import socket
import argparse
import time
import _thread as th
import pickle
from threading import Timer
#import appcli


parser = argparse.ArgumentParser()
parser.add_argument('-v','--version', help='version of it', action='store_true')
parser.add_argument("-p", "--port", help="адрес и порт модуля NM для подключения",
                    metavar="адрес:порт",
                    default="localhost:10001")



class Client(asyncore.dispatcher):
    def __init__(self, host, port, gui):
        self.cli_ui = gui
        asyncore.dispatcher.__init__(self)
        self.create_socket()
        self.connect((host, port))
        #self.out_buffer = message
        self.msg = b''

    def handle_close(self):
        self.close()

    def handle_connect(self):
        pass
        #self.send(b'CONNECTED TEST')

    #def handle_write(self):
        #pass

    def handle_read(self):
        data = self.recv(1024)
        #data = data.decode()
        data = pickle.loads(data)
        print('')
        print(data)
        self.parse_data(data)

    def send_message(self, message):
        msg = pickle.dumps(message)
        self.send(msg)
        #self.send(message.encode())

    def parse_data(self, data):
        ''' '''
        if '<msg>' in data:
            self.parse_msg(data)
            return
        elif '<cmd>' in data:
            self.parse_cmd(data)
        else :
            return

    def parse_msg(self, data):
        ##todo delete 'msg tag here'
        self.cli_ui.textEdit.append('srv ==> ' + data)  #comment it for console version


    def parse_cmd(self, data):
        if 'ls' in data:
            self.cli_ui.add2list(data)
            self.cli_ui.textEdit.append(data)



def write_to_srv(obj) :
    cli = obj
    flag = True
    while flag :
        msg = input('enter message :')
        cli.send_message(msg)
        if msg == 'end' :
            flag = False


if __name__ == '__main__':


    print('test client ')

    args = parser.parse_args()
    if args.port:
        cli = Client(args.port.split(':')[0], int(args.port.split(':')[1]))
    elif args.version:
        print('client version : 1.0.0.1')
    else :
        cli = Client('localhost', 10001)

    i = 0
    while i < 2:
        i += 1
        #cli.send_message('message #%d' % i)
        s = 'message #%d' % i
        Timer(i,cli.send_message,(s,)).start()

    th.start_new_thread(write_to_srv,(cli,))


    asyncore.loop()






