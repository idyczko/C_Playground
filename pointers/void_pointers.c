#include <stdio.h>

int function(void *pointer);

int main() {
  char *str = "String hue hue hue.";
  function(str);
  return 0;
}

/*
*Pointers can be cast to void pointers and back again without data loss.
*Check this out.
*/
int function(void *pointer){
  char *pt = pointer;
  printf("%s", pt);
  return 0;
}
