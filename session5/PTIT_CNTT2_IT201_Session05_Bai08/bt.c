#include<stdio.h>
#include<ctype.h>
#include<string.h>

int convertStrToParseInt(char str[], int length){
    if(length == 1) return str[0] - '0';
    return convertStrToParseInt(str, length - 1) * 10 + str[length - 1] - '0';
}

int main(){
    char str[100];
    printf("Nhập chuỗi: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';
    int startIndex = 0, isNegative = 0, check = 0;
    if(str[0] == '-'){
        startIndex = 1;
        isNegative = 1;
    }
    for(int i = startIndex; i < strlen(str); i++){
        if(!isdigit(str[i])){
            printf("Input không hợp lệ");
            check = 1;
            break;
        }
    }
    if(!check){
        int result = convertStrToParseInt(str + startIndex, strlen(str) - startIndex);
        isNegative ? result = -result : result;
        printf("%d", result);
    }
    return 0;
}