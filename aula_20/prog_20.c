#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){

       char c[40];

       strcpy(c, argv[1]);

       printf("You Wrote: %s\n", c);

       return 0;

}

