#include<stdio.h>
int main(){
	FILE *fptr;
	fptr = fopen("C:\\New folder\\bt01.txt", "a");
	char myText[50];
	fgets(myText, 50, fptr);
	printf("Moi ban nhap mot chuoi bat ky: ");
	fgets(myText, sizeof(myText), stdin);
	fprintf(fptr, "%s", myText);
	fclose(fptr);
	return 0;
}
