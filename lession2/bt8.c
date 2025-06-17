#include<stdio.h>

void findCharacter(int arr[], int n){
    for(int i = 0; i < n; i++){
        int check = 0;
        for(int j = i + 1; j < n; j++){
            if(arr[i] < arr[j]){
                check = 1;
                break;
            }
        }
        if(!check){
            printf("%d ", arr[i]);
        }
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
    }
    findCharacter(arr, n);
    return 0;
}