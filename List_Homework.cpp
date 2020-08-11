//
// Created by cxy on 2020/8/11.
//
//王道顺序表课后习题

typedef struct {
    int *data;//动态数组
    int Maxsize;//最大长度
    int length;//实际长度
} Seqlist;//动态线性表

//Title: 将顺序表中的所有元素逆置
//算法思想: 将顺序表一分为二,前半部分的第1个与后半部分的最后一个对换,前半部分的第二个与后半部分的倒数第二个对换
void Reverse(Seqlist &L)
{
    int temp;
    for(int i = 0;i<L.length/2;i++){
        temp = L.data[i];
        L.data[i] = L.data[L.length - i - 1];
        L.data[L.length - i - 1] = temp;
    }
}

//Title: 删除顺序表中所有值为x的元素 要求时间复杂度为O(n)
//算法思想: 1. 不等于x的就放入新表  2. 记录不等于x的元素的个数k,并向前移动k个位置
//重点理解
void del(Seqlist &L, int x){
    int k = 0;
    for (int i = 0; i < L.length; ++i) {
        if (L.data[k]!= x){
            L.data[k] = L.data[i];
            k++;
        }
        L.length = k;
    }
}

//Title: 删除顺序表中s到t之间的元素 并校验s与t的合法性
//算法思想: 找到符合s到t中的一段元素 并让t后的一段元素替代s到t中的一段
bool del_s_t(Seqlist &L,int s,int t){
    if (s < 0 || t > L.length - 1|| s>t){
        return false;
    }
    int start = -1;//符合s到t的这一组的头下标
    int end = -1;//尾下标
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] >= s){
            start = i;
            break;
        }
    }
    if (start == -1){
        return false;
    }
    for (int i = start; i < L.length; ++i) {
        if (L.data[i] <= t){
            end = i;
            break;
        }
    }

    for (int i = end+1; i < L.length; ++i) {
        L.data[start] = L.data[i];
        start++;
    }
    L.length = start;
    return true;
}

//Title: 删除表中所有重复的元素 使得表中无重复元素
//算法思想: k计数,意义为顺序表中的不同值的元素的个数
//用新表装入新的顺序表,遍历顺序表 当前指向的值只要不等于上一个值就吧该值放入新的顺序表中并k++
bool Delete_same(Seqlist &L){
    if (L.length == 0){
        return false;
    }
    int * news = new int[L.Maxsize];
    int k = 0;
    int temp = -1;
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] != temp) {
            temp = L.data[i];
            news[k] = L.data[i];
            k++;
        }
    }
    L.data = news;
    return true;
}