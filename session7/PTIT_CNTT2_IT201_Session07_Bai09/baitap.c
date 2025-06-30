#include<stdio.h>
#include<stdlib.h>

void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void solution(int arr[], int n){
    int evenArr[n], oddArr[n];
    int evenCount = 0, oddCount = 0;
    
    // Lọc phần tử chẵn và lẻ
    for(int i = 0; i < n; i++){
        if(arr[i] % 2 == 0){
            evenArr[evenCount++] = arr[i];
        }
        else{
            oddArr[oddCount++] = arr[i];
        }
    }

    // Sắp xếp phần tử chẵ
    for(int i = 0; i < evenCount - 1; i++){
        for(int j = 0; j < evenCount - i - 1; j++){
            if(evenArr[j] > evenArr[j+1]){
                int temp = evenArr[j];
                evenArr[j] = evenArr[j+1];
                evenArr[j+1] = temp;
            }
        }
    }

    // Sắp xếp phần tử lẻ
    for(int i = 0; i < oddCount - 1; i++){
        for(int j = 0; j < oddCount - i - 1; j++){
            if(oddArr[j] < oddArr[j+1]){
                int temp = oddArr[j];
                oddArr[j] = oddArr[j+1];
                oddArr[j+1] = temp;
            }
        }
    }

    // Gộp mảng
    int index = 0;
    for(int i = 0; i < evenCount; i++){
        arr[index++] = evenArr[i];
    }
    for(int i = 0; i < oddCount; i++){
        arr[index++] = oddArr[i];
    }
}

int main(){
    int n, *arr;
    printf("Nhập n: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    solution(arr, n);
    printArr(arr, n);
    return 0;
}