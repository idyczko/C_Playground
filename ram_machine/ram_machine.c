#include <stdio.h>
#define INSTRUCTIONS_NUMBER 11
#define INITIAL_MEMORY 10

int *MEMORY;
int *INPUT;
int PROGRAM_COUNTER;

int atoi(char *);
void *calloc(size_t, size_t);
int strcmp(char *, char *);
void free(void *);

struct node{
  struct node *next;
  char *name;
  int (*instruction)(char *);
} *INSTRUCTIONS[INSTRUCTIONS_NUMBER];

int insert(struct node nd);
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

int init_ram(int input[]) {
  MEMORY = (int*) calloc(sizeof(int), INITIAL_MEMORY);
  INPUT = input;
  PROGRAM_COUNTER = 1;

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

  insert(read_node);
  insert(store_node);
  insert(load_node);
  insert(add_node);
  insert(sub_node);
  insert(half_node);
  insert(jump_node);
  insert(jpos_node);
  insert(jneg_node);
  insert(jzero_node);
  insert(halt_node);
  return 0;
}

int run(char **program) {
  char *instr;
  while((instr = *program++) != NULL)
    if(get(instr)() < 0)
      break;

  int result = MEMORY[0];
  free(MEMORY);
  return result;
}

int insert(struct node nd) {
    struct node *ptr = INSTRUCTIONS[hash(nd.name)];
    if(ptr == NULL) {
      INSTRUCTIONS[hash(nd.name)] = &nd;
    }
    while(ptr->next != NULL)
      ptr = ptr->next;
    ptr->next = &nd;
}

int (*get(char *name))() {
    struct node *ptr = INSTRUCTIONS[hash(name)];
    while(strcmp(ptr->name, name) != 0)
      ptr = ptr->next;
    return ptr->instruction;
}

int hash(char *name) {
  int sum;
  while(*name != '\0') {
    sum += *name++;
  }
  return sum % INSTRUCTIONS_NUMBER;
}

int read(char *operand) {
  if (*operand == '^')
    MEMORY[0] = INPUT[MEMORY[atoi(++operand)]];
  else
    MEMORY[0] = INPUT[atoi(++operand)];
  return 0;
};

int store(char *operand) {
  if (*operand == '^')
    MEMORY[MEMORY[atoi(++operand)]] = MEMORY[0];
  else
    MEMORY[atoi(++operand)] = MEMORY[0];
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
    MEMORY[0] += MEMORY[atoi(++operand)];
  return 0;
};

int sub(char *operand) {
  if (*operand == '^')
    MEMORY[0] -= MEMORY[MEMORY[atoi(++operand)]];
  else if (*operand == '=')
    MEMORY[0] -= atoi(++operand);
  else
    MEMORY[0] -= MEMORY[atoi(++operand)];
  return 0;
};

int half(char *operand) {
  MEMORY[0] /= 2;
  return 0;
};

int jump(char *operand) {
  PROGRAM_COUNTER = atoi(operand);
  return 0;
};

int jpos(char *operand) {
  if(MEMORY[0] > 0)
    PROGRAM_COUNTER = atoi(operand);
  return 0;
};

int jneg(char *operand) {
  if(MEMORY[0] < 0)
    PROGRAM_COUNTER = atoi(operand);
  return 0;
};

int jzero(char *operand) {
  if(MEMORY[0] == 0)
    PROGRAM_COUNTER = atoi(operand);
  return 0;
};

int halt(char *operand) {
  PROGRAM_COUNTER = 1;
  return -1;
};
