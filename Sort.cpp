//
// Created by cxy on 2020/9/17.
//

void HeadAdjust(int pInt[], int i, int len);

void swap(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}


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
//增量排序 = 希尔排序
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

//快速排序
//1.选择基准,一般是选取表头元素
//2.将表中大于基准元素的放在右边,小于的放在左边
//3.递归的对左右子表进行重复过程
void QuickSort(int A[],int left, int right){
    int low = left;
    int temp;
    int high = right;
    if (low < high){//递归退出条件
        while(low != high){
            temp = A[low];

            while (low < high && A[high] >= temp){
                high --;
            }
            if (low<high){
                A[low] = A[high];
            }

            while (low < high && A[low] <= temp){
                low ++;
            }
            if (low<high){
                A[high] = A[low];
            }

        }
        A[high] = temp;
        QuickSort(A, left, high-1);
        QuickSort(A, high+1, right);
    }
}

//选择排序之选择排序
void SelectSort(int A[], int n){
    int min;
    for (int i = 0; i < n - 1; ++i) {
        min = i;
        for (int j = i; j < n - 1; ++j) {
            if (A[j] < A[min])
                min = j;
        }
        if (min != i){
            swap(A[min], A[i]);
        }
    }
}

void BuildMxHeap(int A[], int len){
    for (int i = len/2; i > 0; --i) {
        HeadAdjust(A,i, len);
    }
}

//堆排序
//使用堆的特性,选出最大的元素之后,与队尾的元素交换,交换后不满足条件堆的条件,便再进行一次堆的调整,如此循环后选出由小到大的有序数组
void HeapSort(int A[], int len){
    BuildMxHeap(A, len);
    for (int i = len ; i > 1; --i) {
        swap(A[1], A[i-1]);//交换,将顶部满足要求的元素放在最后
        BuildMxHeap(A, i);
    }
}

//队排序之大根堆的建立
void HeadAdjust(int A[], int k, int len) {
    A[0] = A[k];
    for (int i = 2*k;  i < len-1 ; i*=2) {
        if (i < len && A[i] < A[i+1]){
            i++;//找子节点中大的一个
        }
        if(A[0] >= A[i]) break; //注意这里对比的是A[0] 意义为如果最开始的A[0]放在k这个位置,是否满足大根堆
        else{
            A[k] = A[i];//不满足则让孩子节点中大的放在k这个位置
            k = i;//修改k值,因为在这层替换中有可能导致下面的子树不满足大根堆的要求,所以需要将k转到该次替换的节点(子树)进行检查,是否符合大根堆
        }
    }
    A[k] = A[0];//元素的下坠
}

