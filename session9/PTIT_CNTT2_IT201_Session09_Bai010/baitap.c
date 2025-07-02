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

void deleteNodeAt(Node** head, int index){
    if(index < 0 || index > getLengthNode(*head) - 1){
        printf("Index không hợp lệ\n");
        return;
    }
    
    Node* temp = NULL;

    if(index == 0){
        temp = (*head)->next;
        *head = temp;
        free(temp);
    }

    Node* current = *head;

    for(int i = 0; i < index - 1; i++){
        current = current->next;
    }

    temp = current->next;
    current->next = temp->next;
    free(temp);
}

void reverseNode(Node** head){
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void swapDouble(Node** head){
    if(*head == NULL || (*head)->next == NULL){
        return;
    }

    Node* prev = NULL;
    Node* current = *head;
    *head = current->next;

    if(current != NULL && current->next != NULL){
        Node* nextNode = current->next;
        Node* nextTwoNode = nextNode->next;
    
        // Đổi chỗ
        nextNode->next = current;
        current->next = nextTwoNode;
        
        if(prev != NULL){
            prev->next = nextNode;
        }

        // Gắn lại vị trí con trỏ
        prev = current;
        current = current->next;
    }

}

int main(){
    Node* head = NULL;
    pushNode(&head, 10);
    pushNode(&head, 20);
    pushNode(&head, 30);
    pushNode(&head, 40);
    pushNode(&head, 50);
    swapDouble(&head);
    printListNode(head);
    return 0;
}