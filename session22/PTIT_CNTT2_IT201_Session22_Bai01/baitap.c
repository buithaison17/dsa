#include<stdio.h>
#include<stdlib.h>

void addEdge(int** matrix, int src, int des){
    matrix[src][des] = matrix[des][src] = 1;
}

void printMatrix(int** matrix, int v){
    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int v, n, src, des;
    printf("Nhap so dinh: ");
    scanf("%d", &v);
    int **matrix = (int**)malloc(v*sizeof(int*));
    for(int i = 0; i < v; i++){
        matrix[i] = (int*)malloc(v*sizeof(int));
        for(int j = 0; j < v; j++){
            matrix[i][j] = 0;
        }
    }
    for(int i = 0; i < v; i++){
        printf("Nhap la luot node 1 va 2: ");
        scanf("%d %d", &src, &des);
        addEdge(matrix, src, des);
    }
    printMatrix(matrix, v);
    for(int i = 0; i < v; i++){
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}