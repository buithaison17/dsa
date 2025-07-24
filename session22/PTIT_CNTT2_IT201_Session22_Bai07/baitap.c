#include<stdio.h>
#include<stdlib.h>

int queue[100];
int front = -1, rear = -1;

void enqueue(int vertex){
    if(front == -1){
        front++;
        rear++;
    }
    else{
        rear++;
    }
    queue[rear] = vertex;
}

int dequeue(){
    if(front == -1) return -1;
    int temp = queue[front];
    if(front == rear){
        front = rear = -1;
    }
    else{
        front++;
    }
    return temp;
}

void bfs(int** matrix, int startVertex, int v){
    if(v == 0) return;
    int visited[100] = {0};
    printf("%d ", startVertex);
    enqueue(startVertex);
    visited[startVertex] = 1;
    while(front != -1){
        int vertex = dequeue();
        for(int i = 0; i < v; i++){
            if(matrix[vertex][i] == 1 && visited[i] == 0){
                printf("%d ", i);
                visited[i] = 1;
                enqueue(i);
            }
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
    bfs(matrix, 0, v);
    return 0;
}