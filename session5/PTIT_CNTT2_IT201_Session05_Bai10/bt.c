#include<stdio.h>

int countPaths(int i, int j, int blockRow, int blockCol){
    if(i < 0 || j < 0) return 0;
    if(i == blockRow && j == blockCol) return 0;
    if(i == 0 && j == 0) return 1;
    return countPaths(i-1, j, blockRow, blockCol) + countPaths(i, j-1, blockRow, blockCol);
}

int main(){
    int rows, cols, blockRow, blockCol;
    printf("Nhập số hàng: ");
    scanf("%d", &rows);
    printf("Nhập số cột: ");
    scanf("%d", &cols);
    printf("Nhập chỉ số hàng bị chặn: ");
    scanf("%d", &blockRow);
    printf("Nhập chỉ số cột bị chặn: ");
    scanf("%d", &blockCol);
    int result = countPaths(rows-1, cols-1, blockRow, blockCol);
    printf("Số đường đi: %d", result);
    return 0;
}