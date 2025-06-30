#include<stdio.h>
#include<stdlib.h>

void printArr(int** arr, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void sortColumn(int** arr, int rows, int k){
    for(int i = 0; i < rows - 1; i++){
        for(int j = 0; j < rows - i - 1; j++){
            if(arr[j][k] > arr[j + 1][k]){
                int temp = arr[j][k];
                arr[j][k] = arr[j + 1][k];
                arr[j + 1][k] = temp;
            }
        }
    }
}

int main(){
    int rows, cols, **arr, k;
    printf("Nhập số hàng: ");
    scanf("%d", &rows);
    printf("Nhập số cột: ");
    scanf("%d", & cols);
    arr = (int **)malloc(rows * sizeof(int *));
    for(int i = 0; i < rows; i++){
        arr[i] = (int *)malloc(cols * sizeof(int));
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("arr[%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Nhập k: ");
    scanf("%d", &k);
    sortColumn(arr, rows, k - 1);
    printArr(arr, rows, cols);
    for(int i = 0; i < rows; i++){
        free(arr[i]);
    }
    free(arr);
    return 0;
}