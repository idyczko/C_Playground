#include <stdio.h>

int atoi(char *);

int main() {
  char c[] = "1234";
  char *ptr = c;
  int a = atoi(c);
  int b = atoi(c + 1);
  *c = '3';
  *++ptr = 'A';
  printf("PTR: %s\n", ptr);
  *ptr++ = *ptr=='A'?'B':'C';
  printf("%d\t%d\n", a, b);
  printf("%c, %s, %s\n", *c, c, ptr);
  return 0;
}
