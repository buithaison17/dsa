#include<stdio.h>

int isHasDuplicate(int* arr){
    int found = 0;
    for(int i = 0; i < 4; i++){
        for(int j = i + 1; j < 5; j++){
            if(arr[i] == arr[j]){
                return 1;
            }
        }
    }
    return 0;
}

// Độ phức tạp thời gian của cách này là O(n^2)

int main(){
    int arr[5] = {1,2,3,4,5};
    if(isHasDuplicate(arr)){
        printf("Có phân tử trùng lặp");
    }
    else{
        printf("Không có phần tử trùng lặp");
    }
    return 0;
}