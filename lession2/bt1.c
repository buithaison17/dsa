#include<stdio.h>

void findMaxCharacter(int arr[], int n){
    int max = arr[0];
    for(int i = 1; i < n; i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }
    printf("%d", max);
}

int main(){
    int n;
    printf("Nhập số lượng phần tử: ");
    scanf("%d", &n);
    if(n > 0 && n <= 100){
        int arr[n];
        for(int i = 0; i < n; i++){
            printf("Nhập phần tử arr[%d]: ", i);
            scanf("%d", &arr[i]);
        }
        findMaxCharacter(arr, n);
    }

    return 0;
}