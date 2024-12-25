#include<stdio.h>
int main(){
	FILE *fptr;
	fptr = fopen("C:\\New folder\\bt01.txt", "w");
	char myText[50];
	fgets(myText, 50, fptr);
	printf("Moi ban nhap mot chuoi bat ky: ");
	fgets(myText, sizeof(myText), stdin);
	fprintf(fptr, "%s", myText);
	printf("Ky tu dau tien trong file la: %c", myText);
	fclose(fptr);
	return 0;
}

