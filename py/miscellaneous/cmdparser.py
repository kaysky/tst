#!/usr/bin/env python3

import argparse

parser = argparse.ArgumentParser()
parser.add_argument('-f','--foo', help='    allow you see the msg', action='store_true')
parser.add_argument('-ve','--verbous', help='some debug info', action='store_true')
parser.add_argument('-v','--version', help='version of it', action='store_true')
parser.add_argument("-n", "--nm", help="адрес и порт модуля NM для подключения",
                    metavar="адрес:порт",
                    default="localhost:10005")


if __name__ == '__main__':

    args = parser.parse_args()

    if args.foo:
        print('foo section')
    elif args.verbous:
        print('verbous section')
    elif args.version:
        print('1.0.0.1')
    elif args.nm:
        print(args.nm.split(':'))


    print('cmd parser programm ')
