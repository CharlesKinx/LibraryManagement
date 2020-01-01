#ifndef LENDBOOK_H
#define LENDBOOK_H

#include <QWidget>
#include"structs.h"
namespace Ui {
class LendBook;
}

class LendBook : public QWidget
{
    Q_OBJECT

protected:

      void paintEvent(QPaintEvent*);

public:
    explicit LendBook(QWidget *parent = nullptr);
    ~LendBook();
    static StudentArray* studentArray;
    static Students* studentInfo;
    static int index;
    Books* book;
    bool isExistStudent(Students* student);
    bool isExistBook(Books* book);
private slots:
    void on_pushButton_2_released();
    void on_pushButton_released();
    void addNewStudents(Students* students,Books* books);
private:
    Ui::LendBook *ui;
    Students* student;


    bool noBook;
};

#endif // LENDBOOK_H
