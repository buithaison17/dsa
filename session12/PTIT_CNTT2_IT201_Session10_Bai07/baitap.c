#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct DoublyLinkedList{
    Node* head;
    Node* tail;
} DoublyLinkedList;

void createList(DoublyLinkedList** list){
    *list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    (*list)->head = NULL;
    (*list)->tail = NULL;
}

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void unshiftNode(DoublyLinkedList** list, int data){
    Node* newNode = createNode(data);
    if((*list)->head == NULL){
        (*list)->head = newNode;
        (*list)->tail = newNode;
    }
    else{
        newNode->next = (*list)->head;
        (*list)->head->prev = newNode;
        (*list)->head = newNode;
    }
}

void shiftNode(DoublyLinkedList** list){
    if((*list)->head == (*list)->tail){
        (*list)->head = NULL;
        (*list)->tail = NULL;
        free((*list)->head);
    }
    else{
        Node* temp = (*list)->head;
        (*list)->head = (*list)->head->next;
        free(temp);
    }
}

void printListNode(DoublyLinkedList* list){
    Node* current = list->head;
    while(current!= NULL){
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int getLengthNode(DoublyLinkedList* list){
    Node* current = list->head;
    int length = 0;
    while(current != NULL){
        length++;
        current = current->next;
    }
    return length;
}

void bubbleSortLinkedList(DoublyLinkedList** list){
    int length = getLengthNode(*list);
    for(int i = 0; i < length - 1; i++){
        Node* current = (*list)->head;
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
    DoublyLinkedList* list = NULL;
    createList(&list);
    unshiftNode(&list, 10);
    unshiftNode(&list, 40);
    unshiftNode(&list, 20);
    unshiftNode(&list, 30);
    printListNode(list);
    bubbleSortLinkedList(&list);
    printListNode(list);
    return 0;
}