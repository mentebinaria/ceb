#include <stdio.h>


void vuln(void){

	char c[80];

	gets(c);

}

int main(void){

	vuln();


	return 0;

}
