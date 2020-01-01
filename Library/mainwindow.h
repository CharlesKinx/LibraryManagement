#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"addnewbook.h"
#include"lendbook.h"
#include"returnbook.h"
#include"allmanage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:

        void paintEvent(QPaintEvent*);

private slots:
        void on_addBooks_2_released();

        void on_pushButton_released();

        void on_clearBooks_2_released();

        void on_lendBooks_2_released();

        void on_returnBooks_2_released();

private:
    Ui::MainWindow *ui;

    AddNewBook addnewbook;
    LendBook lendbook;
    ReturnBook returnbook;
    AllManage allmanage;
};
#endif // MAINWINDOW_H
