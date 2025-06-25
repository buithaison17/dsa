#include<stdio.h>
#include<stdlib.h>

struct Students
{
    int id;
    char name[100];
    int age;
};


int main(){
    struct Students students[] = {
        {1, "Alice", 20},
        {2, "Bob", 21},
        {4, "Charlie", 22},
        {4, "David", 20},
        {5, "Eva", 23}
    };
    int idSearch, index = -1;
    printf("Nhập ID cần tìm kiếm: ");
    scanf("%d", &idSearch);
    for(int i = 0; i < 5; i++){
        if(idSearch == students[i].id){
            index = i;
        }
    }
    index != -1 ? printf("ID: %d\nName: %s\nAge: %d", students[index].id, students[index].name, students[index].age) :
    printf("Sinh viên không tồn tại");
    return 0;
}