#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct QueueNode{
    TreeNode* treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue{
    QueueNode* front;
    QueueNode* rear;
    int size;
} Queue;

TreeNode* createNode(int data){
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void initQueue(Queue** q){
    *q = (Queue*)malloc(sizeof(Queue));
    (*q)->front = NULL;
    (*q)->rear = NULL;
    (*q)->size = 0;
}

void enqueue(Queue** q, TreeNode* data){
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

TreeNode* dequeue(Queue** q){
    if((*q)->size == 0) return NULL;
    QueueNode* temp = (*q)->front;
    TreeNode* tempData = temp->treeNode;
    (*q)->front = (*q)->front->next;
    (*q)->size--;
    free(temp);
    if((*q)->size == 0) (*q)->rear = NULL;
    return tempData;
}

int BFS(TreeNode* root, int valueSearch){
    if(root == NULL) return 0;
    Queue* q;
    initQueue(&q);
    enqueue(&q, root);
    while((*q).size != 0){
        TreeNode* current = dequeue(&q);
        if(current->data == valueSearch) return 1;
        if(current->left) enqueue(&q, current->left);
        if(current->right) enqueue(&q, current->right);
    }
}

int main(){
    TreeNode* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    int valueSearch;
    printf("Nhap du lieu muon tim: ");
    scanf("%d", &valueSearch);
    BFS(root, valueSearch) ? printf("True") : printf("False");
    return 0;
}