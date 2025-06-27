#include<stdio.h>

int fibonacci(int n){
    if(n == 0) return 1;
    if(n == 1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    int n;
    printf("Nhập n: ");
    scanf("%d", &n);
    if(n > 0){
        int arr[n];
        for(int i = n; i > 0; i--){
            arr[i-1] = fibonacci(i-1);
            printf("%d ", fibonacci(i-1));
        }
    }
    return 0;
}