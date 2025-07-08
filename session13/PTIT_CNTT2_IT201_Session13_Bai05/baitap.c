#include<stdio.h>
#define max 100

int top = -1;

void push(int stack[], int value){
    if(top >= max - 1){
        return;
    }
    top++;
    stack[top] = value;
}

int pop(int stack[]){
    if(top == -1){
        return -1;
    }
    int value = stack[top];
    top--;
    return value;
}

void printStack(int stack[]){
    for(int i = top; i >= 0; i--){
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void reverseArr(int stack[], int arr[], int n){
    for(int i = 0; i < n; i++){
        arr[i] = pop(stack);
    }
}

void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int stack[max];
    int arr[max];
    int n;
    printf("Nhập số lượng phần tử của mảng (Tối đa 100): ");
    scanf("%d", &n);
    if(n < 0 || n > 100){
        printf("Số lượng phần tử không hợp lệ");
    }
    else{
        for(int i = 0; i < n; i++){
            printf("arr[%d]: ", i);
            scanf("%d", &arr[i]);
            push(stack, arr[i]);
        }
    }
    printf("Before: ");
    printArr(arr, n);
    reverseArr(stack, arr, n);
    printf("\nAfter: ");
    printArr(arr, n);
    return 0;
}