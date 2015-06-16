#!/usr/bin/env python3

import sys
from PyQt4.QtGui import QApplication

import llib
from  llib import main_page




if __name__ == "__main__":
	
        print("works")
        app = QApplication(sys.argv)
        main = llib.main_page()
        main.show()
        app.exec_()

