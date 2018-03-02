#include <stdio.h>
#include <string.h>
#include "ram_machine.h"

struct instruction *program;

int isspace(int);

void *calloc(size_t, size_t);
void *malloc(size_t);
void free(void *);
int atoi(char *);
void read_program(char *);

int main(int argc, char *argv[]){
  char **input = argv + 2;
  int *args = calloc(argc - 2, sizeof(int));
  int *ptr = args;
  while(*input != NULL)
    *ptr++ = atoi(*input++);
  init_ram(args);
  read_program(argv[1]);
  printf("Result: %d\n", run(program));
  free(program);
  free(args);
  return 0;
}

void read_program(char *fileName) {
  FILE *fptr;
  char *line = NULL;
  struct instruction *ptr;
  size_t read, len = 0;
  int leng = 0;

  fptr = fopen(fileName, "r");
  if(fptr == NULL)
    return;

  if((read  = getline(&line, &len, fptr)) == -1)
    return;

  int lines = atoi(line);
  program = calloc(lines, sizeof(struct instruction));
  int i = 0;
  while ((read = getline(&line, &len, fptr)) != -1) {
        ptr = (struct instruction *) malloc(sizeof(struct instruction));
        leng = 0;
        while(!isspace(*(line + leng++)));
        for(leng = 0; !isspace(*(line + leng++)););
        ptr->name = (char *) calloc(leng, sizeof(char));
        strncpy(ptr->name, line, leng -1);
        line+=leng;
        for(leng = 0; !isspace(*(line + leng++)););
        ptr->operand = (char *) calloc(leng, sizeof(char));
        strncpy(ptr->operand, line, leng-1);
        program[i++] = *ptr;
  }

  fclose(fptr);
}
