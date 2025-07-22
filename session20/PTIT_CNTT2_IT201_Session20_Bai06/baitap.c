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

int findLevelOfNode(Node* root, int data){
    if(root == NULL) return -1;
    if(root->data == data) return 0;

    int level = 0;
    Queue* q;
    initQueue(&q);
    enqueue(&q, root);

    while(q->size){
        int n  = q->size;
        for(int i = 0; i < n; i++){
            Node* current = dequeue(&q);
            level++;
            if(current->left != NULL){
                if(current->left->data == data){
                    return level;
                }
                else{
                    enqueue(&q, current->left);
                }
            }
            if(current->right != NULL){
                if(current->right->data == data){
                    return level;
                }
                else{
                    enqueue(&q, current->right);
                }
            }
        }
        level++;
    }
    return -1;
}

int main(){
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    int level = findLevelOfNode(root, 3);
    printf("%d ", level);
    return 0;
}