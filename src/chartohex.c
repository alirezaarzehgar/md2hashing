#include <stdio.h>
#include "chartohex.h"


void ctoh(char data[], char *string){
  printf("%s = ", string);
  char k;
  int count = 0;

  for(count = 0; count < 16; count++){
    k = data[count];
    printf("%X", k & 0xff);
  }
  printf("\n");
}
