#include<stdio.h>

struct Sinhvien{
    int id;
    char name[50];
    int age;
};
int main(){
    FILE *file;
    struct Sinhvien sv[100];
    int i = 0;
    file = fopen("students.txt", "r");
    while (fscanf(file, "%d %s %d", &sv[i].id, sv[i].name, &sv[i].age) != EOF){
        i++;
    }
    fclose(file);
    printf("Thong tin cac sinh vien:\n");
    for (int j = 0; j < i; j++){
        printf("ID: %d, Name: %s, Age: %d\n", sv[j].id, sv[j].name, sv[j].age);
    }

    return 0;
}
