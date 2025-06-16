#include<stdio.h>

int calcSum1(int n){
    int sum = 0;
    for(int  i = 1; i <= n; i++){
        sum += i;
    }
    return sum;
}

// Độ phức tạp của các này là O(n);

int calcSum2(int n){
    return n * (n + 1) / 2;
}

// Độ phức tạp của các này là O(1);

int main(){
    int n;
    int sum = 0;
    printf("Nhập n: ");
    scanf("%d", &n);
    sum = calcSum1(n);
    printf("Cách 1: %d\n", sum);
    sum = calcSum2(n);
    printf("Cách 2: %d", sum);
    return 0;
}