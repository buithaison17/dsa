#include<stdio.h>
#include<stdlib.h>

void sumDiagonalMain(int** arr, int row, int col){
    int sum = 0;
    int minDim = (row < col) ? row : col;

    for(int i = 0; i < minDim; i++){
        sum += arr[i][i];
    }
    printf("Tổng đường chéo chính: %d", sum);
}

void sumDiagonalSecondary(int** arr, int row, int col){
    int sum = 0;
    
    if(row != col){
        printf("\nKhông tồn tại đường chéo phụ");
        return;
    }
    for(int i = 0; i < row; i++){
        sum += arr[i][row-i-1];
    }
    printf("\nTổng đường chéo phụ: %d", sum);
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
            sumDiagonalMain(arr, row, col);
            sumDiagonalSecondary(arr, row, col);
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