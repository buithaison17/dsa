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

void bubbleSortNode(Node** head){
    int length = getLengthNode(*head);
    for(int i = 0; i < length - 1; i++){
        Node* current = *head;
        for(int j = 0; j < length - i - 1; j++){
            if(current->data > current->next->data){
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
            }
            current = current->next;
        }
    }
}

int main(){
    Node* head = NULL;
    pushNode(&head, 30);
    pushNode(&head, 20);
    pushNode(&head, 10);
    pushNode(&head, 50);
    pushNode(&head, 0);
    printListNode(head);
    bubbleSortNode(&head);
    printListNode(head);
    return 0;
}