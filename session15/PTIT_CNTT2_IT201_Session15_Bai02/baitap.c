#include<stdio.h>
#define MAX 5

int front = 0, rear = -1;

void enqueue(int arr[], int value){
    if(rear >= MAX -1){
        printf("queue is full\n");
        return;
    }
    rear++;
    arr[rear] = value;
}

void printQueue(int arr[]){
    if(rear == -1){
        printf("queue is empty");
        return;
    }
    for(int i = 0; i <= rear; i++){
        printf("%d ", arr[i]);
    }
    printf("\nfront: %d\n", front);
    printf("rear: %d\n", rear);
}

int main(){
    int array[MAX];
    enqueue(array, 10);
    enqueue(array, 20);
    enqueue(array, 30);
    enqueue(array, 40);
    enqueue(array, 50);
    enqueue(array, 60);
    printQueue(array);
    return 0;
}