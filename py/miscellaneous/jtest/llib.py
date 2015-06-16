#!/usr/bin/env python3


import ui_main
import ui_dialog
import sys
from PyQt4 import QtCore, QtGui
from PyQt4.QtGui import QApplication

import model

class user_dlg(QtGui.QDialog,ui_dialog.Ui_Form):

    def __init__(self, parent=None):
        QtGui.QDialog.__init__(self, parent)
        self.setupUi(self)

    def slot_add(self):
            print('DLG button pushed')


class main_page(QtGui.QMainWindow, ui_main.Ui_MainWindow):

    def __init__(self, parent=None):
        QtGui.QMainWindow.__init__(self, parent)
        self.setupUi(self)

#        self.prjModel = QtGui.QStandardItemModel(4,4)
        self.prjModel = model.prj_schedule()
#        self.delg = model.ExampleDelegate()
        self.item = QtGui.QStandardItem("TEST item")
#        self.prjModel.setItem(0,0,self.item)

        self.tableView.setItemDelegate(model.ExampleDelegate())
        self.tableView.setModel(self.prjModel)

    def slot_add(self):
            print('button pushed')
            dlg = user_dlg()
            dlg.exec()


if __name__ == '__main__':
	
        print("works")
        app = QApplication(sys.argv)
        main = main_page()
        main.show()
        app.exec_()


