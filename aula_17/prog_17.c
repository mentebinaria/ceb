#include <stdio.h>
 
void vuln() {
    char buffer[160];
 
    puts("What is your mame?");
    gets(buffer);

    printf("Welcome: ");
    printf(buffer);

	  puts("\nSay Something:  ");
		gets(buffer);
}
 
int main() {
    vuln();
 
    puts("Not this time");
 
    return 1;
}
