#include<stdio.h>

int findIndex(int arr[], int length, int search){
    for(int i = 0; i < length; i++){
        if(arr[i] == search) return i;
    }
    return - 1;
}

// Độ phức tạp thời gian là O(n)

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
    int index = findIndex(arr, n, search);
    index != -1 ? printf("Vị trí thứ: %d", index) : printf("Không tồn tại phần tử");
    return 0;
}