#include<stdio.h>
#include<stdlib.h>

int calculateSum(int arr[], int left, int right){
    if(right == left) return arr[0];
    return arr[right] + calculateSum(arr, left, right-1);
}

int main(){
    int n;
    printf("Nhập n: ");
    scanf("%d", &n);
    if(n > 0){
        int *arr = (int *)malloc(n * sizeof(int));
        for(int i = 0; i < n; i++){
            printf("Nhập arr[%d]: ", i);
            scanf("%d", &arr[i]);
        }
        int result = calculateSum(arr, 0, n-1);
        printf("%d", result);
        free(arr);
    }
    else{
        printf("Không hợp lệ");
    }
    return 0;
}