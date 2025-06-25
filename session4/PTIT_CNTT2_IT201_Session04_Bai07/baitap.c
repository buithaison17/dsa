#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, found = 0;
    printf("Nhập số lượng phần tử: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        printf("Nhập phần tử arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n / 2; i++){
        if(arr[i] == arr[n-i-1]){
            printf("Cặp đối xứng: (%d, %d)\n", arr[i], arr[i]);
            found = 1;
        }
    }
    if(!found) printf("Không có phần tử đối xứng");
    free(arr);
    return 0;
}