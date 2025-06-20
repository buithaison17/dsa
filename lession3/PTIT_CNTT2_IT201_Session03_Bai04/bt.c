#include<stdio.h>
#include<stdlib.h>

void findMaxCharacter(int** arr, int row, int col){
    int max = arr[0][0];
    for(int i = 1; i < row; i++){
        for(int j = 1; j < col; j++){
            if(max < arr[i][j]){
                max = arr[i][j];
            }
        }
    }
    printf("max: %d", max);
}

void findMinCharacter(int** arr, int row, int col){
    int min = arr[0][0];
    for(int i = 1; i < row; i++){
        for(int j = 1; j < col; j++){
            if(min > arr[i][j]){
                min = arr[i][j];
            }
        }
    }
    printf("\nmin: %d", min);
}

int main(){
    int row, col;
    printf("Nhập số hàng (0 -> 1000): ");
    scanf("%d", &row);
    if(0 < row && row < 1000){
        printf("Nhập số cột (0 -> 1000): ");
        scanf("%d", &col);
        if(0 < col && col < 1000){
            int **arr = (int **)malloc(row * sizeof(int));
            for(int i = 0; i < col; i++){
                arr[i] = (int *)malloc(col * sizeof(int));
            }
            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    printf("Nhập phần tử arr[%d][%d]: ", i, j);
                    scanf("%d", &arr[i][j]);
                }
            }
            findMaxCharacter(arr, row, col);
            findMinCharacter(arr, row, col);

            for(int i = 0; i < row; i++){
                free(arr[i]);
            }
            free(arr);
        }
        else if(0 <= col || col > 1000){
            printf("Số cột không hợp lệ");
        }
    }
    else if(0 <= row || row > 100){
        printf("Số hàng không hợp lệ");
    }
    return 0;
}