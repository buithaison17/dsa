#include<stdio.h>
#include<string.h>
#define max 100

int top = -1;

void push(char stack[], char value){
    if(top >= max -1){
        printf("Stack Overflow");
    }
    else{
        top++;
        stack[top] = value;
    }
}

char pop(char stack[]){
    if(top == -1){
        printf("No element in stack");
    }
    else{
        char value = stack[top];
        top--;
        return value;
    }
}

void printStack(char stack[]){
    for(int i = top; i >= 0; i--){
        printf("%c", stack[i]);
    }
}

int main(){
    char stack[max];
    char str[max];
    printf("Input: ");
    fgets(str, max, stdin);    
    str[strcspn(str, "\n")] = '\0';
    int length = strlen(str);
    for(int i = 0; i < length / 2; i++){
        push(stack, str[i]);
    }
    int start = length / 2 == 0 ? length / 2 : length / 2 + 1;
    int found = 0;
    for(int i = start; i < length; i++){
        if(str[i] != pop(stack)){
            found = 1;
            break;
        }
    }
    found == 0 ? printf("True") : printf("False");
    return 0;
}