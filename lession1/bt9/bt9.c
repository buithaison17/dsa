#include<stdio.h>

void printArr(int arr[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Độ phức tạp về thời gian là O(m*n)
// Độ phức tạp về không gian là O(1)

void printDuongCheoChinh(int arr[3][3]){
    for(int i = 0 ; i < 3; i++){
        printf("%d ", arr[i][i]);
    }
}

// Độ phức tạp về thời gian là O(n)

int main(){
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    printArr(arr);
    printDuongCheoChinh(arr);
    return 0;
}