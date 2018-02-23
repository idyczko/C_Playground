#include <stdio.h>

void *calloc(size_t, size_t);

static const int INITIAL_MEMORY = 10;
static int *MEMORY;
int (* INSTRUCTIONS[10])();

int main() {
  MEMORY = (int*) calloc(sizeof(int), INITIAL_MEMORY);
}
