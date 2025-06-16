#include<stdio.h>
#include<stdlib.h>

int* mallocArray(int n){
    int* arr = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        arr[i] = i;
    }
    return arr;
}

int main(){
    int n;
    printf("Nhập n: ");
    scanf("%d", &n);
    mallocArray(n);
    return 0;
}

// Độ phức tạp không gian O(n);