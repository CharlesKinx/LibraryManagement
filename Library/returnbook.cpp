#include "returnbook.h"
#include "ui_returnbook.h"
#include"mainwindow.h"
#include<QPainter>
#include<QByteArray>
#include<QMessageBox>
#include"lendbook.h"

ReturnBook::ReturnBook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReturnBook)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());
}

ReturnBook::~ReturnBook()
{
    delete ui;
}

void ReturnBook::paintEvent(QPaintEvent *){

    QPainter add(this);
    add.drawPixmap(0,0,width(),height(),QPixmap("../Image/bk3.jpg"));
    add.end();
}
void ReturnBook::on_pushButton_2_released()
{
    MainWindow *mainwin = new MainWindow;
    this->close();
    mainwin->show();
}

bool ReturnBook::isExistStudent(Students* student){
    AddNewBook *add = new AddNewBook;
    for(int i =0;i<LendBook::studentArray->studentNum;i++){
        if(student->studentID == LendBook::studentArray->studentarray[i]->studentID&&add->isSameName(student->name, LendBook::studentArray->studentarray[i]->name)){
            index = i;
            return true;
        }
    }
    return false;
}


bool ReturnBook::isExistBook(Books* book,Students* student){
    if(isExistStudent(student)){
        for(int i = 0;i<LendBook::studentArray->studentarray[index]->lendBooksNum;i++){
            if(book->bookISBN == LendBook::studentArray->studentarray[index]->lendBooks[i]->bookISBN){
                bookIndex = i;
                return true;
            }
        }
    }
            return false;
}

void ReturnBook::AddReturnBook(Books* book){

    AddNewBook *addNew = new AddNewBook;
    switch (book->bookType) {
        case 1:
            for(int i =0;i< AddNewBook::bookArray->SciBooksNum;i++){
                if(AddNewBook::bookArray->SciBooks[i]->bookISBN == book->bookISBN && addNew->isSameName(AddNewBook::bookArray->SciBooks[i]->name,book->name),addNew->isSameName(AddNewBook::bookArray->SciBooks[i]->bookWriter,book->bookWriter)){
                    AddNewBook::bookArray->SciBooks[i]->booksNum++;
                }
            }
        break;
        case 2:
             for(int i =0;i< AddNewBook::bookArray->ArtBooksNum;i++){
                 if(AddNewBook::bookArray->ArtBooks[i]->bookISBN == book->bookISBN && addNew->isSameName(AddNewBook::bookArray->ArtBooks[i]->name,book->name),addNew->isSameName(AddNewBook::bookArray->ArtBooks[i]->bookWriter,book->bookWriter)){
                        AddNewBook::bookArray->ArtBooks[i]->booksNum++;
                }
            }
        break;
    }
}

void ReturnBook::returnBook(){
    free(LendBook::studentArray->studentarray[index]->lendBooks[bookIndex]);
    for(int i =bookIndex;i<LendBook::studentArray->studentarray[index]->lendBooksNum;i++){
        LendBook::studentArray->studentarray[index]->lendBooks[i] = LendBook::studentArray->studentarray[index]->lendBooks[i+1];
    }
     LendBook::studentArray->studentarray[index]->lendBooksNum--;
}


void ReturnBook::on_pushButton_released()
{

    StackTools *stack = new StackTools;

    student = stack->InitStudent();
    book = stack->InitBook();

    student->studentID = ui->lineEdit_2->text().toInt();
    book->bookType = ui->lineEdit_5->text().toInt();
    student->returnDate = ui->lineEdit_6->text().toLong();
    book->bookISBN = ui->lineEdit_7->text().toInt();

    student->name = stack->charQStr(ui->lineEdit->text());
    book->name = stack->charQStr(ui->lineEdit_3->text());
    book->bookWriter =  stack->charQStr(ui->lineEdit_4->text());


    if(student->name ==NULL){
        QMessageBox::information(this, "错误", "请正确学生信息！");
    }else if(student->studentID < 0 || student->studentID == 0){
         QMessageBox::information(this, "错误", "请正确输入借书证ID！");
    }else if(book->name == NULL || book->bookWriter == NULL){
        QMessageBox::information(this, "错误", "请正确输入书籍信息！");
    }else if(book->bookType !=1 &&book->bookType !=2){
        QMessageBox::information(this, "错误", "请正确输入书籍类型代号！");
    }else if(!stack->isRightData(student->returnDate)){
        QMessageBox::information(this, "错误", "请正确输入还书日期！");
    }else if(!isExistStudent(student)){
        QMessageBox::information(this, "错误", "无该同学借书信息！");
    }else if(!isExistBook(book,student)){
        QMessageBox::information(this, "错误", "该同学未借阅此书！");
    }else {
        if(stack->isOutData(LendBook::studentArray->studentarray[index])){
            QMessageBox::information(this, "注意", "该同学已逾期借阅此书！");
            QMessageBox::information(this, "正确", "成功还书！");
            AddReturnBook(book);
            returnBook();
        }else{
            QMessageBox::information(this, "正确", "成功还书！");
            AddReturnBook(book);
            returnBook();
        }
    }
}


