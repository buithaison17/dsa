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

void deleteNodeByValue(Node** head, int data){
    Node* current = *head;
    Node* temp = NULL;
    int found = 0;

    if(current->data == data){
        temp = *head;
        *head = (*head)->next;
        free(temp);
        found = 1;
    }

    while(current != NULL && current->next != NULL){
        if(current->next->data == data){
            found = 1;
            temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
        current = current->next;
    }

    if(!found){
        printf("Phần tử không tồn tại\n");
    }
}


int main(){
    Node* head = NULL;
    int dataDelete;
    pushNode(&head, 30);
    pushNode(&head, 50);
    pushNode(&head, 10);
    pushNode(&head, 50);
    pushNode(&head, 0);
    printListNode(head);
    printf("Nhập dữ liệu muốn xóa: ");
    scanf("%d", &dataDelete);
    deleteNodeByValue(&head, dataDelete);
    printListNode(head);
    return 0;
}