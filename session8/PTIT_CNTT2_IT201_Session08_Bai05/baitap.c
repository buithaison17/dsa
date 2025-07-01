#include<stdio.h>

void insertionSort(int arr[], int length){
    for(int i = 1; i < length; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// Độ phức tạp thời gian à O(n^2)

int main(){
    int n;
    printf("Nhập n: ");
    scanf("%d", &n);
    int arr[n];
    printf("Nhập các phần tử có trong mảng: ");
    for(int i = 0 ; i < n; i++){
        scanf("%d", &arr[i]);
    }
    insertionSort(arr, n);
    for(int i = 0 ; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}