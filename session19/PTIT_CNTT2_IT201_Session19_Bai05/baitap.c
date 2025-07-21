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

int DFS(Node* root, int valueSearch){
    if(root == NULL) return 0;
    if(root->data == valueSearch) return 1;
    if(root->left) return DFS(root->left, valueSearch);
    return DFS(root->right, valueSearch);
}

int main(){
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    int valueSearch;
    printf("Nhap du lieu muon tim: ");
    scanf("%d", &valueSearch);
    DFS(root, valueSearch) ? printf("True") : printf("False");
    return 0;
}