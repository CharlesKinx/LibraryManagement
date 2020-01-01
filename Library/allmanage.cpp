#include "allmanage.h"
#include "ui_allmanage.h"
#include"mainwindow.h"
#include<QPainter>
#include<readerinfo.h>
AllManage::AllManage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AllManage)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());
}

AllManage::~AllManage()
{
    delete ui;
}

void AllManage::paintEvent(QPaintEvent *){

    QPainter add(this);
    add.drawPixmap(0,0,width(),height(),QPixmap("../Image/bk3.jpg"));
    add.end();
}

void AllManage::on_pushButton_2_released()
{
    MainWindow *mainwin = new MainWindow;
    this->close();
    mainwin->show();
}

void AllManage::on_pushButton_released()
{
    this->close();
    ReaderInfo *read = new ReaderInfo;
    read->show();
}

void AllManage::on_pushButton_3_released()
{
    this->close();
    BookInfo *book = new BookInfo;
    book->show();
}
