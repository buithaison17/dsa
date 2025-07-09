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

int pop(Stack** stack){
    if((*stack)->size == 0){
        printf("Ngăn xếp trống");
        return -1;
    }
    int value = (*stack)->top->data;
    Node* temp = (*stack)->top;
    (*stack)->top = (*stack)->top->next;
    (*stack)->size--;
    free(temp);
    return value;
}

void peek(Stack* stack){
    if(stack->size == 0){
        printf("Ngăn xếp trống\n");
        return;
    }
    printf("%d\n", stack->top->data);
}

void printStack(Stack* stack){
    if(stack->size == 0){
        printf("Ngăn xếp trống\n");
        return;
    }
    Node* current = stack->top;
    while(current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
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
    peek(stack);
    return 0;
}