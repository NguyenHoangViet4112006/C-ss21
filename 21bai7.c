#include<stdio.h>
struct Student{
    int id;
    char name[50];
    int age;
};
int main(){
    FILE *file;
    int numStudents;
    struct Student student;
    file = fopen("students.txt", "w");
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &numStudents);
    getchar();
    for (int i = 0; i < numStudents; i++) {
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &student.id);
        getchar();
        printf("Name: ");
        fgets(student.name, sizeof(student.name), stdin);
        printf("Age: ");
        scanf("%d", &student.age);
        getchar();
        fprintf(file, "%d %s %d\n", student.id, student.name, student.age);
    }
    fclose(file);
    return 0;
}

