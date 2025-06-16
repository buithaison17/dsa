#include<stdio.h>

void printDouble(int n){
    int i = 1;
    while (i < n)
    {
        printf("%d\n", i);
        i *= 2;
    }
    
}

int main(){
    int n;
    printf("Nhập n: ");
    scanf("%d", &n);
    printDouble(n);
    return 0;
}

// Độ phức tạp thời gian O(log n);