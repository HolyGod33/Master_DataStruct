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

bool GetTop(Stacklist &sq, BiTNode &p){
    if (sq.top != -1){
        p = sq.data[sq.top];
        return true;
    }
    return false;
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
            visit(T);//如果是中序遍历则吧这个visit放在else里面
            Push(sq,*p);
            p = p->lChild;
        }else{
            Pop(sq,*p);//当前节点为空时,出栈,即获取父节点
            p = p->rChild;//父节点的右子节点
        }

    }
}

//后序遍历的非递归形式
//沿着根的左孩子,依次入栈(不是访问),直到左孩子为空,然后读取栈顶元素(不是出栈) 如果栈顶的右孩子存在且没有被访问过,则转向右孩子执行:一直访问左孩子
//若右孩子为空,则栈顶元素出栈并访问栈顶元素
void PostOrder2(BiTree T){
    Stacklist  sq;
    initStack(sq);
    BiTree p = T;
    BiTNode *r = nullptr; //指向最近访问过的节点
    while (p || sq.top != -1){
        if (p){
            Push(sq, *p);
            p = p->rChild;
        }
        else{
            GetTop(sq,*p);
            if (p->rChild && p->rChild != r){//如果栈顶元素的右孩子存在且未被访问过
                p = p->rChild;//就让栈顶元素的右孩子压栈
                Push(sq, *p);
                p = p->lChild;//并访问右孩子的左孩子(执行上一个的if)
            } else{
                Pop(sq,*p);
                visit(p);
                r = p;
                p = nullptr;//防止再次访问p的子树
            }
        }
    }

}



