#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void vuln()
{
  char buffer[64];
  unsigned int ret;

  puts("Diga alguma coisa: ");

  gets(buffer);

  ret = __builtin_return_address(0);
   

  if((ret &  0xff000000) ==  0xff000000) {
      printf("Voce sobrescreveu o endereco de retorno: (%p)\n", ret);
      _exit(1);
  }

  printf("Voce disse: %s\n", buffer);
}

int main(int argc, char **argv)
{

  vuln();

}
