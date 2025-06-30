#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sorted(int* arr, int* toX, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(toX[j] > toX[j+1] || (toX[j] == toX[j+1] && arr[j] > arr[j+1])){
                // Đổi toX
                int temp = toX[j];
                toX[j] = toX[j+1];
                toX[j+1] = temp;

                // Đổi arr tương ứng
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int n, x, *arr, *toX;
    printf("Nhập n: ");
    scanf("%d", &n);
    printf("Nhập x: ");
    scanf("%d", &x);
    arr = (int *)malloc(n * sizeof(int));
    toX = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
        toX[i] = abs(arr[i] - x);
    }
    sorted(arr, toX, n);
    printArr(arr, n);
    free(arr);
    free(toX);
    return 0;
}