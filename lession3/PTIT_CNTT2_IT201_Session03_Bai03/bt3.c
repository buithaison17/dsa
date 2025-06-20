#include<stdio.h>
#include<stdlib.h>

void averageEvenNumber(int arr[], int n){
    int sum = 0, count = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] % 2 == 0){
            sum += arr[i];
            count++;
        }
    }
    float average = sum / count;
    printf("average: %.2f", average);
}

int main(){
    int n;
    printf("Nhập số lượng phần tử: ");
    scanf("%d", &n);
    if(n < 0){
        printf("Số lượng phần tử không được âm");
    }
    else if(n == 0){
        printf("Số lượng phần tử phải lớn hơn 0");
    }
    else if(0 < n && n < 100){
        int *arr = (int*)malloc(n * sizeof(int));
        for(int i = 0; i < n; i++){
            printf("Nhập phần tử arr[%d]: ", i);
            scanf("%d", &arr[i]);
        }
        averageEvenNumber(arr, n);
        free(arr);
    }
    return 0;
}