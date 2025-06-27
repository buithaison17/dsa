#include<stdio.h>
#include<stdlib.h>

int countWays(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    return countWays(n- 1) + countWays(n - 2);
}

int main(){
    int n;
    printf("Nhập số bậc: ");
    scanf("%d", &n);
    int result = countWays(n);
    printf("%d", result);
    return 0;
}