#ifndef SEARCHREADER_H
#define SEARCHREADER_H

#include    <QWidget>

namespace Ui {
class SearchReader;
}

class SearchReader : public QWidget
{
    Q_OBJECT

public:
    explicit SearchReader(QWidget *parent = nullptr);
    ~SearchReader();

private slots:

private:
    Ui::SearchReader *ui;
};

#endif // SEARCHREADER_H
