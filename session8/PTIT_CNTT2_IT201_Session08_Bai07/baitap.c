#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int left, int right){
    int pivot = arr[right];
    int i = left - 1;
    for(int j = left; j < right; j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[right]);
    return i + 1;
}

void quickSort(int arr[], int left, int right){
    if(left < right){
        int pi = partition(arr, left, right);
        quickSort(arr, left, pi - 1);
        quickSort(arr, pi + 1, right);
    }
}

// Độ phức tạp về thời gian của thuật toán là O(nlogn)
// Độ phức tạp về không gian của thuật toán là O(logn)

int main(){
    int n;
    printf("Nhập n: ");
    scanf("%d", &n);
    int arr[n];
    printf("Nhập các phần tử có trong mảng: ");
    for(int i = 0 ; i < n; i++){
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n - 1);
    for(int i = 0 ; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}