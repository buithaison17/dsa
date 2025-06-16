#include<stdio.h>

void bubbleSort(int* arr){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 5 - i - 1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Độ phức tạp thời gian của thuật toán sắp xếp này là O(n^2)

int main(){
    int arr[5] = {4, 3, 2, 1, 5};
    bubbleSort(arr);
    return 0;
}