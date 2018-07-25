#include "multi_stack.h"

static int **multi_stack;
static int *size;
static int stacks;
static int current;

void init() {
	stacks = INIT_STACKS;
	current = 0;
	size = (int *) calloc(INIT_STACKS, sizeof(int));
	auto int i;
	for (i = 0; i < INIT_STACKS; i++)
		size[i] = 0;
	multi_stack = (int **) calloc(INIT_STACKS, sizeof(int *));
	for (i = 0; i < INIT_STACKS; i++)
		multi_stack[i] = (int *) calloc(MAX_CAPACITY, sizeof(int));
}

void free_stack() {
	auto int i;
	for (i = 0; i < INIT_STACKS; i++)
		free(multi_stack[i]);
	free(multi_stack);
	current = 0;
	stacks = 0;
	free(size);
}

void expand_stack() {
	int **temp_stack = (int **) calloc(stacks*GROWTH_FACTOR, sizeof(int *));
	int *temp_size = (int *) calloc(stacks*GROWTH_FACTOR, sizeof(int));
	int i, j;
	for (i = 0; i < stacks * GROWTH_FACTOR; i++) {
		temp_size[i] = i < stacks ? size[i] : 0;
		temp_stack[i] = (int *) calloc((i < stacks ? size[i] : MAX_CAPACITY), sizeof(int));
		if (i < stacks)
			for (j = 0; j < size[i]; i++)
				temp_stack[i][j] = multi_stack[i][j];
		free(multi_stack[i]);
	}
	free(multi_stack);
	free(size);
	size = temp_size;
	multi_stack = temp_stack;
	stacks *= GROWTH_FACTOR;
}

void push (int value) {
	if (size[current] < MAX_CAPACITY) {
		multi_stack[current][size[current]++] = value;
	} 
	
	if (stacks - 1 > current) {
		expand_stack();
	}
	multi_stack[++current][0] = value;
	size[current]++;
}

int top(int stack) {
	return size[stack] == 0 ? -404 : multi_stack[stack][size[stack] - 1];
}

int pop(int stack) {
	while(!size[stack] && stack > 0)
		stack--;
	return size[stack] == 0 ? -404 : multi_stack[stack][--size[stack]];
}

int is_empty() {
	int i = current;
	while(!size[i] && i > 0)
		i--;
	return size[i] == 0;
}

void print_diagnostics() {
	auto int i, j;
	printf("Stacks: \n", stacks);
	printf("Current: \n", current);
	printf("Sizes: \n");
	for (i = 0; i < stacks; i++) {
		printf("%d\t", size[i]);
	}
	for (j = MAX_CAPACITY - 1; j >= 0; j--) {
		for (i = 0; i < stacks; i++) {
			if (j < size[i])
				printf("%d\t", multi_stack[i][j]);
			else
				printf("\t");
		}
		printf("\n");
	}
}
