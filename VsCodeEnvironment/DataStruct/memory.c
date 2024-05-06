#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct Student student;

struct Student
{
    int age;
    char name[100];
    int id;
};

student * CreateStudent();
void ShowStudent(student *);

int main(int argc, char const *argv[])
{
    student * stu = CreateStudent();
    ShowStudent(stu);
    return 0;
}

student * CreateStudent()
{
    student * stu = (student *)malloc(sizeof(student));
    stu->age = 18;
    stu->id = 10000;
    strcpy(stu->name, "wangfeijian");
    return stu;
}

void ShowStudent(student * stu)
{
    printf("%d %s %d", stu->id, stu->name, stu->age);
}