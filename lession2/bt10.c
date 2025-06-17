#include<stdio.h>

void countCharacter(int arr[], int n){
    int checkCharacter[n], countCheckCharacter[n], index = 0;
    for(int i = 0; i < n; i++){
        int found = 0;
        for(int j = 0; j < index; j++){
            if(arr[i] == arr[j]){
                found = 1;
                break;
            }
        }
        if(!found){
            int count = 0;
            checkCharacter[index] = arr[i];
            for(int k = 0; k < n; k++){
                if(arr[i] == arr[k]){
                    count++;
                }
            }
            countCheckCharacter[index++] = count;
        }
    }
    for(int i = 0; i < index; i++){
        printf("%d: %d\n", checkCharacter[i], countCheckCharacter[i]);
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
        countCharacter(arr, n);
    }
    return 0;
}