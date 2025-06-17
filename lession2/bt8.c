#include<stdio.h>

int main(){
    int n, arr[100];
    printf("Nhập số lượng phần tử: ");
    scanf("%d", &n);
    if(0 < n && n <= 100){
        for(int i = 0; i < n; i++){
            printf("Nhập phần tử arr[%d]: ", i);
            scanf("%d", &arr[i]);
        }
        countCharacter(arr, n);
    }
    return 0;
}