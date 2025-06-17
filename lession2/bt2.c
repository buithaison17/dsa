#include<stdio.h>

void countCharacter(int arr[], int n){
    int character, count = 0;
    printf("Nhập phần tử muốn đếm số lượng: ");
    scanf("%d", &character);
    for(int i = 0; i < n; i++){
        if(arr[i] == character){
            count++;
        }
    }
    printf("%d", character);
}

int main(){
    int n;
    printf("Nhập số phần tử muốn thêm: ");
    scanf("%d", &n);
    if(0 < n && n <= 100){
        int arr[n];
        for(int i = 0; i < n; i++){
            printf("Nhập phần tử arr[%d]: ", i);
            scanf("%d", &arr[i]);
        }
        countCharacter(arr, n);
    }
    return 0;
}