#include<stdio.h>

void findElement(int arr[], int n){
    int sum, found = 0;
    printf("Nhập tổng: ");
    scanf("%d", &sum);
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] + arr[j] == sum){
                found = 1;
                printf("%d %d", arr[i], arr[j]);
            }
        }
    }
    if(!found){
        printf("Không tìm thấy");
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
        findElement(arr, n);
    }
    return 0;
}