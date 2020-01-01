#include "searchbook.h"
#include "ui_searchbook.h"
#include"allmanage.h"
#include<QByteArray>
#include"addnewbook.h"
#include<QMessageBox>
#include"structs.h"


SearchBook::SearchBook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchBook)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());
}

SearchBook::~SearchBook()
{
    delete ui;
}


void SearchBook::on_pushButton_2_released()
{
    AllManage *all = new AllManage;
    this->close();
    all->show();
}


bool SearchBook::isSameName(QString str,char* name){

    StackTools *stacktools = new StackTools;
    char* string = (char*)malloc(sizeof(char));
    string = stacktools->charQStr(str);

    int i = 0;
    while(string[i] == name[i] && string[i] != '\0' && name[i] != '\0'){
        i++;
    }
    if(string[i] == '\0' && name[i]=='\0'){
        return true;
    }else{
        return false;
    }
}

bool SearchBook::isExistISBN(int type,int num,QString name){

    switch (type) {
        case 1:
            for(int i = 0;i<AddNewBook::bookArray->SciBooksNum;i++){
                if(num == AddNewBook::bookArray->SciBooks[i]->bookISBN&&isSameName(name,AddNewBook::bookArray->SciBooks[i]->name)){
                    AddNewBook::bookInfo = AddNewBook::bookArray->SciBooks[i];
                    AddNewBook::bookIndex = i;
                    return true;
                }
            }
        case 2:
            for(int i = 0;i<AddNewBook::bookArray->ArtBooksNum;i++){
                if(num == AddNewBook::bookArray->ArtBooks[i]->bookISBN&&isSameName(name,AddNewBook::bookArray->ArtBooks[i]->name)){
                     AddNewBook::bookInfo = AddNewBook::bookArray->ArtBooks[i];
                     AddNewBook::bookIndex = i;
                     return true;
                }
            }

    }
    return false;
}





