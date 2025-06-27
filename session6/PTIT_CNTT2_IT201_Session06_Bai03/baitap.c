#include<stdio.h>

int total(int n){
    if(n < 10) return n;
    return n % 10 + total(n / 10);
}

int main(){
    int n;
    printf("Nhập n: ");
    scanf("%d", &n);
    int result = total(n);
    printf("%d", result);
    return 0;
}