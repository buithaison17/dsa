#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph{
    Node** adjList;
    int numVertices;
} Graph;

Graph* initGraph(int vertices){
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->adjList = (Node**)malloc(vertices*sizeof(Node*));
    g->numVertices = vertices;
    for(int i = 0; i < vertices; i++){
        g->adjList[i] = NULL;
    }
    return g;
}

Node* createNode(int vertex){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Graph* g, int src, int des){
    Node* newNode = createNode(des);
    newNode->next = g->adjList[src];
    g->adjList[src] = newNode;
}

void printAdjList(Graph* g){
    if(g->numVertices == 0) return;
    for(int i = 0; i < g->numVertices; i++){
        printf("%d: ", i);
        Node* currrent = g->adjList[i];
        while(currrent){
            printf("%d -> ", currrent->vertex);
            currrent = currrent->next;
        }
        printf("NULL\n");
    }
}


int main(){
    int n;
    printf("Nhap so dinh: ");
    scanf("%d", &n);
    int** matrix = (int**)malloc(n*sizeof(int*));
    for(int i = 0; i < n; i++) matrix[i] = (int*)malloc(n*sizeof(int));
    printf("Nhap ma tran ke:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    Graph* g = initGraph(n);
    // Chuyen doi sang danh sach ke
    for(int i = 0; i < n; i++){
        for(int j = n-1; j >= 0; j--){
            if(matrix[i][j] == 1) addEdge(g, i, j);
        }
    }
    printAdjList(g);
    return 0;
}