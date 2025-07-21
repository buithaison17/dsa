#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data){
    if(root == NULL) return createNode(data);
    if(data < root->data) root->left = insert(root->left, data);
    else if(data > root->data) root->right = insert(root->right, data);
    return root;
}

int isCheck(Node* root, int min, int max){
    if(root == NULL) return 1;
    if(root->data <= min || root->data >= max) return 0;
    return isCheck(root->left, min, root->data) && isCheck(root->right, root->data, max);
}

int main(){
    Node* root = NULL;
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 8);
    root = insert(root, 6);
    root = insert(root, 7);
    isCheck(root, -100, 100) ? printf("True") : printf("False");
    return 0;
}