#include "multi_stack.h"

static int **multi_stack;
static int *size;
static int current;

void init() {
	current = 0;
	*size = 0;
	**multistack = (int **) calloc(1, sizeof(int *);
	multistack[0] = (int *) calloc(MAX_CAPACITY, sizeof(int));
}

void free() {
	auto int i;
	while (i < current)
		free(multistack[i++]);
	free(multistack);
	current = 0;
	*size = 0;
}
