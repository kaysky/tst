#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from PyQt4 import QtCore, QtGui


class prj:

     def __init__(self,name,begin,end):
         self.name = name
         self.begin = begin
         self.end = end

class prj_schedule(QtCore.QAbstractTableModel):

    def __init__(self):
            QtCore.QAbstractTableModel.__init__(self)
            self.nrow = 0
            self.ncolumn = 0
            self.headers = ('Имя','Начало','Конец')
            self.lst = list()
            self.lst.append(prj('prg1','10/10/70','10/10/70'))
            self.lst.append(prj('prg2','10/14/30','10/10/70'))
            self.lst.append(prj('prg3','100/10/70','10/10/70'))
            self.lst.append(prj('prg4','50/10/10','10/10/70'))

    def rowCount(self,parent):
        return self.lst.__len__();

    def columnCount(self,parent):
        return 3;

#    def headerData(self,section, orientation, role):
#        return header_data
    def flags(self, index):
        return QtCore.QAbstractItemModel.flags(self,index) | QtCore.Qt.ItemIsEditable

    def data(self,index,role):
#        if (!index.isValid || index.row() >= self.lst.__len__()):
#            return QtCore.QVariant
        if index.column() == 0:
            return self.lst[index.row()].name
        if index.column() == 1:
            return self.lst[index.row()].begin
        if index.column() == 2:
            return self.lst[index.row()].end

#    def setData(self,index, value, role):
#        if (index.isValid):
#            self.lst




#    def insertRows(self, row, count, parent = self):



class ExampleDelegate(QtGui.QItemDelegate):

    def __init__(self):
        QtGui.QItemDelegate.__init__(self)

    def createEditor(self, parent, option, index):
        editor =  QtGui.QDateTimeEdit(parent)
        editor.setDisplayFormat("dd.MM.yyyy")
        editor.setCalendarPopup(True)
        editor.setDate(QtCore.QDate.currentDate())
        return editor

    def setEditorData(self,editor, index):
        dateEditor = QtGui.QDateTimeEdit(editor)
        if (dateEditor):
            dateEditor.setDate(QtCore.QDate.fromString(index.model().data(index, QtCore.Qt.EditRole).toString(),"dd.MM.yyyy"))

    def setModelData(self, editor, model,index):
        dateEditor = QtGui.QDateTimeEdit(editor)
        if(dateEditor):
            model.setData(index, dateEditor.date().toString("dd.MM.yyyy"))



if __name__ == '__main__':

        print("works")
