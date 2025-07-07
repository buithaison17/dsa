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

void deleteNodeByValue(DoublyLinkedList** list, int data){
    Node* current = (*list)->head;
    while(current != NULL){
        Node* nextNode = current->next;
        if(current->data == data){
            if(current == (*list)->head){
                if((*list)->head->next == NULL){
                    (*list)->head = NULL;
                    (*list)->tail = NULL;
                }
                else{
                    (*list)->head = (*list)->head->next;
                }
            }
            else if(current == (*list)->tail){
                (*list)->tail = (*list)->tail->prev;
                (*list)->tail->next = NULL;
            }
            else{
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            free(current);
        }
        current = nextNode;
    }
}

int main(){
    DoublyLinkedList* list = NULL;
    createList(&list);
    unshiftNode(&list, 10);
    unshiftNode(&list, 10);
    unshiftNode(&list, 20);
    unshiftNode(&list, 10);
    unshiftNode(&list, 10);
    int data;
    printListNode(list);
    scanf("%d", &data);
    deleteNodeByValue(&list, data);
    printListNode(list);
    return 0;
}