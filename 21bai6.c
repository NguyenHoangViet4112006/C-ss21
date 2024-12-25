#include<stdio.h>
int main() {
    FILE *fptr, *fptr2;
    char ch;
    fptr = fopen("bt01.txt", "r");
    fptr2 = fopen("bt06.txt", "w");
    while ((ch=fgetc(fptr)) !=EOF){
        fputc(ch, fptr2);
    }
    fclose(fptr);
    fclose(fptr2);
    return 0;
}

