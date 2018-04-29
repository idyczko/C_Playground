#include <stdio.h>
#include "heap.h"

int main(int argc, char *argv[]) {
  int numbers[20] = {10, 12, 32, 123, 124, 121, 2, 3, 12, 21, 121, 1, 1212, 12, 1, 0563, 39492, 2, 3, 23};
  struct binary_table_heap h = {0, 100, (int *) calloc(100, sizeof(int))};
  int i = 0;
  for(i; i<20;i++)
    add(&h, numbers[i]);

  printf_heap(h);
  pop(&h);
  add(&h, 0);
  printf_heap(h);
  for(i=0; i<20;i++)
    numbers[i] = pop(&h);
  for(i=0; i<20;i++)
    printf("%d ", numbers[i]);

  return 0;
}
