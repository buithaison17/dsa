#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct QueueNode{
    Node* treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue{
    QueueNode* front;
    QueueNode* rear;
    int size;
} Queue;

void initQueue(Queue** q){
    *q = (Queue*)malloc(sizeof(Queue));
    (*q)->front = NULL;
    (*q)->rear = NULL;
    (*q)->size = 0;
}

void enqueue(Queue** q, Node* data){
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->treeNode = data;
    newNode->next = NULL;
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

Node* dequeue(Queue** q){
    if((*q)->size == 0) return NULL;
    QueueNode* temp = (*q)->front;
    Node* tempData = temp->treeNode;
    (*q)->front = (*q)->front->next;
    free(temp);
    (*q)->size--;
    if((*q)->size == 0) (*q)->rear = NULL;
    return tempData;
}

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preorder(Node* root){
    if(root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}



void insert(Node** root, int data){
    if(root == NULL){
        *root = createNode(data);
        return;   
    }

    Queue* q;
    initQueue(&q);
    enqueue(&q, *root);

    while(q->size){
        Node* current = dequeue(&q);
        if(current->left == NULL){
            current->left = createNode(data);
            return;
        }
        else{
            enqueue(&q, current->left);
        }
        if(current->right == NULL){
            current->right = createNode(data);
            return;
        }
        else{
            enqueue(&q, current->right);
        }
    }

}

int main(){
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    insert(&root, 6);
    preorder(root);
    return 0;
}