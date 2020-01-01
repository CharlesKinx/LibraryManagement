#ifndef ADDNEWBOOK_H
#define ADDNEWBOOK_H

#include <QWidget>
#include<QLineEdit>
#include"stacktools.h"
#include"structs.h"
namespace Ui {
class AddNewBook;
}

class AddNewBook : public QWidget
{
    Q_OBJECT

protected:

      void paintEvent(QPaintEvent*);

public:
    explicit AddNewBook(QWidget *parent = nullptr);
    ~AddNewBook();
    static BookArray* bookArray;
    static Books* bookInfo;
    static int  bookIndex;
     bool isSameName(char* newName,char* bookName);
private slots:
    void on_pushButton_2_released();
    void on_pushButton_released();
    void addNewBook(Books* book,int num);
    int isExistBooks(BookArray* bookArray,Books* book);

private:
    Ui::AddNewBook *ui;
    StackTools* stacktools;
    Books* book;
};


#endif // ADDNEWBOOK_H
