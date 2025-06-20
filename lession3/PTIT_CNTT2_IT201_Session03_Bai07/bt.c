#include<stdio.h>
#include<stdlib.h>

void sumArr(int** arr, int rows, int cols){
    int k, sum = 0;
    printf("Nhập số hàng muốn tính tổng: ");
    scanf("%d", &k);
    if(k < 0 && k > rows){
        printf("Hàng cần tính không tồn tại");
        return;
    }
    for(int i = 0; i < cols; i++){
        sum += arr[k-1][i];
    }
    printf("sum = %d", sum);
}

int main(){
    int rows, cols;
    printf("Nhập số hàng (0 -> 1000): ");
    scanf("%d", &rows);
    if(0 < rows && rows < 1000){
        printf("Nhập số cột (0 -> 1000): ");
        scanf("%d", &cols);
        if(0 < cols && cols < 1000){
            int **arr = (int **)malloc(rows * sizeof(int));
            for(int i = 0; i < cols; i++){
                arr[i] = (int *)malloc(cols * sizeof(int));
            }
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    printf("Nhập phần tử arr[%d][%d]: ", i, j);
                    scanf("%d", &arr[i][j]);
                }
            }
            sumArr(arr, rows, cols);
        }
        else{
            printf("Số cột không hợp lệ");
        }
    }
    else{
        printf("Số hàng không hợp lệ");
    }
    return 0;
}