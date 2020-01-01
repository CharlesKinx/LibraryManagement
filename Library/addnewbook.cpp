#include "addnewbook.h"
#include "ui_addnewbook.h"
#include"mainwindow.h"
#include<QMessageBox>
#include<QByteArray>
#include"stacktools.h"
#include"structs.h"
#include<QPainter>
#include <QTextCodec>



AddNewBook::AddNewBook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddNewBook)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());
}

AddNewBook::~AddNewBook()
{
    delete ui;
}


void AddNewBook::paintEvent(QPaintEvent *){

    QPainter add(this);
    add.drawPixmap(0,0,width(),height(),QPixmap("../Image/bk3.jpg"));
    add.end();
}

void AddNewBook::on_pushButton_2_released()
{
    MainWindow *mainw = new MainWindow;
    this->close();
    mainw->show();
}



bool AddNewBook::isSameName(char* newName,char* bookName){
    int i = 0;

    while(newName[i] == bookName[i] && newName[i] != '\0' && bookName[i] != '\0'){
        i++;
    }

    if(newName[i] == '\0' && bookName[i]=='\0'){
        return true;
    }else{
        return false;
    }
}
int AddNewBook::isExistBooks(BookArray* bookArray,Books* book){
    switch (book->bookType) {
        case 1:
        for(int i = 0;i<bookArray->SciBooksNum;i++){
            if(bookArray->SciBooks[i]->bookISBN == book->bookISBN&&isSameName(bookArray->SciBooks[i]->name,book->name)&&isSameName(bookArray->SciBooks[i]->bookWriter,book->bookWriter)){
                return i;
            }
        }
        break;
        case 2:
        for(int i = 0;i<bookArray->ArtBooksNum;i++){
            if(bookArray->ArtBooks[i]->bookISBN == book->bookISBN&&isSameName(bookArray->ArtBooks[i]->name,book->name)&&isSameName(bookArray->ArtBooks[i]->bookWriter,book->bookWriter)){
                return i;
            }
        }
        break;
    default:
        break;
    }
    return -1;
}


void AddNewBook::addNewBook(Books* book,int num){
    switch (book->bookType) {
        case 1:
            if(isExistBooks(AddNewBook::bookArray,book) == -1){
                AddNewBook::bookArray->SciBooks[AddNewBook::bookArray->SciBooksNum] = book;
                AddNewBook::bookArray->SciBooks[AddNewBook::bookArray->SciBooksNum]->bookAllNum+=num;
                AddNewBook::bookArray->SciBooks[AddNewBook::bookArray->SciBooksNum]->booksNum += num;
                AddNewBook::bookArray->SciBooksNum++;
            }else{
                AddNewBook::bookArray->SciBooks[isExistBooks(AddNewBook::bookArray,book)]->bookAllNum += num;
                AddNewBook::bookArray->SciBooks[isExistBooks(AddNewBook::bookArray,book)]->booksNum += num;
            }
        break;
        case 2:
           if(isExistBooks(AddNewBook::bookArray,book) == -1){
                AddNewBook::bookArray->ArtBooks[AddNewBook::bookArray->ArtBooksNum] = book;
                AddNewBook::bookArray->ArtBooks[AddNewBook::bookArray->ArtBooksNum]->bookAllNum+=num;
                AddNewBook::bookArray->ArtBooks[AddNewBook::bookArray->ArtBooksNum]->booksNum += num;
                AddNewBook::bookArray->ArtBooksNum++;
            }else{
               AddNewBook::bookArray->ArtBooks[isExistBooks(AddNewBook::bookArray,book)]->bookAllNum += num;
               AddNewBook::bookArray->ArtBooks[isExistBooks(AddNewBook::bookArray,book)]->booksNum+=num;
            }
        break;
    default:
        break;
    }
}


void AddNewBook::on_pushButton_released()
{

  book = stacktools->InitBook();

  book->name = stacktools->charQStr(ui->lineEdit->text());
  book->bookWriter = stacktools->charQStr(ui->lineEdit_2->text());
  book->bookPublisher = stacktools->charQStr(ui->lineEdit_7->text());

  book->bookPrice = ui->lineEdit_6->text().toInt();
  book->bookISBN = ui->lineEdit_5->text().toInt();
  book->newAddNum = ui->lineEdit_3->text().toInt();
  book->bookType = ui->lineEdit_4->text().toInt();


  if(book->name == NULL ||book->bookWriter==NULL){
      QMessageBox::information(this, "错误", "请输入正确书籍信息！");
  }else  if((book->bookType!=1) && (book->bookType!=2)){
      QMessageBox::information(this, "错误", "请输入正确书籍信息！");
  }else if(book->newAddNum == 0|| book->bookISBN == 0){
         QMessageBox::information(this, "错误", "请输入正确书籍信息！");
  }else if(book->bookPrice<=0){
       QMessageBox::information(this, "错误", "请输入正确书籍信息！");
  }else{
      QMessageBox::information(this, "正确", "入库成功");
      addNewBook(book,book->newAddNum);
      MainWindow *mainw = new MainWindow;
      this->close();
      mainw->show();

  }
}


