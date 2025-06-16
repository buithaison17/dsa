#include<stdio.h>
#include<string.h>

void bubbleSort(char* str){
    for(int i = 0; i < strlen(str); i++){
        for(int j = 0; j < strlen(str) - i - 1; j++){
            if(str[j] > str[j+1]){
                char temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
            }
        }
    }
}

void isPermutation(char* str1, char* str2){
    if(strlen(str1) != strlen(str2)){
        printf("false");
        return;
    }
    
    bubbleSort(str1);
    bubbleSort(str2);

    if(strcmp(str1, str2) == 0){
        printf("true");
    }
    else{
        printf("false");
    }
}

// Độ phức tạp thời gian của cách này là O(n^2);

int main(){
    char str1[10] = "world";
    char str2[10] = "olhel";
    isPermutation(str1, str2);
    return 0;

}