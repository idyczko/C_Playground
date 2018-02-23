#include <stdio.h>

int main(int argc, char *argv[]) {
  int atoi(char*);
  void *calloc(size_t, size_t);
  int arg = atoi(*++argv);
  int con = arg;
  int *array = (int *) calloc(sizeof(int), arg);

  do{
    array[con - arg] = con - arg;
  } while (--arg > 0);

  return 0;
}
