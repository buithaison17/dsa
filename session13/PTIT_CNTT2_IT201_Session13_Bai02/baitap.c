#include<stdio.h>
#define max 5

int top = -1;

void push(int stack[], int value){
    if(top >= max - 1){
        return;
    }
    top++;
    stack[top] = value;
}

void printStack(int stack[]){
    for(int i = 0; i <= top; i++){
        printf("%d ", stack[i]);
    }
    printf("\n");
    printf("top: %d\n", top);
    printf("cap: %d\n", max);
}

int main(){
    int stack[max];
    int value;
    for(int i = 0; i < 5; i++){
        printf("Nhập phần tử của stack: ");
        scanf("%d", &value);
        push(stack, value);
    }
    printStack(stack);
    return 0;
}