#include "ram_machine.h"

int *MEMORY;
int *INPUT;
int PROGRAM_COUNTER = 0;

int atoi(char *);
void *calloc(size_t, size_t);
int strcmp(char *, char *);
void free(void *);

int insert(struct node *nd);
int (* get(char *name))();
int hash(char *);

int read(char *);
int store(char *);
int load(char *);
int add(char *);
int sub(char *);
int half(char *);
int jump(char *);
int jpos(char *);
int jneg(char *);
int jzero(char *);
int halt(char *);

struct node read_node = {NULL, "READ", &read};
struct node store_node = {NULL, "STORE", &store};
struct node load_node = {NULL, "LOAD", &load};
struct node add_node = {NULL, "ADD", &add};
struct node sub_node = {NULL, "SUB", &sub};
struct node half_node = {NULL, "HALF", &half};
struct node jump_node = {NULL, "JUMP", &jump};
struct node jpos_node = {NULL, "JPOS", &jpos};
struct node jneg_node = {NULL, "JNEG", &jneg};
struct node jzero_node = {NULL, "JZERO", &jzero};
struct node halt_node = {NULL, "HALT", &halt};

int init_ram(int input[]) {
  MEMORY = (int*) calloc(sizeof(int), INITIAL_MEMORY);
  int m;
  for(m = 0; m < INITIAL_MEMORY; MEMORY[m++] = 0);

  INPUT = input;
  PROGRAM_COUNTER = 0;

  insert(&read_node);
  insert(&store_node);
  insert(&load_node);
  insert(&add_node);
  insert(&sub_node);
  insert(&half_node);
  insert(&jump_node);
  insert(&jpos_node);
  insert(&jneg_node);
  insert(&jzero_node);
  insert(&halt_node);

  return 0;
}

int run(struct instruction *program) {
  while(1) {
    printf("Executing instruction %d: %s\nOperand: %s\nRegister beforehand: %d\n",
      PROGRAM_COUNTER, program[PROGRAM_COUNTER].name, program[PROGRAM_COUNTER].operand, MEMORY[0]);
    if(get(program[PROGRAM_COUNTER].name)(program[PROGRAM_COUNTER].operand) < 0)
      break;
    printf("Register afterwards: %d\n\n", MEMORY[0]);
    PROGRAM_COUNTER++;
  }

  int result = MEMORY[0];
  free(MEMORY);
  return result;
}

int insert(struct node *nd) {
    int hsh = hash(nd->name);
    struct node *ptr = INSTRUCTIONS[hsh];
    if(ptr == NULL) {
      INSTRUCTIONS[hsh] = nd;
      return 0;
    }

    while((ptr = ptr->next) != NULL);
    ptr = nd;
    return 0;
}

int (*get(char *name))() {
    struct node *ptr = INSTRUCTIONS[hash(name)];
    for(; strcmp(ptr->name, name) != 0; ptr = ptr->next);
    return ptr->instruction;
}

int hash(char *name) {
  int sum;
  for(sum = 0; *name != '\0'; sum += *name++);
  return sum % INSTRUCTIONS_NUMBER;
}

int read(char *operand) {
  if (*operand == '^')
    MEMORY[0] = INPUT[MEMORY[atoi(++operand) - 1]];
  else
    MEMORY[0] = INPUT[atoi(operand) - 1];
  return 0;
};

int store(char *operand) {
  if (*operand == '^')
    MEMORY[MEMORY[atoi(++operand)]] = MEMORY[0];
  else
    MEMORY[atoi(operand)] = MEMORY[0];
  return 0;
};

int load(char *operand) {
  if (*operand == '^')
    MEMORY[0] = MEMORY[MEMORY[atoi(++operand)]];
  else if (*operand == '=')
    MEMORY[0] = atoi(++operand);
  else
    MEMORY[0] = MEMORY[atoi(++operand)];
  return 0;
};

int add(char *operand) {
  if (*operand == '^')
    MEMORY[0] += MEMORY[MEMORY[atoi(++operand)]];
  else if (*operand == '=')
    MEMORY[0] += atoi(++operand);
  else
    MEMORY[0] += MEMORY[atoi(operand)];
  return 0;
};

int sub(char *operand) {
  if (*operand == '^')
    MEMORY[0] -= MEMORY[MEMORY[atoi(++operand)]];
  else if (*operand == '=')
    MEMORY[0] -= atoi(++operand);
  else
    MEMORY[0] -= MEMORY[atoi(operand)];
  return 0;
};

int half(char *operand) {
  MEMORY[0] /= 2;
  return 0;
};

int jump(char *operand) {
  PROGRAM_COUNTER = atoi(operand) - 1;
  return 0;
};

int jpos(char *operand) {
  if(MEMORY[0] > 0)
    PROGRAM_COUNTER = atoi(operand) - 1;
  return 0;
};

int jneg(char *operand) {
  if(MEMORY[0] < 0)
    PROGRAM_COUNTER = atoi(operand) - 1;
  return 0;
};

int jzero(char *operand) {
  if(MEMORY[0] == 0)
    PROGRAM_COUNTER = atoi(operand) - 1;
  return 0;
};

int halt(char *operand) {
  PROGRAM_COUNTER = 0;
  return -1;
};
