#include<stdio.h>
#include<string.h>

void bubbleSort(char str[]){
    for(int i = 0; i < strlen(str) - 1; i++){
        for(int j = 0; j < strlen(str) - i - 1; j++){
            if(str[j] > str[j+1]){
                int temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
            }
        }
    }
}

int main(){
    char str[100];
    printf("Input: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';
    printf("before: %s", str);
    bubbleSort(str);
    printf("\nafter: %s", str);
    return 0;
}