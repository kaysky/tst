#!/usr/bin/env python3

import socket
import struct

UDP = struct.Struct('!HHHH')
#d = UDP.pack(55,56,0,0)
#print('udp => ',d)
#print(UDP.unpack(d))


FILTER=''.join([(len(repr(chr(x)))==3) and chr(x) or '.' for x in range(256)])

#def dump(src, length=8):
    #N=0; result=''
    #while src:
       #s,src = src[:length],src[length:]
       ##print('s = ',s)
       #hexa = ' '.join(["%02X"%ord(x) for x in s])#ord
       #s = s.translate(FILTER)
       #result += "%04X   %-*s   %s\n" % (N, length*3, hexa, s)
       #N+=length
    #return result

def dump(src, length=8):
    N=0; result=''
    while src:
        s,src = src[:length],src[length:]
        N+=length
        s = UDP.unpack(s)
        print('dump:',s)


def main():
  """
  Пример использования сокетов прямого доступа (SOCK_RAW).
  Сниффет только TCP пакеты. Чтобы посниффить udp пакеты надо указать socket.IPPROTO_UDP,
  аналогично и для ICMP: socket.IPPROTO_ICMP
  Для запуска сниффера нужны права суперпользователя!
  """
  
  num_of_packets = 1
  s = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket.IPPROTO_UDP)    #IPPROTO_TCP
  for i in range(0, num_of_packets):
    packet = s.recv(16000)
    print("Got a %d byte packet\n" % len(packet))
    print(packet)
    dump(packet)
    #print(dump(packet))
  
if __name__ == '__main__':
  main()
