//
// 重点:用求余的方式实现循环队列.
//

#define MAXSIZE 50
//队列的顺序表实现
typedef struct QueueList{
    int data[MAXSIZE];
    int front, rear;
}SqQueue;

void InitQueue(SqQueue &Q){
    Q.front = Q.rear = 0;
}

//判空: 尾指针是否等于头指针

bool EnQueue(SqQueue &Q,int x){
    if (((Q.rear+1) % MAXSIZE) == Q.front){
        return false;
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear+1)%MAXSIZE;
    return true;
}

bool DeQueue(SqQueue &Q,int &x){
    if (Q.rear == Q.front){
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front+1) % MAXSIZE;
    return true;
}

//牺牲一个空间来是否满了
//还可以在SqQueue中加个size
bool isFull(SqQueue &Q){
    if ((Q.rear+MAXSIZE-Q.front) % MAXSIZE == MAXSIZE -1){
        return true;
    }
    return false;
}