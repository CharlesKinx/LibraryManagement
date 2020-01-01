#ifndef READERINFO_H
#define READERINFO_H

#include <QWidget>
#include"structs.h"
namespace Ui {
class ReaderInfo;
}

class ReaderInfo : public QWidget
{
    Q_OBJECT

protected:

      void paintEvent(QPaintEvent*);

public:
    explicit ReaderInfo(QWidget *parent = nullptr);
    ~ReaderInfo();
    bool isExistStudent(QString name,int ID);
    static Students* studentInfo;
private slots:
      void on_pushButton_2_released();
      void showFirstInfo();
      void showSecondInfo();
      void showThirdInfo();
      void on_pushButton_3_released();

private:
    Ui::ReaderInfo *ui;
};

#endif // READERINFO_H
