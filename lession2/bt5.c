#include<stdio.h>

void deleteCharacter(int arr[], int n){
    int position;
    printf("Nhập vị trí muốn xóa(0 -> %d): ", n-1);
    scanf("%d", &position);
    if(position < 0 || position >= n){
        printf("Vị trí xóa không hợp lệ");
        return;
    }
    for(int i = position; i < n; i++){
        arr[i] = arr[i+1];
    }
    for(int i = 0; i < n-1; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int n;
    printf("Nhập số lượng phần tử: ");
    scanf("%d", &n);
    if(0 < n && n <= 100){
        int arr[n];
        for(int i = 0; i < n; i++){
            printf("Nhập phần tử arr[%d]: ", i);
            scanf("%d", &arr[i]);
        }
        deleteCharacter(arr, n);
    }
    return 0;
}