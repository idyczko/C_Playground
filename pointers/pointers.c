#include <stdio.h>

int main() {
  int i = 10, j;
  int* tab[] = {&i, &i ,&i};
  i++;
  for(j = 0; j < 3; j++) {
    printf("%d\n", *tab[j]);
  }
  (*tab[2])++;
  for(j = 0; j < 3; j++) {
    printf("%d\n", *tab[j]);
  }
  return 0;
}
