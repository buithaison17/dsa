#include<stdio.h>

void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for(int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }
    for(int i = 0; i < n2; i++){
        R[i] = arr[mid + i + 1];
    }
    int i = 0, j = 0, index = left;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[index++] = L[i++];
        }
        else{
            arr[index++] = R[j++];
        }
    }
    while(i < n1){
        arr[index++] = L[i++];
    }
    while(j < n2){
        arr[index++] = R[j++];
    }
}

void mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main(){
    int n;
    printf("Nhập n: ");
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("before: ");
    printArr(arr, n);
    mergeSort(arr, 0, n - 1);
    printf("after: ");
    printArr(arr, n);
    return 0;
}