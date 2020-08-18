//
//栈的应用_括号匹配
//
#define MAXSIZE 50

typedef struct {
    char data[MAXSIZE];
    int top;//指向顶部的指针
}Stacklist;
using namespace std;

void initStack(Stacklist &sq){
    sq.top = -1;
}

bool isStackEmpty(Stacklist &sq){
    if (sq.top == -1){
        return false;
    }
    return true;
}

bool Push(Stacklist &sq, char x){
    if (sq.top == MAXSIZE - 1){
        return false;
    }
    sq.top += 1;
    sq.data[sq.top] = x;
    return true;
}

bool Pop(Stacklist &sq,char &x){
    if (sq.top == -1){
        return false;//栈空 弹出失败
    }
    x = sq.data[sq.top];
    sq.top--;
    return true;
}
//算法思想 左括号压栈 遇到右括号则先判断是否空栈,非空栈则弹出栈顶元素,若栈顶元素与当前匹配则成功,移向下一个
bool bracketCheck(char str[], int length){
    Stacklist sq;
    for (int i = 0; i < length; ++i) {
        if (str[i] == '{' || str[i] == '[' || str[i] == '(' || str[i] == '<'){
            Push(sq,str[i]); //如果是左符号 压栈
        } else{
            if (isStackEmpty(sq)){
                return false;//如果不是左符号则是右符号,但是当前栈是空的说明只有单一的右符号,则匹配失败
            }

            char x ;
            Pop(sq,x); // 出栈
            if (str[i] == '}' && x != '{'){
                return false;//刚弹出的元素与当前str中的括号不匹配
            }
            if (str[i] == ']' && x != '['){
                return false;
            }
            if (str[i] == ')' && x != '('){
                return false;
            }
        }
    }
    return isStackEmpty(sq);

}
