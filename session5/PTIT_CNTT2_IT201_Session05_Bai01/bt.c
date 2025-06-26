#include<stdio.h>

void printRecursion(int n) {
    if(n == 0) return;
    printRecursion(n-1);
    printf("%d ", n);
}

int main(){
    int n;
    printf("Nhập n: ");
    scanf("%d", &n);
    printRecursion(n);
    return 0;
}