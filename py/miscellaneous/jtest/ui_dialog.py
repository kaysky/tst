# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'dialog.ui'
#
# Created: Tue Jul  8 17:28:52 2014
#      by: PyQt4 UI code generator 4.10.4
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

try:
    _fromUtf8 = QtCore.QString.fromUtf8
except AttributeError:
    def _fromUtf8(s):
        return s

try:
    _encoding = QtGui.QApplication.UnicodeUTF8
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig, _encoding)
except AttributeError:
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig)

class Ui_Form(object):
    def setupUi(self, Form):
        Form.setObjectName(_fromUtf8("Form"))
        Form.resize(533, 251)
        self.timeEdit = QtGui.QTimeEdit(Form)
        self.timeEdit.setGeometry(QtCore.QRect(140, 51, 118, 27))
        self.timeEdit.setObjectName(_fromUtf8("timeEdit"))
        self.dateEdit = QtGui.QDateEdit(Form)
        self.dateEdit.setGeometry(QtCore.QRect(260, 51, 110, 27))
        self.dateEdit.setObjectName(_fromUtf8("dateEdit"))
        self.timeEdit_2 = QtGui.QTimeEdit(Form)
        self.timeEdit_2.setGeometry(QtCore.QRect(140, 81, 118, 27))
        self.timeEdit_2.setObjectName(_fromUtf8("timeEdit_2"))
        self.dateEdit_2 = QtGui.QDateEdit(Form)
        self.dateEdit_2.setGeometry(QtCore.QRect(260, 81, 110, 27))
        self.dateEdit_2.setObjectName(_fromUtf8("dateEdit_2"))
        self.label = QtGui.QLabel(Form)
        self.label.setGeometry(QtCore.QRect(40, 56, 58, 17))
        self.label.setObjectName(_fromUtf8("label"))
        self.label_2 = QtGui.QLabel(Form)
        self.label_2.setGeometry(QtCore.QRect(40, 91, 58, 17))
        self.label_2.setObjectName(_fromUtf8("label_2"))
        self.btAdd = QtGui.QPushButton(Form)
        self.btAdd.setGeometry(QtCore.QRect(150, 190, 87, 27))
        self.btAdd.setObjectName(_fromUtf8("btAdd"))
        self.label_3 = QtGui.QLabel(Form)
        self.label_3.setGeometry(QtCore.QRect(40, 24, 91, 17))
        self.label_3.setObjectName(_fromUtf8("label_3"))
        self.lineEdit = QtGui.QLineEdit(Form)
        self.lineEdit.setGeometry(QtCore.QRect(140, 20, 231, 27))
        self.lineEdit.setObjectName(_fromUtf8("lineEdit"))
        self.btClose = QtGui.QPushButton(Form)
        self.btClose.setGeometry(QtCore.QRect(270, 190, 91, 27))
        self.btClose.setObjectName(_fromUtf8("btClose"))
        self.actionAdd = QtGui.QAction(Form)
        self.actionAdd.setObjectName(_fromUtf8("actionAdd"))
        self.actionClose = QtGui.QAction(Form)
        self.actionClose.setObjectName(_fromUtf8("actionClose"))

        self.retranslateUi(Form)
        QtCore.QObject.connect(self.btAdd, QtCore.SIGNAL(_fromUtf8("pressed()")), Form.slot_add)
        QtCore.QObject.connect(self.btClose, QtCore.SIGNAL(_fromUtf8("pressed()")), Form.close)
        QtCore.QMetaObject.connectSlotsByName(Form)

    def retranslateUi(self, Form):
        Form.setWindowTitle(_translate("Form", "Form", None))
        self.label.setText(_translate("Form", "Начало", None))
        self.label_2.setText(_translate("Form", "Конец", None))
        self.btAdd.setText(_translate("Form", "Добавить", None))
        self.label_3.setText(_translate("Form", "Имя проекта", None))
        self.btClose.setText(_translate("Form", "Закрыть", None))
        self.actionAdd.setText(_translate("Form", "add", None))
        self.actionClose.setText(_translate("Form", "close", None))

