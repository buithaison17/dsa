#include<stdio.h>

int calculateFactorial(int n) {
    if(n == 1) return 1;
    return n * calculateFactorial(n-1);
}

int main(){
    int n;
    printf("Nhập n: ");
    scanf("%d", &n);
    if(n > 0){
        int factorial = calculateFactorial(n);
        printf("%d", factorial);
    }
    else{
        printf("Không hợp lệ");
    }
    return 0;
}