//
// 二叉排序(搜索)树
//

#include "iostream"
typedef struct BSTNode{
    int data;
    struct BSTNode *lChild, *rChild;
}BSTNode, *BSTree;

using namespace std;

//二叉搜索树的搜索
BSTNode *BST_Search(BSTree T, int x){
    while (T != nullptr && T->data != x){ //当树为空或者节点值等于目标值 退出循环
        if (x<T->data){
            T = T->lChild;
        } else{
            T = T->rChild;
        }
    }
    return T;
}

//二叉排序树的插入
bool BST_Insert(BSTree &T, int x){
    if (T == nullptr) {
        T = new BSTNode();
        T->data = x;
        return true;
    }
    else if (x<T->data){
        BST_Insert(T->lChild, x);
    }
    else if (x>T->data){
        BST_Insert(T->rChild,x);
    }
    else if (x == T->data){
        return false;
    }
    return false;
}

//二叉排序树的构造
void BST_create(BSTree T, int arr[], int length){
    T = NULL;
    int i = 0;
    while (i < length){
        BST_Insert(T, arr[i]);
        i++;
    }
}

//二叉搜索树的删除
BSTree BST_Delete(BSTree T, int x){
    if (T == NULL){
        return false;
    }
    else if (x<T->data){//小于当前节点的值,则往左子树走
        T->lChild = BST_Delete(T->lChild,x);
        return T;
    }
    else if (x > T->data){//大于当前节点的值 则往右子树走
        T->rChild = BST_Delete(T->rChild,x);
        return T;
    }
    else {//等于当前节点的值
        if (T->rChild == NULL){//右子树为空,用左子树替代被删除的节点
            return T->lChild;
        }
        if (T->lChild == NULL){//左子树为空,用右子树替代被删除的节点
            return T->rChild;
        }
        else{
            //用右子树的最小节点(直接后继)替代当前删除的节点  则是右子树的中序遍历的第一个点
            //或者用左子树的最大节点(直接前驱)替代 则是左子树的中序遍历的最后一个点
        }
    }
}