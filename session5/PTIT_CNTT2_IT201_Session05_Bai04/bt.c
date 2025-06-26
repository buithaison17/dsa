#include<stdio.h>

int calculateSum(int firstNum, int secondNum){
    if(secondNum == firstNum) return firstNum;
    return secondNum + calculateSum(firstNum ,secondNum - 1);
}

int main(){
    int firstNum, secondNum;
    printf("Nhập số thứ nhất: ");
    scanf("%d", &firstNum);
    printf("Nhập số thứ hai: ");
    scanf("%d", &secondNum);
    if(firstNum > 0 && secondNum > 0 && firstNum < secondNum){
        int result = calculateSum(firstNum, secondNum);
        printf("%d", result);
    }
    else{
        printf("Không hợp lệ");
    }
    return 0;
}