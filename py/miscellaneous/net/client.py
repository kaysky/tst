#!/usr/bin/env python3
import socket               # Import socket module
from screener import ScreenShoot

s = socket.socket()         # Create a socket object
host = socket.gethostname() # Get local machine name
port = 10001                 # Reserve a port for your service.

s.connect((host, port))
#s.send(b"Hello server!")
sh = ScreenShoot("n2.png")
name = sh.makeFile()
print (name)
f = open(name,'rb')
print( 'Sending...')
l = f.read(1024)
while (l):
    print ('Sending...')
    s.send(l)
    l = f.read(1024)
f.close()
print ("Done Sending")
#print ( s.recv(1024))
s.shutdown(socket.SHUT_WR)
s.close                     # Close the socket when done


