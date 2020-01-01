#ifndef STRUCTS_H
#define STRUCTS_H
#define MAXSIZE 1000
#define MAXLENDBOOKNUM 3
#define MAXLENDDAYS 30


typedef struct Books{
    char* name; //姓名
    int bookISBN; //序号
    char* bookWriter;   //作者
    char* bookPublisher;    //出版社
    int bookPrice;  //价格
    int bookType;  //书类 自然科学 = 1,文学著作 = 2
    int bookAllNum;    //数量
    int booksNum;   //库存
    int newAddNum;  //新增图书数量
    int bookTime;   //书最近一次借的时间
    long borrowDate=0;    //借书日期
    long returnDate=0; //还书日期
    int returnDay=0;  //借书时间

}book;

typedef struct Students{
    char* name; //姓名
    int studentID=0;    //借书证ID
    book* lendBooks[MAXLENDBOOKNUM];
    int lendBooksNum=0;
    long phoneNum=0;  //电话
    long borrowDate=0;    //借书日期
    long returnDate=0; //还书日期
    int returnDay=0;  //借书时间
}student;


struct BookArray{
   book* SciBooks[MAXSIZE];
   book* ArtBooks[MAXSIZE];
   int SciBooksNum=0;
   int ArtBooksNum=0;
} ;

struct StudentArray{
    student *studentarray[MAXSIZE];
    int studentNum = 0;
};

#endif // STRUCTS_H
