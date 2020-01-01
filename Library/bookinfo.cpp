#include "bookinfo.h"
#include "ui_bookinfo.h"
#include"searchbook.h"
#include"addnewbook.h"
#include<QMessageBox>
#include<QPainter>
#include<QTextCodec>

BookInfo::BookInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookInfo)
{
    ui->setupUi(this);
    ui->lineEdit_5->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_3->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_4->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_7->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_8->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_9->setFocusPolicy(Qt::NoFocus);
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());
}

BookInfo::~BookInfo()
{
    delete ui;
}

void BookInfo::paintEvent(QPaintEvent *){

    QPainter add(this);
    add.drawPixmap(0,0,width(),height(),QPixmap("../Image/bk3.jpg"));
    add.end();
}

void BookInfo::on_pushButton_2_released()
{
    AllManage *all = new AllManage;
    this->close();
    all->show();
}

void BookInfo::on_pushButton_4_released()
{
    SearchBook *search = new SearchBook;
    QString name = ui->lineEdit_1->text();

    int ISBN = ui->lineEdit_2->text().toInt();
    int type = ui->lineEdit_6->text().toInt();


    if(ui->lineEdit_1->text()==NULL){
        QMessageBox::information(this, "错误", "请输入图书姓名！");
    }else if(type != 1 && type !=2){
        QMessageBox::information(this, "错误", "请输入正确图书序号！");
    }else if(!search->isExistISBN(type,ISBN,name)){
        QMessageBox::information(this, "错误", "无该图书信息！");
    }else
    {

     QString pulisher = QString::fromLocal8Bit(AddNewBook::bookInfo->bookPublisher);
     QString writer = QString::fromLocal8Bit( AddNewBook::bookInfo->bookWriter);
     QString ISBN = QString::number( AddNewBook::bookInfo->bookISBN);
     QString bookNum = QString::number( AddNewBook::bookInfo->booksNum);
     QString bookAllNum = QString::number (AddNewBook::bookInfo->bookAllNum);
     QString bookPrice = QString::number( AddNewBook::bookInfo->bookPrice);
     QString bookTime = QString::number (AddNewBook::bookInfo->bookTime);

     QString bookType;

     if( AddNewBook::bookInfo->bookType == 1){
         bookType = "自然科学";
     }else{
         bookType="文学著作";
     }
     ui->lineEdit_7->setText(pulisher);
     ui->lineEdit_8->setText(bookPrice);
     ui->lineEdit_9->setText(bookTime);
     ui->lineEdit_6->setText(bookType);
     ui->lineEdit_3->setText(writer);
     ui->lineEdit_4->setText(bookAllNum);
     ui->lineEdit_5->setText(bookNum);
    }

}


void BookInfo::on_pushButton_3_released()
{
    StackTools *stackTools = new StackTools;
    if(ui->lineEdit_4->text() == NULL){
        QMessageBox::information(this, "错误", "请输入正确图书信息！");
    }else{
    QMessageBox::information(this, "注意", "确认清除此书吗！");
    stackTools->clearBook(AddNewBook::bookArray,AddNewBook::bookIndex,AddNewBook::bookInfo->bookType);
    AllManage *all = new AllManage;
    this->close();
    all->show();
    }
}












