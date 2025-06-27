#include<stdio.h>
#include<stdlib.h>

int findMax(int arr[], int max, int index){
    if(index < 0) return max;
    if(arr[index] > max) return findMax(arr, arr[index], index - 1);
    return findMax(arr, max, index - 1);
}

int findMin(int arr[], int min, int index){
    if(index < 0) return min;
    if(arr[index] < min) return findMin(arr, arr[index], index - 1);
    return findMin(arr, min, index - 1);
}

int main(){
    int n;
    printf("Nhập n: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        printf("Nhập arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    int max = findMax(arr, arr[n-1], n-2);
    int min = findMin(arr, arr[n-1], n-2);
    printf("max: %d\nmin: %d", max, min);
    return 0;
}