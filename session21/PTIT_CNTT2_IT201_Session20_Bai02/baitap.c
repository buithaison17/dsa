#include<stdio.h>
#include<stdlib.h>
#define V 4

int matrix[V][V];

void addEdge(int src, int des){
    matrix[src][des] = matrix[des][src] = 1; 
}

void printMatrix(){
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 3);
    printMatrix();
    return 0;
}