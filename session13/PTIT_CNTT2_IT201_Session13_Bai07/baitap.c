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

int isMatching(char open, char close){
    if(open == '[' && close == ']') return 0;
    if(open == '(' && close == ')') return 0;
    if(open == '{' && close == '}') return 0;
    return 1;
}

int isValidBrackets(char stack[], char str[]){
    int length = strlen(str);
    for(int i = 0; i < length; i++){
        if(str[i] == '[' || str[i] == '(' || str[i] == '{'){
            push(stack, str[i]);
        }
        else if(str[i] == ']' || str[i] == ')' || str[i] == '}'){
            if(top == -1) return 0;
            char open = pop(stack);
            if(!isMatching(open, str[i])) return 0;
        }
    }
    return 1;
}

int main(){
    char stack[max];
    char str[max];
    printf("Input: ");
    fgets(str, max, stdin);    
    str[strcspn(str, "\n")] = '\0';
    isValidBrackets(stack, str) ? printf("True") : printf("False");
    return 0;
}