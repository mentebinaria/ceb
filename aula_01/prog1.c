#include <stdio.h>
#include <string.h>


void func(void){

	int n = 10;
	int n2 = 11;
	int sum = n + n2;
	char *a = "AAAAAAAA";
	char *b = "BBBBBBBB";
	char d[80];
	char e[80];
	strcpy(d,a);
	strcpy(e,b);	
}

int main(int arg, char *argv[]){

	char c[40];
	
	strcpy(c,argv[1]);

	printf("Escrevemos: %s\n", c);

	func();

	return 0;

}
