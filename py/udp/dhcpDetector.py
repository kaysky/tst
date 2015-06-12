#!/usr/bin/env python3

import socket

#UDP_IP = "0.0.0.0"
UDP_IP = "255.255.255.255"
UDP_PORT = 68

sock = socket.socket(socket.AF_INET, # Internet
                     socket.SOCK_DGRAM) # UDP
sock.bind((UDP_IP, UDP_PORT))

while True:
    data, addr = sock.recvfrom(2048) # buffer size is 1024 bytes
    print("received message:", data.decode())
