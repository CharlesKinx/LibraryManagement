#include "readerinfo.h"
#include "ui_readerinfo.h"
#include<QPainter>
#include<allmanage.h>
#include"lendbook.h"
#include<QMessageBox>

ReaderInfo::ReaderInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReaderInfo)
{
    ui->setupUi(this);
    ui->lineEdit_3->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_4->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_5->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_7->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_8->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_9->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_10->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_11->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_12->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_13->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_14->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_15->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_16->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_17->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_18->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_19->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_20->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_21->setFocusPolicy(Qt::NoFocus);
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());
}

ReaderInfo::~ReaderInfo()
{
    delete ui;
}
void ReaderInfo::paintEvent(QPaintEvent *){

    QPainter add(this);
    add.drawPixmap(0,0,width(),height(),QPixmap("../Image/bk3.jpg"));
    add.end();
}

void ReaderInfo::on_pushButton_2_released()
{
    this->close();
    AllManage *all = new AllManage;
    all->show();
}



bool ReaderInfo::isExistStudent(QString name,int ID){

    SearchBook *search = new SearchBook;
    for(int i =0;i<LendBook::studentArray->studentNum;i++){
        if(ID == LendBook::studentArray->studentarray[i]->studentID&&search->isSameName(name,LendBook::studentArray->studentarray[i]->name)){
            LendBook::studentInfo =LendBook::studentArray->studentarray[i];
            return true;
        }
    }
    return false;

}

void ReaderInfo::showFirstInfo(){
    QString name = QString::fromLocal8Bit( LendBook::studentInfo->lendBooks[0]->name);
    QString writr = QString::fromLocal8Bit( LendBook::studentInfo->lendBooks[0]->bookWriter);
    QString num = "1";
    QString lendDate = QString::number (LendBook::studentInfo->lendBooks[0]->borrowDate);
    QString days = QString::number( LendBook::studentInfo->lendBooks[0]->returnDay);
    QString type;
    if( LendBook::studentInfo->lendBooks[0]->bookType ==1){
        type = "自然科学";
    }else{
        type = "文学著作";
    }

    ui->lineEdit_9->setText(name);
    ui->lineEdit_3->setText(type);
    ui->lineEdit_4->setText(writr);
    ui->lineEdit_5->setText(num);
    ui->lineEdit_7->setText(lendDate);
    ui->lineEdit_8->setText(days);
}

void ReaderInfo::showSecondInfo(){
    QString name = QString::fromLocal8Bit( LendBook::studentInfo->lendBooks[1]->name);
    QString writr = QString::fromLocal8Bit( LendBook::studentInfo->lendBooks[1]->bookWriter);
    QString num = "1";
    QString lendDate = QString::number (LendBook::studentInfo->lendBooks[1]->borrowDate);
    QString days = QString::number( LendBook::studentInfo->lendBooks[1]->returnDay);
    QString type;
    if( LendBook::studentInfo->lendBooks[1]->bookType ==1){
        type = "自然科学";
    }else{
        type = "文学著作";
    }

    ui->lineEdit_12->setText(name);
    ui->lineEdit_17->setText(type);
    ui->lineEdit_20->setText(writr);
    ui->lineEdit_19->setText(num);
    ui->lineEdit_21->setText(lendDate);
    ui->lineEdit_18->setText(days);
}

void ReaderInfo::showThirdInfo(){
    QString name = QString::fromLocal8Bit( LendBook::studentInfo->lendBooks[2]->name);
    QString writr = QString::fromLocal8Bit( LendBook::studentInfo->lendBooks[2]->bookWriter);
    QString num = "1";
    QString lendDate = QString::number (LendBook::studentInfo->lendBooks[2]->borrowDate);
    QString days = QString::number( LendBook::studentInfo->lendBooks[2]->returnDay);
    QString type;
    if( LendBook::studentInfo->lendBooks[2]->bookType ==1){
        type = "自然科学";
    }else{
        type = "文学著作";
    }

    ui->lineEdit_16->setText(name);
    ui->lineEdit_10->setText(type);
    ui->lineEdit_13->setText(writr);
    ui->lineEdit_15->setText(num);
    ui->lineEdit_14->setText(lendDate);
    ui->lineEdit_11->setText(days);
}


void ReaderInfo::on_pushButton_3_released()
{

    int ID = ui->lineEdit_6->text().toInt();
    long phone = ui->lineEdit_2->text().toLong();

    QString name = ui->lineEdit_1->text();

    if(name == NULL){
        QMessageBox::information(this, "错误", "请输入姓名！");
    }else if(ID <=0 || phone<=0){
        QMessageBox::information(this, "错误", "请正确输入个人信息！");
    }else if(!isExistStudent(name,ID)){
        QMessageBox::information(this, "错误", "没有该读者信息！");
    }else if(LendBook::studentInfo->lendBooksNum == 0){
         QMessageBox::information(this, "错误", "没有该读者借书信息！");
    }else if(LendBook::studentInfo->lendBooksNum ==1){
        showFirstInfo();
    }else if(LendBook::studentInfo->lendBooksNum == 2){
        showFirstInfo();
        showSecondInfo();
    }else if(LendBook::studentInfo->lendBooksNum==3){
        showFirstInfo();
        showSecondInfo();
        showThirdInfo();
    }
}
