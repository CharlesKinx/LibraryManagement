#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<QPaintEvent>
#include"addnewbook.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *){

    QPainter p(this);
    p.drawPixmap(0,0,width(),height(),QPixmap("../Image/bk3.jpg"));
    p.end();
}

void MainWindow::on_addBooks_2_released()
{
    this->close();
    addnewbook.show();
}

void MainWindow::on_pushButton_released()
{
    this->close();
}

void MainWindow::on_clearBooks_2_released()
{
    this->close();
    allmanage.show();
}

void MainWindow::on_lendBooks_2_released()
{
    this->close();
    lendbook.show();
}

void MainWindow::on_returnBooks_2_released()
{
    this->close();
    returnbook.show();
}
