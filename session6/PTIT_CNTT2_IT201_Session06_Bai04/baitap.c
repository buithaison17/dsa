#include<stdio.h>

int hanoi(int n, char from, char aux, char to){
    if(n == 1){
        printf("Di chuyển đĩa %d từ %c sang %c", n, from, to);
        return 0;
    }
    hanoi(n-1, from, to, aux);
    printf("\nDi chuyển đĩa %d từ %c sang %c\n", n, from, to);
    hanoi(n-1, aux, from, to);
}

int main(){
    int n;
    printf("Nhập số đĩa: ");
    scanf("%d", &n);
    n ? hanoi(n, 'A', 'B', 'C') : printf("Input không hợp lệ"); 
    return 0;
}