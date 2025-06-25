#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, target, index = -1;
    printf("Nhập số lượng phần tử: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        printf("Nhập phần tử arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Nhập phần tử muốn tìm kiếm: ");
    scanf("%d", &target);
    for(int i = 0; i < n; i++){
        if(arr[i] == target){
            printf("%d ", i);
            index = i;
        }
    }
    if(index == -1) printf("Không tồn tại phần tử trong mảng");
    free(arr);
    return 0;
}