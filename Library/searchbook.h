#ifndef SEARCHBOOK_H
#define SEARCHBOOK_H

#include <QWidget>
#include"allmanage.h"
#include"structs.h"
#include"addnewbook.h"
#include"bookinfo.h"


namespace Ui {
class SearchBook;
}

class SearchBook : public QWidget
{
    Q_OBJECT

signals:
    void sendBookInfo(Books*);

public:
    explicit SearchBook(QWidget *parent = nullptr);
    ~SearchBook();
    bool isExistISBN(int bookType,int bookISBN,QString name);
    bool isSameName(QString str,char* name);

private slots:
    void on_pushButton_2_released();

private:
    Ui::SearchBook *ui;
    Books* book;
    BookInfo bookInfo;
};

#endif // SEARCHBOOK_H
