#ifndef RETURNBOOK_H
#define RETURNBOOK_H

#include <QWidget>
#include"structs.h"

namespace Ui {
class ReturnBook;
}

class ReturnBook : public QWidget
{
    Q_OBJECT

public:
    explicit ReturnBook(QWidget *parent = nullptr);
    ~ReturnBook();
    static int index;
    static int bookIndex;
protected:

      void paintEvent(QPaintEvent*);
private slots:
    void on_pushButton_2_released();
    void on_pushButton_released();
    bool isExistBook(Books* book,Students* student);
    void AddReturnBook(Books* book);
    bool isExistStudent(Students* student);
    void returnBook();
private:
    Ui::ReturnBook *ui;
    Books* book;
    Students* student;

};

#endif // RETURNBOOK_H
