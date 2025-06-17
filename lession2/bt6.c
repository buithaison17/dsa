#include<stdio.h>

void addCharacter(int arr[], int n){
    int position, value;
    printf("Nhập vị trí muốn thêm (0 -> %d):", n);
    scanf("%d", &position);
    if(0 > position || position > n){
        printf("Vị trí xóa không hợp lệ");
        return;
    }
    printf("Nhập giá trị: ");
    scanf("%d", &value);
    for(int i = n; i > position; i--){
        arr[i] = arr[i-1];
    }
    arr[position] = value;
    for(int i = 0; i < n+1; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int n, arr[100];
    printf("Nhập số lượng phần tử: ");
    scanf("%d", &n);
    if(0 < n && n <= 100){
        for(int i = 0; i < n; i++){
            printf("Nhập phần tử arr[%d]: ", i);
            scanf("%d", &arr[i]);
        }
        addCharacter(arr, n);
    }
    return 0;
}