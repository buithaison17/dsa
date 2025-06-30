#include<stdio.h>

void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

void bubbleSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int n;
    printf("Nhập n: ");
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("before: ");
    printArr(arr, n);
    bubbleSort(arr, n);
    printf("\nafter: ");
    printArr(arr, n);
    return 0;
}