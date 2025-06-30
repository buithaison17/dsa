#include<stdio.h>

void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void solution(int arr[], int n){
    int negativeArr[n], positiveArr[n], zeroArr[n];
    int negativeCount = 0, positiveCount = 0, zeroCount = 0;
    
    // Lọc các phần tử nhỏ hơn 0, bằng 0 và lớn hơn 0
    for(int i = 0; i < n; i++){
        if(arr[i] < 0){
            negativeArr[negativeCount++] = arr[i];
        }
        else if(arr[i] == 0){
            zeroArr[zeroCount++] = arr[i]; 
        }
        else{
            positiveArr[positiveCount++] = arr[i];
        }
    }

    // Đảo ngược mảng số lẻ và số chẵn
    for(int i = 0; i < negativeCount / 2; i++){
        int temp = negativeArr[i];
        negativeArr[i] = negativeArr[negativeCount - i - 1];
        negativeArr[negativeCount - i - 1] = temp;
    }
    for(int i = 0; i < positiveCount / 2; i++){
        int temp = positiveArr[i];
        positiveArr[i] = positiveArr[positiveCount - i - 1];
        positiveArr[positiveCount - i - 1] = temp;
    }

    // Ghép mảng
    int index = 0;
    for(int i = 0; i < negativeCount; i++){
        arr[index++] = negativeArr[i];
    }
    for(int i = 0; i < zeroCount; i++){
        arr[index++] = zeroArr[i];
    }
    for(int i = 0; i < positiveCount; i++){
        arr[index++] = positiveArr[i];
    }
}

int main(){
    int n;
    printf("Nhập n (0 -> 1000): ");
    scanf("%d", &n);
    if(n < 0){
        printf("Không hợp lệ");
    }
    else{
        int arr[n];
        for(int i = 0; i < n; i++){
            printf("Nhập arr[%d]: ", i);
            scanf("%d", &arr[i]);
        }
        printf("before: ");
        printArr(arr, n);
        solution(arr, n);
        printf("after: ");
        printArr(arr, n);
    }
    return 0;
}