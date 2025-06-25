#include<stdio.h>
#include<stdlib.h>

int findMax(int arr[], int n){
    int max = arr[0], index = 0;
    for(int i = 0; i < n; i++){
        if(max < arr[i]){
            max = arr[i];
            index = i;
        }
    }
    return index;
}

int main(){
    int n, target;
    printf("Nhập số lượng phần tử: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        printf("Nhập phần tử arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    int result = findMax(arr, n);
    printf("%d", result);
    free(arr);
    return 0;
}