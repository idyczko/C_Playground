#include <stdio.h>
#include "ram_machine.h"

int main(){
  int args[] = {10, 12};
  init_ram(args);
  struct instruction program[] = {{"READ", "1"},
                                  {"STORE", "1"},
                                  {"READ", "2"},
                                  {"ADD", "1"},
                                  {"HALF", NULL},
                                  {"HALT", NULL}};
  printf("Result: %d\n", run(program));
  return 0;
}
