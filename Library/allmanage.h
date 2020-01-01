#ifndef ALLMANAGE_H
#define ALLMANAGE_H

#include <QWidget>
#include"searchbook.h"
#include"searchreader.h"

namespace Ui {
class AllManage;
}

class AllManage : public QWidget
{
    Q_OBJECT

public:
    explicit AllManage(QWidget *parent = nullptr);
    ~AllManage();
protected:

      void paintEvent(QPaintEvent*);

private slots:
    void on_pushButton_2_released();

    void on_pushButton_released();

    void on_pushButton_3_released();

private:
    Ui::AllManage *ui;
};

#endif // ALLMANAGE_H
