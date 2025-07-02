#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node* createNode(int data){
    Node* newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printListNode(Node* head){
    Node* current = head;
    while(current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void unshiftNode(Node** head, int data){
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

int main(){
    Node* head = NULL;

    unshiftNode(&head, 10);
    unshiftNode(&head, 20);
    unshiftNode(&head, 30);

    printListNode(head);
    return 0;
}