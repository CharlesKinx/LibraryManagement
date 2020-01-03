#include "stacktools.h"
#include"structs.h"
#include<stdlib.h>
#include"addnewbook.h"
StackTools::StackTools()
{

}

Students* StackTools::InitStudent(){
    Students* student = (Students*)malloc(sizeof(Students));
    student->name = NULL;
    student->phoneNum = 0;
    student->returnDay = 0;
    student->studentID = 0;
    student->borrowDate = 0;
    student->returnDate = 0;
    student->lendBooksNum = 0;
    return  student;
}

BookArray* StackTools::InitBooksArray(){
    BookArray* bookArray = (BookArray*)malloc(sizeof(BookArray));
    bookArray->ArtBooksNum=0;
    bookArray->SciBooksNum=0;
    return bookArray;
}

Books* StackTools::InitBook(){
    Books* book = (Books*)malloc(sizeof(Books));
    book->bookPrice = 0;
    book->bookPublisher=NULL;
    book->name =NULL;
    book->bookAllNum = 0;
    book->bookISBN = 0;
    book->bookType = 0;
    book->bookTime = 0;
    book->bookWriter = NULL;
    book->booksNum = 0;
    return book;
}


char* StackTools::charQStr(QString str){
    char *copy = (char *)malloc(sizeof (char) * str.size());
      int i;
      QByteArray ba = str.toLocal8Bit();

      for(i = 0; i < ba.size(); ++i){
          copy[i] = ba.at(i);
      }
      copy[i] = '\0';
      return copy;
}



int StackTools::isExistBooks(BookArray* bookArray,Books* book){
    //根据book->bookType的值（1 为自然科学 2 为文学著作）
    switch (book->bookType) {
        case 1:
        for(int i = 0;i<bookArray->SciBooksNum;i++){
            if(bookArray->SciBooks[i]->bookISBN == book->bookISBN){ //判断是否存在的依据是：在自然科学书籍数组中是否存在一样的图书ISBN
                return i;
            }
        }
        break;
        case 2:
        for(int i = 0;i<bookArray->ArtBooksNum;i++){
            if(bookArray->ArtBooks[i]->bookISBN == book->bookISBN){
                return i;
            }
        }
        break;
    }
    return -1;
}

void StackTools::addNewBooks(Books* book,int num){
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
    }
}

void StackTools::clearBook(BookArray* bookArray,int index,int bookType){
    if(bookType==1){
        free(bookArray->SciBooks[index]);
        for(int i = index;i<bookArray->SciBooksNum;i++){
            bookArray->SciBooks[index] = bookArray->SciBooks[index+1];
        }
        bookArray->SciBooksNum--;
    }else{
        free(bookArray->ArtBooks[index]);
        for(int i = index;i<bookArray->ArtBooksNum;i++){
            bookArray->ArtBooks[index] = bookArray->ArtBooks[index+1];
        }
        bookArray->ArtBooksNum--;
    }
}

bool StackTools::isRightData(long Date){
        int f=1;
        int ryear=0;
        if(Date>20501231||Date<20190101)
        {
            f=0;
            return false;
        }
        long day=Date%100;
        long month=(Date%10000-day)/100;
        long year=(Date-Date%10000)/10000;
        if(year<2019||year>2050||month<1||month>12||day<1||day>31) {
            f=0;
            return false;
        }
        if(year%4==0)
            ryear=1;
        if(month==02){
            if(ryear)
                if(day>29){f=0;return false;}

            if(day>28)
            {f=0;return false;}

        }else{
            if(month%2==1){
                if(day>31){f=0;return false;}
            }
             if(month%2==0){
                 if(day>30){f=0;return false;}
             }
        }
        return true;
}

bool StackTools::isOutData(Books* student){
        long day1 = student->borrowDate % 100;
        long month1 = (student->borrowDate % 10000 - day1) / 100;
        long year1 = (student->borrowDate - student->borrowDate % 10000) / 10000;
        long day2 = student->returnDate % 100;
        long month2 = (student->returnDate % 10000 - day2) / 100;
        long year2 = (student->returnDate - student->returnDate % 10000) / 10000;

        int sum = 0;

        if ((year2 - year1) == 0) {
            sum = JudgeMonthDay(year1, month1, month2, day1, day2);

        }
        if ((year2 - year1) == 1)
            sum = backday(year1, month1, day1) + frontday(year2, month2, day2);
        if ((year2 - year1) > 1) {
            sum = backday(year1, month1, day1) + frontday(year2, month2, day2);
            for (int i = year1 + 1; i <= year2 - 1; i++) {
                sum += isYear(i);
            }

        }

        if (sum > student->returnDay)
            return true;
        else
            return false;
}

int StackTools::isYear(int year){
    if ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0) {
        return 366;
    }
    else return 365;
}

int StackTools::frontday(int year, int month, int day){

    int num1[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
    int num2[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    int sum = 0;
        if (isYear(year) == 366) {
            for (int i = 0; i < month - 1; i++) {
                sum += num1[i];
            }
            return sum + day;
        }
        else {
            for (int i = 0; i < month - 1; i++) {
                sum += num2[i];
            }
            return sum + day;
        }
}

int StackTools::backday(int year, int month, int day) {                      //计算这年还剩多少天
    return isYear(year) - frontday(year, month, day);
}
int StackTools::JudgeMonthDay(int year, int month1, int month2, int day1, int day2) {
    int num1[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
    int num2[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int sum = 0;
    if ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0) {
        if (month1 == month2)
            return day2 - day1;
        if ((month2 - month1) == 1) {
            return (num1[month1 - 1] - day1 + day2);
        }
        if ((month2 - month1) > 1) {
            sum = num1[month1 - 1] - day1 + day2;
            for (int i = month1 + 1; i <= month2 - 1; i++) {
                sum += num1[i - 1];
            }
            return sum;
        }
    }
    else {
        if (month1 == month2)
            return day2 - day1;
        if ((month2 - month1) == 1) {
            return num2[month1 - 1] - day1 + day2;
        }
        if ((month2 - month1) > 1) {
            sum = num2[month1 - 1] - day1 + day2;
            for (int i = month1 + 1; i <= month2 - 1; i++) {
                sum += num2[i - 1];
            }
            return sum;
        }
    }
    return 0;
}












