#!/usr/bin/env python3

import socket

UDP_IP = "255.255.255.255"
UDP_PORT = 67
MESSAGE = b"Hello, UDP World!"

print("UDP target IP:", UDP_IP)
print("UDP target port:", UDP_PORT)
print("message:", MESSAGE)

sock = socket.socket(socket.AF_INET, # Internet
                     socket.SOCK_DGRAM) # UDP
sock.sendto(MESSAGE, (UDP_IP, UDP_PORT))
