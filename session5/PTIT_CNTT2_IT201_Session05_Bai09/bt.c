#include<stdio.h>

int countPaths(int i, int j){
    if(i < 0 || j < 0) return 0;
    if(i == 0 && j == 0) return 1;
    return countPaths(i-1, j) + countPaths(i, j-1);
}

int main(){
    int rows, cols;
    printf("Nhập số hàng: ");
    scanf("%d", &rows);
    printf("Nhập số cột: ");
    scanf("%d", &cols);
    int result = countPaths(rows-1, cols-1);
    printf("Số đường đi: %d", result);
    return 0;
}