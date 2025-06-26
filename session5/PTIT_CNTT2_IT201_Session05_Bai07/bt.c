#include<stdio.h>
#include<stdlib.h>

int fibonacci(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    int n;
    printf("Nhập n: ");
    scanf("%d", &n);
    if(n > 0){
        printf("Dãy Fibonacci từ 0 đến %d là:\n", n);
        for(int i = 0; i < n; i++){
            printf("%d ", fibonacci(i));
        }
    }
    return 0;
}