#include "mainwindow.h"
#include <QApplication>
#include<stacktools.h>
#include<addnewbook.h>
#include"lendbook.h"
#include<QTextCodec>
#include"returnbook.h"
#include"readerinfo.h"

BookArray* AddNewBook::bookArray = (BookArray*)malloc(sizeof(BookArray));
Books* AddNewBook::bookInfo = (Books*)malloc(sizeof(Books));
StudentArray* LendBook::studentArray = (StudentArray*)malloc(sizeof(StudentArray));
Students* LendBook::studentInfo = (Students *)malloc(sizeof(Students));
int ReturnBook::index = 0;
int ReturnBook::bookIndex = 0;



int AddNewBook::bookIndex = 0;
int LendBook::index = 0;

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
