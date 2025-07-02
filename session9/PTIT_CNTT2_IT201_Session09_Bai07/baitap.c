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

void shiftNode(Node** head){
    Node* temp = (*head)->next;
    (*head) = temp;
}

int getLengthNode(Node* head){
    int length = 0;
    Node* current = head;
    while(current != NULL){
        length++;
        current = current->next;
    }
    return length;
}

void pushNode(Node** head, int data){
    Node* newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
    }
    else{
        Node* current = *head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
}

void insertNode(Node** head, int index, int data){
    if(index < 0 || index > getLengthNode(*head)){
        printf("Index không hợp lệ");
        return;
    }
    
    if(index == 0){
        unshiftNode(head, data);
        return;
    }

    if(index == getLengthNode(*head)){
        pushNode(head, data);
        return;
    }

    Node* newNode = createNode(data);
    Node* current = *head;
    for(int i = 0; i < index - 1; i++){
        current = current->next;
    }
    Node* nextNode = current->next;
    newNode->next = nextNode;
    current->next = newNode;
}

int main(){
    Node* head = NULL;
    pushNode(&head, 10);
    pushNode(&head, 30);
    pushNode(&head, 40);
    pushNode(&head, 50);
    insertNode(&head, 1, 20);
    insertNode(&head, 0, 0);
    printListNode(head);
    return 0;
}