#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isPalindrome(char str[], int left, int right){
    if(left >= right) return 1;
    if(str[left] != str[right]) return 0;
    return(str, left+1, right-1);
} 

int main(){
    char str[1000];
    printf("Nhập chuỗi của bạn: ");
    fgets(str, 1000, stdin);
    str[strcspn(str, "\n")] = '\0';
    if(isPalindrome(str, 0, strlen(str)-1)){
        printf("Palindrome valid");
    }
    else{
        printf("Palindrome invalid");
    }
    return 0;
}