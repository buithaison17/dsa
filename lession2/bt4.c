#include<stdio.h>

void editCharacter(int arr[], int n){
    int position, value;
    printf("Nhập vị trí muốn sửa (0 -> %d): ", n-1);
    scanf("%d", &position);
    printf("Nhập giá trị thay thế: ");
    scanf("%d", &value);
    if(position < 0 || position >= n){
        printf("Vị trí không hợp lệ");
        return;
    }
    arr[position] = value;
    for(int i = 0; i < n; i++){
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
        editCharacter(arr, n);
    }
    return 0;
}