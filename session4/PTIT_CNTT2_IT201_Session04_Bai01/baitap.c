#include<stdio.h>
#include<stdlib.h>

int linearSearch(int arr[], int n, int target){
    for(int i = 0; i < n; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
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
    printf("Nhập phần tử muốn tìm kiếm: ");
    scanf("%d", &target);
    int index = linearSearch(arr, n, target);
    index != -1 ? printf("%d", index) : printf("Không tìm thấy phần tử");
    free(arr);
    return 0;
}