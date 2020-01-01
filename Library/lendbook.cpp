#include "lendbook.h"
#include "ui_lendbook.h"
#include"mainwindow.h"
#include"QMessageBox"
#include<QPainter>

LendBook::LendBook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LendBook)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());
}

LendBook::~LendBook()
{
    delete ui;
}

void LendBook::paintEvent(QPaintEvent *){

    QPainter add(this);
    add.drawPixmap(0,0,width(),height(),QPixmap("../Image/bk3.jpg"));
    add.end();
}
void LendBook::on_pushButton_2_released()
{
    MainWindow *mainwin = new MainWindow;
    this->close();
    mainwin->show();
}

//查找该学生是否存在，若存在并记录该学生的索引
bool LendBook::isExistStudent(Students* student){
    AddNewBook *add = new AddNewBook;
    for(int i =0;i<LendBook::studentArray->studentNum;i++){
        if(student->studentID == LendBook::studentArray->studentarray[i]->studentID&&add->isSameName(student->name, LendBook::studentArray->studentarray[i]->name)){
            index = i;
            return true;
        }
    }
    return false;
}


void LendBook::addNewStudents(Students* student,Books* books){
    if(isExistStudent(student)){
        LendBook::studentArray->studentarray[index]->lendBooks[student->lendBooksNum] = (Books*)malloc(sizeof(Books));
        LendBook::studentArray->studentarray[index]->lendBooks[student->lendBooksNum]->name = (char *)malloc(sizeof (char));
        LendBook::studentArray->studentarray[index]->lendBooks[student->lendBooksNum]->name = books->name;
        LendBook::studentArray->studentarray[index]->lendBooks[student->lendBooksNum]->bookWriter = (char *)malloc(sizeof (char));
        LendBook::studentArray->studentarray[index]->lendBooks[student->lendBooksNum]->bookWriter = books->bookWriter;
        LendBook::studentArray->studentarray[index]->lendBooks[student->lendBooksNum] = books;
        LendBook::studentArray->studentarray[index]->lendBooksNum++;
    }else{
        LendBook::studentArray->studentarray[LendBook::studentArray->studentNum] = student;
        LendBook::studentArray->studentarray[index]->lendBooks[student->lendBooksNum] = (Books*)malloc(sizeof(Books));
        LendBook::studentArray->studentarray[index]->lendBooks[student->lendBooksNum]->name = (char *)malloc(sizeof (char));
        LendBook::studentArray->studentarray[index]->lendBooks[student->lendBooksNum]->name = books->name;
        LendBook::studentArray->studentarray[index]->lendBooks[student->lendBooksNum]->bookWriter = (char *)malloc(sizeof (char));
        LendBook::studentArray->studentarray[index]->lendBooks[student->lendBooksNum]->bookWriter = books->bookWriter;
        LendBook::studentArray->studentarray[LendBook::studentArray->studentNum]->lendBooks[student->lendBooksNum] = books;
        LendBook::studentArray->studentarray[LendBook::studentArray->studentNum]->lendBooksNum++;
        LendBook::studentArray->studentNum++;
    }
}
//判断该书是否存在
bool LendBook::isExistBook(Books* book){
    AddNewBook *addNew = new AddNewBook;
    switch (book->bookType) {
        case 1:
            for(int i =0;i< AddNewBook::bookArray->SciBooksNum;i++){
                if(AddNewBook::bookArray->SciBooks[i]->bookISBN == book->bookISBN && addNew->isSameName(AddNewBook::bookArray->SciBooks[i]->name,book->name)&&addNew->isSameName(AddNewBook::bookArray->SciBooks[i]->bookWriter,book->bookWriter)){
                    if( AddNewBook::bookArray->SciBooks[i]->booksNum ==0){
                        noBook = true;
                    }else{
                        noBook = false;
                        AddNewBook::bookArray->SciBooks[i]->booksNum--;
                        AddNewBook::bookArray->SciBooks[i]->bookTime++;
                    }
                    book = AddNewBook::bookArray->SciBooks[i];
                    return true;
                }
            }
        break;
        case 2:
             for(int i =0;i< AddNewBook::bookArray->ArtBooksNum;i++){
                    if(AddNewBook::bookArray->ArtBooks[i]->bookISBN == book->bookISBN && addNew->isSameName(AddNewBook::bookArray->ArtBooks[i]->name,book->name)&&addNew->isSameName(AddNewBook::bookArray->ArtBooks[i]->bookWriter,book->bookWriter)){
                        if( AddNewBook::bookArray->ArtBooks[i]->booksNum ==0){
                            noBook = true;
                        }else{
                            noBook = false;
                            AddNewBook::bookArray->ArtBooks[i]->booksNum--;
                            AddNewBook::bookArray->ArtBooks[i]->bookTime++;
                        }
                        book = AddNewBook::bookArray->ArtBooks[i];
                        return true;
                    }
                }
    }
    return false;
}

void LendBook::on_pushButton_released()
{
    StackTools *stackTools = new StackTools;

    student = stackTools->InitStudent();
    book = stackTools->InitBook();

    student->studentID = ui->lineEdit_2->text().toLong();
    student->phoneNum = ui->lineEdit_3->text().toLong();
    book->bookType = ui->lineEdit_5->text().toInt();
    book->bookISBN = ui->lineEdit_9->text().toInt();
    book->borrowDate = ui->lineEdit_6->text().toLong();
    book->returnDay = ui->lineEdit_8->text().toLong();

    student->name = stackTools->charQStr(ui->lineEdit_1->text());
    book->bookWriter = stackTools->charQStr(ui->lineEdit_7->text());
    book->name =stackTools->charQStr(ui->lineEdit_4->text());

    if(student->name ==NULL){
        QMessageBox::information(this, "错误", "请正确输入读者信息！");
    }else if(student->studentID == 0||student->studentID<0){
        QMessageBox::information(this, "错误", "请正确输入借书证ID！");
    }else if(student->phoneNum == 0||student->phoneNum<0){
        QMessageBox::information(this, "错误", "请正确输入联系方式！");
    }else if(book->name == NULL){
        QMessageBox::information(this, "错误", "请正确输入借书信息！");
    }else if(book->bookType !=1 &&book->bookType!=2){
        QMessageBox::information(this, "错误", "请正确输入借书类别代号！");
    }else if(!stackTools->isRightData(book->borrowDate)){
        QMessageBox::information(this, "错误", "请正确输入借阅时间！");
    }else if(book->returnDay >=30||book->returnDay<=0){
        QMessageBox::information(this, "错误", "请正确输入借阅天数！");
    }else if(student->lendBooksNum >3){
         QMessageBox::information(this, "借阅失败", "该读者借阅书籍量已是最大借书量！");
    }else if(!isExistBook(book)){
        QMessageBox::information(this, "借阅失败", "无该图书信息！");
    }else{
        QMessageBox::information(this, "正确", "借阅成功！");
        addNewStudents(student,book);
        MainWindow *mainwin = new MainWindow;
        this->close();
        mainwin->show();
    }
}















