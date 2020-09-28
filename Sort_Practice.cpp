//
// Created by cxy on 2020/9/23.
//

//排序习题

//交换排序 (快排, 冒泡排序习题)
//---------------------------------

//No.1 双向冒泡排序算法,即正反两个方向进行扫,正方向获得最大元素,反方向获取最小元素
//思路: 设置左指针left 右指针right 初始指定为表头标尾,两个循环扫描,当左指针或者右指针
//相等退出,或者没有进行交换时退出
void BubbleSort_double(int A[], int n){
    int low = 0;
    int high = n-1;
    bool flag = true;
    while (low<high && flag){
        flag = false;
        for (int i = low; i < high; ++i) {
            if (A[i] > A[i + 1]){

            }
        }
    }
}