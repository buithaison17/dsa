#include<stdio.h>
#include<string.h>
#include <ctype.h>

struct Students
{
    int id;
    char name[100];
    int age;
};

void toLowerCase(char str[]){
    for(int i = 0; i < strlen(str); i++){
        str[i] = tolower(str[i]);
    }
}

int main(){
    struct Students students[] = {
        {1, "Alice", 20},
        {2, "Bob", 21},
        {3, "Charlie", 22},
        {4, "David", 20},
        {5, "Eva", 23}
    };

    char nameSearch[100];
    printf("Nhập tên phần tử muốn tìm kiếm: ");
    fgets(nameSearch, 100, stdin);
    nameSearch[strcspn(nameSearch, "\n")] =  '\0';
    toLowerCase(nameSearch);
    for(int i = 0; i < 5; i++){
        char fullName[100];
        strcpy(fullName, students[i].name);
        toLowerCase(nameSearch);
        toLowerCase(fullName);
        if(strstr(fullName, nameSearch) != NULL){
            printf("ID:%d\nName: %s\nAge:%d\n\n", students[i].id, students[i].name, students[i].age);
        }
    }
    return 0;
}