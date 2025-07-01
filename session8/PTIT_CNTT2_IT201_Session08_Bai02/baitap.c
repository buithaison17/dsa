#include<stdio.h>

int binarySearch(int arr[], int left, int right, int search){
    if(left > right) return -1;
    int mid = (left + right) / 2;
    if(arr[mid] < search) return binarySearch(arr, mid + 1, right, search);
    if(arr[mid] > search) return binarySearch(arr, left, mid - 1, search);
    else return mid;
}

// Độ phức tạp thời gian là O(logn)

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

// Độ phức tạp thời gian là O(n^2)

int main(){
    int n, search;
    printf("Nhập n: ");
    scanf("%d", &n);
    int arr[n];
    printf("Nhập các phần tử có trong mảng: ");
    for(int i = 0 ; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Nhập phần tử muốn tìm kiếm: ");
    scanf("%d", &search);
    bubbleSort(arr, n);
    int index = binarySearch(arr, 0, n, search);
    index != -1 ? printf("Vị trí thứ: %d", index) : printf("Không tồn tại phần tử");
    return 0;
}