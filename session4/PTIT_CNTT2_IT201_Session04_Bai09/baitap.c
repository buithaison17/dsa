#include<stdio.h>
#include<stdlib.h>

int binarySearch(int arr[], int left, int right, int target){
    if(left >= right) return -1;
    int mid = (left + right) / 2;
    if(arr[mid] < target) return binarySearch(arr, mid+1, right, target);
    else if(arr[mid] > target) return binarySearch(arr, left, mid-1, target);
    else return mid;
}

void bubbleSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
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
    bubbleSort(arr, n);
    printf("Nhập phần tử muốn tìm kiếm: ");
    scanf("%d", &target);
    int index = binarySearch(arr, 0, n-1, target);
    index != -1 ? printf("Phần tử có trong mảng") : printf("Phần tử không có trong mảng");
    free(arr);
    return 0;
}