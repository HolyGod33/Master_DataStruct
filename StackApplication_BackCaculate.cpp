//
// 后缀表达式计算
//

//算法思想:从左往右遍历,非操作符压栈,遇见操作符则弹出栈顶的两个元素,配合操作符进行计算,并将计算结果压栈
#define MAXSIZE 50

typedef struct {
    char data[MAXSIZE];
    int top;//指向顶部的指针
} Stacklist;

int caculate(char str[],int length){

}