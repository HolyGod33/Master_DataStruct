#include <stdio.h>
#include "iostream"
#define MaxSize 50

typedef struct {
	int *data;//动态数组 
	int Maxsize;//最大长度 
	int length;//实际长度 
} Seqlist;//动态线性表

using namespace std;

//初始化动态线性表
void InitList(Seqlist &L){
    L.data = (int *)malloc(MaxSize*sizeof(int));//动态申请一片连续的空间
    L.length = 	0;//初始化当前的长度为0
    L.Maxsize = MaxSize;
}
void IncreaseCapacity(Seqlist &L,int len){
    int *p = L.data;
    L.data = (int *)malloc((MaxSize+len)*sizeof(int));
    int i;
    for(i = 0;i < L.length;i++){
        L.data[i] = p[i];
    }
    L.Maxsize += len;
    free(p);
}
//求
 int main(){
 	Seqlist L;
 	InitList(L);
 	IncreaseCapacity(L,20);
 }

 //线性表扩容表实际长度
 int length(Seqlist &L){
 	return L.length;
 } 
 //find element
 int LacateElem(Seqlist &L,int e){
 	for(int i = 0;i < L.length;i++){
 		if(L.data[i] == e){
 			return i;
		 }
	 }
	 return -1;
 }
 //find element by index
 int GetElem(Seqlist &L,int i){
 	if(i > L.length){
 		return -1;
	}
	return L.data[i];
 }
//插入
bool ListInsert(Seqlist &L, int i, int e) {
    if (i <1 || i>L.length) {
        return false;
    }
    if (L.length >= MaxSize) {
        return false;
    }
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length += 1;
    return true;
}
//删除
bool ListDelete(Seqlist &L, int index, int e) {
    if (L.length < index || index < 1) {
        return false;
    }
    for (int j = index; j <= L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    return true;
}
