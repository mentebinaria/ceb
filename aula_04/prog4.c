#include <stdio.h>
#include <string.h>


void vuln(void){

	char c[40];
	
	puts("Me alimente: ");

	gets(c);

	printf("Vc escreveu: %s\n", c);

}

int main(void){

	vuln();

	return 0; 

}
