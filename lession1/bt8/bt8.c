#include<stdio.h>

void countMaxCharacter(int* arr){
    int countMax = 0;
    int characterCountMax;

    for(int i = 0; i < 10; i++){
        int count = 0;
        for(int j = 0; j < 10; j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }
        if(count > countMax){
            countMax = count;
            characterCountMax = arr[i];
        }
    }

    printf("Phần tử xuất hiện nhiều nhất là %d: %d lần", characterCountMax, countMax);
}

// Độ phức tạp của cách này là O(n^2)

int main(){
    int arr[10] = {1, 2, 3, 2, 4, 4, 4, 2, 6, 4};
    countMaxCharacter(arr);
    return 0;
}