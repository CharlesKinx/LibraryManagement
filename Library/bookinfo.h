#ifndef BOOKINFO_H
#define BOOKINFO_H

#include <QWidget>
#include"structs.h"
namespace Ui {
class BookInfo;
}

class BookInfo : public QWidget
{
    Q_OBJECT

public:
    explicit BookInfo(QWidget *parent = nullptr);
    ~BookInfo();
protected:

      void paintEvent(QPaintEvent*);

private slots:
    void on_pushButton_2_released();
    void on_pushButton_4_released();
    void on_pushButton_3_released();

private:
    Ui::BookInfo *ui;
    Books* book;
};

#endif // BOOKINFO_H
