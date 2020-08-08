#include <iostra>
#define MaxSize 50

typedef struct {
	int *data;//动态数组 
	int Maxsize;//最大长度 
	int length;//实际长度 
} Seqlist;//动态线性表  
using namespace std;


 int main(){
 	Seqlist L;
 	InitList(L);
 	IncreaseCapacity(L,20);
 }
 //初始化动态线性表 
 void InitList(Seqlist &L){
	L.data = (int *)malloc(MaxSize*sizeof(int));//动态申请一片连续的空间
	L.length = 	0;//初始化当前的长度为0 
	L.Maxsize = MaxSize;
 }
 //线性表扩容 
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
 //求表实际长度
 int length(Seqlist &L){
 	return L.length;
 } 
 //find element
 int LacateElem(Seqlist &q,int e){
 	for(int i = 0;i < L.length;i++){
 		if(L.data[i] == e){
 			return i;
		 }
	 }
	 return -1;
 }
 //find element by index
 int GetElem(Seqlist &L,int i){
 	if(i > length){
 		return -1;
	}
	return L.data[i];
 }
