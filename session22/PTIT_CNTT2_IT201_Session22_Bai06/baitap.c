#include<stdio.h>
#include<stdlib.h>

void dfs(int** matrix, int vertex, int numVertices, int visited[]){
    if(numVertices == 0) return;
    printf("%d ", vertex);
    visited[vertex] = 1;
    for(int i = 0; i < numVertices; i++){
        if(matrix[vertex][i] == 1 && visited[i] == 0){
            dfs(matrix, i, numVertices, visited);
        }
    }
}

int main(){
    int v, n;
    printf("Nhap so dinh: ");
    scanf("%d", &v);
    printf("Nhap so canh: ");
    scanf("%d", &n);
    int **matrix = (int**)malloc(v*sizeof(int*));
    for(int i = 0; i < v; i++){
        matrix[i] = (int*)malloc(v*sizeof(int));
        for(int j = 0; j < v; j++) matrix[i][j] = 0;
    }
    int src, des;
    printf("Nhap cac canh:\n");
    for(int i = 0; i < n; i++){
        scanf("%d %d", &src, &des);
        matrix[src][des] = matrix[des][src] = 1;
    }
    int vertex;
    printf("Nhap dinh bat dau duyet: ");
    scanf("%d", &vertex);
    int visited[100] = {0};
    dfs(matrix, vertex, v, visited);
    return 0;
}