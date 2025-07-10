#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Customer{
    char fullName[100];
    int age;
} Customer;

typedef struct Node{
    Customer c;
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

Node* createNode(Customer c){
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->c.fullName, c.fullName);
    newNode->c.age = c.age;
    newNode->next = NULL;
    return newNode;
}

void enqueue(Queue** q, Customer c){
    Node* newNode = createNode(c);
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

Customer dequeue(Queue** q){
    if((*q)->size == 0){
        Customer empty = {"", 0};
        printf("Danh sách trống\n");
        return empty;
    }
    else{
        Customer c = (*q)->front->c;
        Node* temp = (*q)->front;
        (*q)->front = (*q)->front->next;
        free(temp);
        (*q)->size--;
        if((*q)->size == 0) (*q)->rear = NULL;
        return c;
    }
}

void printQueue(Queue* q){
    Node* current = q->front;
    while(current != NULL){
        printf("Họ tên: %s\n", current->c.fullName);
        printf("Tuổi: %d\n", current->c.age);
        current = current->next;
    }
}

int main(){
    Queue* queueOld;
    Queue* queueNormal;
    Customer c;
    initQueue(&queueOld);
    initQueue(&queueNormal);
    int choice;
    do{
        printf("1. Thêm khách\n");
        printf("2. Phục vụ\n");
        printf("3. Xem hàng chờ\n");
        printf("Lựa chọn: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                getchar();
                printf("Nhập tên: ");
                fgets(c.fullName, sizeof(c.fullName), stdin);
                c.fullName[strcspn(c.fullName, "\n")] = '\0';
                printf("Nhập tuổi: ");
                scanf("%d", &c.age);
                c.age >= 60 ? enqueue(&queueOld, c) : enqueue(&queueNormal, c);
                printf("Thêm thành công vào hàng chờ\n");
                break;
            case 2:
                Customer new;
                if(queueNormal->size == 0 && queueOld->size == 0){
                    printf("Danh sách chờ trống\n");
                }
                else if(queueOld->size != 0){
                    new = dequeue(&queueOld);
                    printf("Phục vụ ưu tiên: %s\n", new.fullName);
                    printf("Tuổi: %d\n", new.age);
                }
                else{
                    new = dequeue(&queueNormal);
                    printf("Phục vụ thường: %s\n", new.fullName);
                    printf("Tuổi: %d\n", new.age);
                }
                break;
            case 3:
                if(queueNormal->size == 0 && queueOld->size == 0){
                    printf("Danh sách chờ trống\n");
                }
                if(queueOld->size != 0){
                    printf("Danh sách ưu tiên:\n");
                    printQueue(queueOld);
                }
                else{
                    printf("Danh sách chờ ưu tiên trống\n");
                }
                if(queueNormal->size != 0){
                    printf("Danh sách chờ thường:\n");
                    printQueue(queueNormal);
                }
                else{
                    printf("Danh sách chờ thường trống\n");
                }
                break;
            case 4:
                break;
            default:
                break;
        }
    }
    while(choice != 4);
    return 0;
}