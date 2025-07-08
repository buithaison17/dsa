#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

int top = -1;

void push(char stack[][MAX], char value[]){
    if(top >= MAX - 1) return;
    top++;
    strcpy(stack[top], value);
}

char* pop(char stack[][MAX]){
    if(top == -1) return "";
    char* value = stack[top];
    top--;
    return value;
}

void convertToInfix(char stack[][MAX], char postfix[], char infix[]){
    int length = strlen(postfix);
    for(int i = 0; i < length; i++){
        if(isdigit(postfix[i])){
            char temp[2] = {postfix[i], '\0'};
            push(stack, temp);
        }
        else if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/'){
            char* a = pop(stack);
            char* b = pop(stack);
            sprintf(infix, "(%s %c %s)", b, postfix[i], a);
            push(stack, infix);
        }
    }
}

int main(){
    char stack[MAX][MAX], postfix[MAX], infix[MAX];
    printf("Postfix: ");
    fgets(postfix, MAX, stdin);
    postfix[strcspn(postfix, "\n")] = '\0';
    convertToInfix(stack, postfix, infix);
    printf("Infix: %s", infix);
    return 0;
}