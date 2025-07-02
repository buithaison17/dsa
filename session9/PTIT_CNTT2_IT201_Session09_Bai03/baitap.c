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

int getNode(Node* head, int data){
    if(head->data == data){
        return 1;
    }
    Node* current = head;
    while(current != NULL){
        if(current->data == data) return 1;
        current = current->next;
    }
    return -1;
}

int main(){
    Node* head = createNode(1);
    Node* node1 = createNode(2);
    Node* node2 = createNode(3);
    Node* node3 = createNode(4);
    Node* node4 = createNode(5);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    
    getNode(head, 7) != -1 ? printf("True") : printf("False");

    return 0;
}