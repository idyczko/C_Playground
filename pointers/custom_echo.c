#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: echo #arg#.");
  }
  
  char *pt;
  while((pt = *++argv) != 0)
    printf("%s ", pt);
  printf("\n");
  return 0;
}
