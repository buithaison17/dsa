#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct Node{
    int data;
    struct Node* next;
} Node;


typedef struct Stack{
    Node* top;
    int size;
    int max;
} Stack;

void createStack(Stack** stack){
    *stack = (Stack*)malloc(sizeof(Stack));
    (*stack)->top = NULL;
    (*stack)->size = 0;
    (*stack)->max = MAX;
}

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main(){
    Stack* stack = NULL;
    createStack(&stack);
    free(stack);
    return 0;
}