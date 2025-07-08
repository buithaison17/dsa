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

int pop(int stack[]){
    if(top == -1){
        printf("No element in stack");
        return -1;
    }
    int value = stack[top];
    top--;
    return value;
}

void printStack(int stack[]){
    for(int i = top; i >= 0; i--){
        printf("%d\n", stack[i]);
    }
    printf("\n");
}

int main(){
    int stack[max];
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    printStack(stack);
    return 0;
}