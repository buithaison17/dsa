#include<stdio.h>

int calculateSum(int n) {
    if(n == 0) return 0;
    return n + calculateSum(n-1);
}

int main(){
    int n;
    printf("Nhập n: ");
    scanf("%d", &n);
    if(n > 0){
        int sum = calculateSum(n);
        printf("%d", sum);
    }
    else{
        printf("Không hợp lệ");
    }
    return 0;
}