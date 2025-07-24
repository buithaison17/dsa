#include<stdio.h>
#include<stdlib.h>

int countVertex(int** matrix, int v, int k){
    int count = 0;
    for(int i = 0; i < v; i++){
        if(matrix[k][i] == 1) count++;
    }
    return count;
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
    int k;
    printf("Nhap dinhk muon kiem tra: ");
    scanf("%d", &k);
    int numVertices = countVertex(matrix, v, k);
    printf("So dinh ke voi dinh %d la: %d", k, numVertices);
    return 0;
}