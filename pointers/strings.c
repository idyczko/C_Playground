#include <stdio.h>

int atoi(char *);

int main() {
  char *c = "1234";
  int a = atoi(c);
  int b = atoi(++c);
  printf("%d\t%d\n", a, b);
  return 0;
}
