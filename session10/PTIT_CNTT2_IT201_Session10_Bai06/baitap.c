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

void printListNode(Node* head){
    Node* current = head;
    while(current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int getLengthNode(Node* head){
    Node* current = head;
    int length = 0;
    while(current != NULL){
        length++;
        current = current->next;
    }
    return length;
}

void getMidNode(Node* head){
    int mid = getLengthNode(head) / 2;
    Node* current = head;
    for(int i = 0; i < mid; i++){
        current = current->next;
    }
    printf("Node %d: %d", mid+1, current->data);
}

int main(){
    Node* head = NULL;
    pushNode(&head, 5);
    pushNode(&head, 4);
    pushNode(&head, 3);
    pushNode(&head, 2);
    pushNode(&head, 1);
    pushNode(&head, 6);
    getMidNode(head);
    return 0;
}