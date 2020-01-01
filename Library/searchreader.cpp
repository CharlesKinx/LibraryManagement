#include "searchreader.h"
#include "ui_searchreader.h"
#include"allmanage.h"

SearchReader::SearchReader(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchReader)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());
}

SearchReader::~SearchReader()
{
    delete ui;
}
