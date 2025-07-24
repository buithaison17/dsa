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
    Graph* newGraph = (Graph*)malloc(sizeof(Graph));
    newGraph->adjList = (Node**)malloc(vertices*sizeof(Node*));
    newGraph->numVertices = vertices;
    for(int i = 0; i < vertices; i++){
        newGraph->adjList[i] = NULL;
    }
    return newGraph;
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
    newNode = createNode(src);
    newNode->next = g->adjList[des];
    g->adjList[des] = newNode;
}

void printGraph(Graph* g){
    if(g->numVertices == 0) return;
    for(int i = 0; i < g->numVertices; i++){
        Node* current = g->adjList[i];
        printf("%d: ", i);
        while(current){
            printf("%d ", current->vertex);
            current = current->next;
        }
        printf("\n");
    }
}

int main(){
    int v, src, des;
    printf("Nhap so dinh: ");
    scanf("%d", &v);
    Graph* graph = initGraph(v);
    for(int i = 0; i <= v; i++){
        printf("Nhap lan luot tung canh: ");
        scanf("%d %d", &src, &des);
        addEdge(graph, src, des);
    }
    printGraph(graph);
    return 0;
}