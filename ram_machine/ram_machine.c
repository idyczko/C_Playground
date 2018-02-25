#include <stdio.h>
#define INSTRUCTIONS_NUMBER 11
#define INITIAL_MEMORY 10

static int *MEMORY;

void *calloc(size_t, size_t);

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

int main() {
  MEMORY = (int*) calloc(sizeof(int), INITIAL_MEMORY);
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
  return 0;
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

int hash(char *name) {
  int sum;
  while(*name != '\0') {
    sum += *name++;
  }
  return sum % INSTRUCTIONS_NUMBER;
}

int read(char *operand) {
  return 0;
};
int store(char *operand) {
  return 0;
};
int load(char *operand) {
  return 0;
};
int add(char *operand) {
  return 0;
};
int sub(char *operand) {
  return 0;
};
int half(char *operand) {
  return 0;
};
int jump(char *operand) {
  return 0;
};
int jpos(char *operand) {
  return 0;
};
int jneg(char *operand) {
  return 0;
};
int jzero(char *operand) {
  return 0;
};
int halt(char *operand) {
  return 0;
};
