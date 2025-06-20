#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, m, value;
    printf("Nhập n phần tử: ");
    scanf("%d", &n);
    if(n > 0){
        int *arr = (int*)malloc(n * sizeof(int));
        for(int i = 0; i < n; i++){
            printf("Nhập phân tử arr[%d]: ", i);
            scanf("%d", &arr[i]);
        }
        printf("Nhập số phần tử muốn thêm: ");
        scanf("%d", &m);
        n += m;
        arr = (int *)realloc(arr, n * sizeof(int));
        for(int i = n - m; i < n; i++){
            printf("Nhập phần tử: ");
            scanf("%d", &arr[i]);
        }
        for(int i = 0; i < n; i++){
            printf("%d ", arr[i]);
        }
    }
    else{
        printf("Số lượng phần tử không hợp lệ");
    }
    return 0;
}