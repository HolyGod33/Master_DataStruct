//
// 二叉树的遍历(先中后序) 递归
//
#include "iostream"
#define MAXSIZE 50

using namespace std;

typedef struct BiTNode{
    const char *data;
    struct BiTNode *lChild, *rChild;
}BiTNode, *BiTree;

typedef struct {
    BiTNode data[MAXSIZE];
    int top;//指向顶部的指针
}Stacklist;

using namespace std;

void initStack(Stacklist &sq){
    sq.top = -1;
}
void visit(BiTNode *T){
    printf("%s", T->data);
}

bool Push(Stacklist &sq, BiTNode x){
    if (sq.top == MAXSIZE - 1){
        return false;
    }
    sq.top += 1;
    sq.data[sq.top] = x;
    return true;
}
bool Pop(Stacklist &sq,BiTNode &x){
    if (sq.top == -1){
        return false;//栈空 弹出失败
    }
    x = sq.data[sq.top];
    sq.top--;
    return true;
}

//先序遍历
void PreOrder(BiTree T){
    if (T != NULL){
        visit(T);
        PreOrder(T->lChild);
        PreOrder(T->rChild);
    }
}

//中序遍历
void InOrder(BiTree T){
    if (T != NULL){
        PreOrder(T->lChild);
        visit(T);
        PreOrder(T->rChild);
    }
}

//后续遍历
void PostOrder(BiTree T){
    if (T != NULL){
        PreOrder(T->lChild);
        PreOrder(T->rChild);
        visit(T);
    }
}

//先序遍历的非递归形式(中序遍历只是换visit的位置 此处不重写)
void PreOrder2(BiTree T){
    Stacklist sq;
    initStack(sq);
    BiTree p = T;
    while (p || sq.top != -1){//当p为空或者栈为空时退出遍历
        if (p){
            visit(T);
            Push(sq,*p);
            p = p->lChild;
        }else{
            Pop(sq,*p);//当前节点为空时,出栈,即获取父节点
            p = p->rChild;//父节点的右子节点
        }

    }
}

//后序遍历的非递归形式

void PostOrder2(BiTree T){

}



