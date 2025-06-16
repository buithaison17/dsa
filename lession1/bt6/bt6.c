#include<stdio.h>

void countCharacter(int* arr, int character){
    int count = 0;
    for(int i = 0; i < 5; i++){
        if(arr[i] == character){
            count++;
        }
    }
    printf("%d", count);
}

// Độ phức tạp thời gian là O(n);

int main(){
    int arr[5] = {3, 2, 1, 3, 4};
    int character; 
    printf("Nhập phần tử muốn đếm: ");
    scanf("%d", &character);
    countCharacter(arr, character);
    return 0;
}