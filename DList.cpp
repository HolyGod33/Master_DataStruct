//
// Created by cxy on 2020/8/9.
//
#include<iostream>
typedef struct DNode{
    int data;
    struct DNode *prior,*next;//前驱指针 后驱指针
} DNode, *DLinklist;//双向链表

using namespace std;

//初始化双链表
bool InitDLinkList(DLinklist &L){
    L = new DNode;
    if(L==NULL){
        cout << "初始化失败";
        return false;
    }
    L->prior = NULL;
    L->next = NULL;
    return true;
}

int main(){
    DLinklist L;
    InitDLinkList(L);
}
//在p节点后插入s节点
bool InsertNextDNode(DNode *p, DNode *s){
    if(p == NULL||s == NULL){
        return false;
    }
    s->next = p->next;
    if(p->next != NULL){
        p->next->prior = s;
    }
    p->next = s;
    s->prior = p;
}
//删除p的后继节点
bool DeleteNextDNode(DNode *p){
    if (p == NULL) return false;
    DNode *q = p->next;
    if (q == NULL) return false;
    p->next = q->next;
    if(q->next != NULL)
        q->next->prior = p;
    free(q);
    return true;
}
void DestoryList(DLinklist &L){
    while (L->next!=NULL){
        DeleteNextDNode(p);
    }
    free(L);
    L = NULL;
}

