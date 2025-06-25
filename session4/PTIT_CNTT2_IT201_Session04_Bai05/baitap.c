#include<stdio.h>
#include<stdlib.h>

int binarySearch(int arr[], int n, int target){
    int left = 0, right = n - 1;
    while (left >= right){
        int mid = (left + right) / 2;
        if(arr[mid] < target) left = mid + 1;
        else if(arr[mid] > target) right = mid - 1;
        else return mid;
    }
    return -1;
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
    printf("Nhập phần tử cần tìm kiếm: ");
    scanf("%d", &target);
    bubbleSort(arr, n);
    int result = binarySearch(arr, n, target);
    result != 1 ? printf("Phần tử có trong mảng") : printf("Không tìm thấy phần tử");
    free(arr);
    return 0;
}