#!/usr/bin/env python3

import subprocess


class ScreenShoot:

    def __init__(self, name="sreenshoot"):
        self.name = name
        self.cmd = "xwd -root -out " + name

    def makeFile(self):
        subprocess.check_call(self.cmd, shell=True)
        return self.name


if __name__ == '__main__':

    sh = ScreenShoot("tst.png")
    name = sh.makeFile()
    print(name)
