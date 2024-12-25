#include <stdio.h>
int main() {
    FILE *file;
    int soDong;
    char line[256];
    file = fopen("bt05.txt", "w");
    printf("Nhap so dong: ");
    scanf("%d", &soDong);
    getchar();
    for (int i = 0; i <soDong; i++){
        printf("Nhap noi dung dong thu %d: ", i + 1);
        fgets(line, sizeof(line), stdin);
        fprintf(file, "%s", line);
    }  
    fclose(file);
    file = fopen("bt05.txt", "r");
    printf("\nNoi dung file bt05.txt:\n");
    while (fgets(line, sizeof(line), file) != NULL){
    	printf("%s", line);
    }
	fclose(file);
    return 0;
}

