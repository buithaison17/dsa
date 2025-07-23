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

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = data;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int data){
    Graph* newGraph = (Graph*)malloc(sizeof(Graph));
    newGraph->adjList = (Node**)malloc(sizeof(data*sizeof(Node*)));
    newGraph->numVertices = data;
    for(int i = 0; i < data; i++){
        newGraph->adjList[i] = NULL;
    }
    return newGraph;
}

void addEdge(Graph* graph, int src, int des){
    Node* newNode = createNode(des);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
    newNode = createNode(src);
    newNode->next = graph->adjList[des];
    graph->adjList[des] = newNode;
}

void printGraph(Graph* graph){
    for(int i = 0; i < graph->numVertices; i++){
        Node* current = graph->adjList[i];
        while(current){
            printf("%d -> ", current->vertex);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main(){
    Graph* graph = createGraph(3);
    addEdge(graph, 1, 2);
    printGraph(graph);
    return 0;
}