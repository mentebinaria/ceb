#include <stdio.h>

void vuln(void){
	char buffer[80];
	puts("Feed me: ");
	gets(buffer);
}

int main(void){
	vuln();
}


