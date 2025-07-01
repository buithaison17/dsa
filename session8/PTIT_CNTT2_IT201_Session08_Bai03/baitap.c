#include<stdio.h>

void bubbleSort(int arr[], int length){
    for(int i = 0; i < length - 1; i++){
        for(int j = 0; j < length - i - 1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
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
    bubbleSort(arr, n);
    for(int i = 0 ; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}