#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

int top = -1;

void push(char stack[][MAX], char data[]){
    if(top >= MAX - 1) return;
    top++;
    strcpy(stack[top], data);
}

char* pop(char stack[][MAX]){
    char* data = stack[top];
    top--;
    return data;
}

void converToInfix(char stack[][MAX], char postfix[]){
    int length = strlen(postfix);
    char result[MAX];
    for(int i = 0; i < length; i++){
        if(isdigit(postfix[i])){
            char temp[2] = {postfix[i], '\0'};
            push(stack, temp);
        }
        else if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/'){
            char* a = pop(stack);
            char* b = pop(stack);
            sprintf(result, "(%s %c %s)", b, postfix[i], a);
            push(stack, result);
        }
    }
    printf("Infix: %s", result);
}

int main(){
    char stack[MAX][MAX];
    char postfix[MAX];
    printf("Postfix: ");
    fgets(postfix, MAX, stdin);
    postfix[strcspn(postfix, "\n")] = '\0';
    converToInfix(stack, postfix);
    return 0;
}