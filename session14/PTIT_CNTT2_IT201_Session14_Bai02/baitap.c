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

void push(Stack** stack, int data){
    if((*stack)->size >= (*stack)->max) return;
    Node* newNode = createNode(data);
    newNode->next = (*stack)->top;
    (*stack)->top = newNode;
    (*stack)->size++;
}

int main(){
    Stack* stack = NULL;
    createStack(&stack);
    int n, value;
    printf("Nhập số lượng phần tử muốn thêm (tối đa 100): ");
    scanf("%d", &n);
    printf("Nhập từng phần tử: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &value);
        push(&stack, value);
    }
    printStack(stack);
    free(stack);
    return 0;
}