#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

int top = -1;

void push(char stack[], char value){
    if(top >= MAX - 1) return;
    top++;
    stack[top] = value;
}

char pop(char stack[]){
    if(top == -1) return '\0';
    char value = stack[top];
    top--;
    return value;
}

int compareOperator(char op){
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

void convertToPostfix(char stack[], char infix[], char postfix[]){
    int length = strlen(infix);
    int index = 0;
    for(int i = 0; i < length; i++){
        char ch = infix[i];
        if(isdigit(ch)){
            postfix[index++] = ch;
        }
        else if(ch == '('){
            push(stack, ch);
        }
        else if(ch == ')'){
            while(top != -1 && stack[top] != '('){
                postfix[index++] = pop(stack);
            }
            pop(stack);
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            while(top != -1 && compareOperator(stack[top]) >= compareOperator(ch)){
                postfix[index++] = pop(stack);
            }
            push(stack, ch);
        }
    }
    while(top != -1){
        postfix[index++] = pop(stack);
    }
    postfix[index] = '\0';
}

int main(){
    char stack[MAX], infix[MAX], postfix[MAX];
    printf("Infix: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0';
    convertToPostfix(stack, infix, postfix);
    printf("Postfix: %s", postfix);
    return 0;
}