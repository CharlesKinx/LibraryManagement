#ifndef STACKTOOLS_H
#define STACKTOOLS_H
#include"structs.h"
#include<QString>
class StackTools
{
public:
    StackTools();


public:

    BookArray* InitBooksArray();
    Books* InitBook();
    void addNewBooks(Books* book,int num);
    bool fullArray(BookArray* bookArray,int num);
    int selectBookType(Books* book);
    int isExistBooks(BookArray* bookArray,Books* book);
    void clearBook(BookArray* bookArray,int index,int bookType);
    bool isRightData(long Date);
    bool isOutData(Books* student);
    Students* InitStudent();
    int isYear(int year);
    int frontday(int year, int month, int day);
    int backday(int year, int month, int day);
    int JudgeMonthDay(int year, int month1, int month2, int day1, int day2);
    char* charQStr(QString str);
};

#endif // STACKTOOLS_H
