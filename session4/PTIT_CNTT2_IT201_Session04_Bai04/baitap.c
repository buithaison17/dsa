#include<stdio.h>
#include<stdlib.h>

int findIndex(int arr[], int n, int target){
    int index = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] == target) index = i;
    }
    return index;
}

int main(){
    int n, target;
    printf("Nhập số lượng phần tử: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        printf("Nhập phần tử arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Nhập phần tử cần tìm kiếm: ");
    scanf("%d", &target);
    int result = findIndex(arr, n, target);
    result != 1 ? printf("%d", result) : printf("Không tìm thấy phần tử");
    free(arr);
    return 0;
}