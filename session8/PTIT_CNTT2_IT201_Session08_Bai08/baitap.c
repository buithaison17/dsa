#include<stdio.h>

void printArr(int arr[], int n){
    for(int i = 0 ; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int linearSearch(int arr[], int n, int target){
    for(int i = 0; i < n; i++){
        if(arr[i] == target) return i;
    }
    return -1;
}

int binarySearch(int arr[], int left, int right, int target){
    if(left > right) return -1;
    int mid = (left + right) / 2;
    if(arr[mid] < target) return binarySearch(arr, mid + 1, right, target);
    if(arr[mid] > target) return binarySearch(arr, left, mid - 1, target);
    return mid;
}

int main(){
    int n, search;
    printf("Nhập n: ");
    scanf("%d", &n);
    int arr[n];
    printf("Nhập các phần tử có trong mảng: ");
    for(int i = 0 ; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("before: ");
    printArr(arr, n);
    insertionSort(arr, n);
    printf("after: ");
    printArr(arr, n);
    printf("Nhập phần tử muốn tìm kiếm: ");
    scanf("%d", &search);
    printf("Vị trí tìm kiếm bằng Linear Search: %d", linearSearch(arr, n, search));
    printf("\nVị trí tìm kiếm bằng Binary Search: %d", binarySearch(arr, 0, n, search));
    return 0;
}