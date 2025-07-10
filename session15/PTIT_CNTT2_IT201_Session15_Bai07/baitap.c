#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node{
    char fullName[100];
    struct Node* next;
} Node;

typedef struct Queue{
    Node* front;
    Node* rear;
    int size;
} Queue;

void initQueue(Queue** q){
    *q = (Queue*)malloc(sizeof(Queue));
    (*q)->front = NULL;
    (*q)->rear = NULL;
    (*q)->size = 0;
}

Node* createNode(char fullName[]){
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->fullName, fullName);
    newNode->next = NULL;
    return newNode;
}

void enqueue(Queue** q, char fullName[]){
    Node* newNode = createNode(fullName);
    if((*q)->size == 0){
        (*q)->front = newNode;
        (*q)->rear = newNode;
    }
    else{
        (*q)->rear->next = newNode;
        (*q)->rear = newNode;
    }
    (*q)->size++;
}

char* dequeue(Queue** q){
    if((*q)->size == 0){
        printf("\nHàng chờ trống\n\n");
        return "";
    }
    char* fullName = (char*)malloc(100*sizeof(char));
    strcpy(fullName, (*q)->front->fullName);
    Node* temp = (*q)->front;
    (*q)->front = (*q)->front;
    free(temp);
    (*q)->size--;
    if((*q)->size == 0) (*q)->rear = NULL;
    return fullName;
}

void printQueue(Queue* q){
    if((*q).size == 0){
        printf("Danh sách trống\n");
        return;
    }
    Node* current = q->front;
    while(current != NULL){
        printf("%s\n", current->fullName);
        current = current->next;
    }
    printf("\n");
}

int main(){
    Queue* queue;
    initQueue(&queue);
    char nameCustomer[100];
    int choice;
    do{
        printf("2. Thêm khách\n");
        printf("1. Phục vụ\n");
        printf("3. Xem danh sách\n");
        printf("4. Thoát\n");
        printf("Lựa chọn: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                getchar();
                printf("Nhập tên: ");
                fgets(nameCustomer, 100, stdin);
                nameCustomer[strcspn(nameCustomer, "\n")] = '\0';
                printf("\n%s\n", nameCustomer);
                enqueue(&queue, nameCustomer);
                break;
            case 2:
                char* fullName = dequeue(&queue);
                printf("Phục vụ khách hàng: %s\n", fullName);
                break;
            case 3:
                printQueue(queue);
                break;
        }
    }
    while(choice != 4);
    return 0;
}