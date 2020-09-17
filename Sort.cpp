//
// Created by cxy on 2020/9/17.
//

//从后往前两两比较,若为逆序则交换他们  冒泡排序
void BubbleSort(int A[], int n){
    for (int i = 0; i < n - 1; ++i) {
        bool flag = false;
        for (int j = n-1; j > i; --j) {//每一趟排序都可以使一个元素移动到最终位置,则该元素就不需要再进入对比
            if (A[j-1]>A[j]){
                int temp = A[j-1];
                A[j-1] = A[j];
                A[j] = temp;
                flag = true;
            }
            if (flag = false){//如果某一趟排序过程中未发生交换(即有序)则算法提前结束
                return;
            }
        }
    }
}

//希尔排序 先将排序表分割成若干个特殊子表
//对各个字表分别进行插入排序
//缩小增量d,直到d = 1为止
void shellSort(int A[], int n){
    int d, i, j;
    //A[0]只是暂存
    for (d = n/2; d>=1; d/=2) {
        for (int i = d+1; i <=n; ++i) {
            if (A[i]< A[i-d]){
                A[0] = A[i];
                for (int j = i-d; j >0 && A[0] < A[j]; j-=d) {//插入排序 如果当前元素i比该次指针j小,就放在j的后面,j就往前顶
                    A[j+d] = A[j];//向前移动
                }
                A[j+d] = A[0];//为什么是j+d:因为当上面的循环退出时,已经执行了j-=d,因为当前j的指向不符合条件,前一个已经移动完成,于是便插入j前面一个
            }
        }
    }
}