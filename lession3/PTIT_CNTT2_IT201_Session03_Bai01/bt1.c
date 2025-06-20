#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("Nhập số lượng phần tử: ");
    scanf("%d", &n);
    if(n < 0){
        printf("Số lượng phần tử không được âm");
    }
    else if(n == 0){
        printf("Số lượng phần tử phải lớn hơn 0");
    }
    else if(0 < n && n < 100){
        int *arr = (int*)malloc(n * sizeof(int));
        for(int i = 0; i < n; i++){
            printf("Nhập phần tử arr[%d]: ", i);
            scanf("%d", &arr[i]);
        }
        for(int i = 0; i < n; i++){
            printf("Phần tử thứ %d: %d\n", i+1, arr[i]);
        }
        free(arr);
    }
    return 0;
}