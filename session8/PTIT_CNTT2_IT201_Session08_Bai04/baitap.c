#include<stdio.h>

void selectionSort(int arr[], int length){
    for(int i = 0; i < length - 1; i++){
        int minIndex = i;
        for(int j = i; j < length; j++){
            if(arr[minIndex] > arr[j]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
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
    selectionSort(arr, n);
    for(int i = 0 ; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}