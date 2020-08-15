//
// Created by cxy on 2020/8/15.
//

#include <cstdlib>

//队列的链式实现(带头结点)

typedef struct LinkNode{
    int data;
    struct LinkNode *next;//后驱指针
} LinkNode;//双向链表

typedef struct LinkQueue {
    LinkNode *top;
    LinkNode *rear;
};
//初始化
void InitQueue(LinkQueue &Q){
    Q.top = Q.rear = new LinkNode();
    Q.top->next = nullptr;
}

//元素入队
void EnQueue(LinkQueue &Q,int x){
    LinkNode *s = new LinkNode();
    s->data = x;
    s->next = nullptr;
    Q.rear->next = s;
    Q.rear = s;
}

//元素出队
bool DelQueue(LinkQueue &Q){
    //判空
    if (Q.rear == Q.top){
        return false;
    }
    LinkNode *p = Q.top;
    Q.top->next = p->next;
    //判断是不是最后一个元素出队
    if (Q.rear == p){
        Q.rear = Q.top;
    }
    free(p);
    return true;
}