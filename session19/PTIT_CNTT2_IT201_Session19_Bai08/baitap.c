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

int heightTree(Node* root){
    if(root == NULL) return 0;
    int leftHeight = heightTree(root->left);
    int rightHeight = heightTree(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main(){
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    int height = heightTree(root) - 1;
    printf("%d", height);
    return 0;
}