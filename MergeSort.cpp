//
// Created by cxy on 2020/9/20.
//
//归并排序

#define N 10

int *B = new int[N];

void Merge(int A[], int low, int mid, int high){
    int i, j ,k;
    for (k = low; k < high; ++k) {
        B[k] = A[k];
    }

    for (i = low, j = mid + 1; i <= mid && j <= high; ++k) {
        if (B[i] <= B[j]){
            A[k] = B[i++];
        }
        else{
            A[k] = B[j++];
        }
    }while (i <= mid){
        A[k++] = B[i++];
    }
    while (j <= high){
        A[k++] = B[j++];
    }
}

void MergeSort(int A[], int low, int high){
    if (low < high){
        int mid = (low + high) / 2;
        MergeSort(A, low, mid);
        MergeSort(A, mid+1, high);
        Merge(A, low, mid, high);
    }
}
