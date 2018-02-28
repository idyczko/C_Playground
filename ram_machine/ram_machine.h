#ifndef RAM_MACHINE
#define RAM_MACHINE
#include <stdio.h>
#define INSTRUCTIONS_NUMBER 11
#define INITIAL_MEMORY 16

struct node{
  struct node *next;
  char *name;
  int (*instruction)(char *);
} *INSTRUCTIONS[INSTRUCTIONS_NUMBER];

struct instruction{
  char *name;
  char *operand;
};

int init_ram(int[]);
int run(struct instruction*);

#endif
