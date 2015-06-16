#!/usr/bin/env python3

from PyQt4 import QtCore, QtGui
import form_ui
import sys
import cli
import _thread as th
import asyncore

#def send_to_srv(msg):
    #cli.send_message(msg)

class client_ui(QtGui.QWidget,form_ui.Ui_Form):

    def __init__(self):
        QtGui.QWidget.__init__(self)
        self.setupUi(self)
        self.setupSlots()
        self.client = cli.Client('localhost', 10001, self)

        self.listmodel = QtGui.QStandardItemModel()
        self.prItem = self.listmodel.invisibleRootItem()
        self.listView.setModel(self.listmodel)
        self.idx = None

    def setupSlots(self):
        self.sendButton.clicked.connect(self.handler)
        self.addButtontolist.clicked.connect(self.add2list)
        self.delButtonfromlist.clicked.connect(self.delfromlist)
        self.listView.clicked.connect(self.some_print)

    def handler(self):
        #self.lineEdit.setText('test message from button')
        #self.textEdit.setText('test message from button')
        #self.textEdit.append('test message from button ver.2')
        self.textEdit.append(self.lineEdit.text())
        self.client.send_message('srv <== ' + self.lineEdit.text())
        self.lineEdit.clear()

    def add2list(self, portnumber='port #'):
        item =  QtGui.QStandardItem(portnumber)
        #item.setData(obj)
        self.prItem.appendRow(item)

    def delfromlist(self):
        #q = self.prItem.rowCount()
        #self.textEdit.append(str('q = > %d' % q))
        #self.textEdit.append('dell from list')
        r = self.prItem.removeRow(self.idx)

    def some_print(self,modIdx):#deselectedId
        self.idx = modIdx.row()
        self.textEdit.append(str('chosen = > %d client' % self.idx))



if __name__ == "__main__":

    app = QtGui.QApplication(sys.argv)
    #cli = cli.Client('localhost', 10001)
    cli_ui = client_ui()
    cli_ui.show()


    th.start_new_thread(asyncore.loop,(0,))
    sys.exit(app.exec_())
