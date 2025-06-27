#include<stdio.h>

int convertToBinary(int n){
    if(n == 0) return 0;
    return convertToBinary(n / 2) * 10 + (n % 2);
}

int main(){
    int n;
    printf("Nhập n: ");
    scanf("%d", &n);
    int result = convertToBinary(n);
    printf("%d", result);
    return 0;
}