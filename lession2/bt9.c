#include<stdio.h>

void findCountMax(int arr[], int n){
    int maxCount = 0, character;
    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }
        if(count > maxCount){
            maxCount = count;
            character = arr[i];
        }
    }
    printf("%d", character);
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
        findCountMax(arr, n);
    }
    return 0;
}