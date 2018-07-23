#include "min_stack.h"

void *calloc(size_t, size_t);

struct element {
	int value;
	int substack_min;
};

static struct element *stack;
static int size = 0;
static int capacity = DEFAULT_SIZE;

void init_stack() {
	stack = (struct element*) calloc(DEFAULT_SIZE, sizeof(struct element));
}

void push(int value) {
	if (size < capacity) {
		stack[size].value = value;
		stack[size].substack_min = size == 0 ? value : value < stack[size - 1].substack_min ? value : stack[size - 1].substack_min;
		size++;
	}
}

int pop() {
	return stack[--size].value;
}

int top() {
	return stack[size - 1].value;
}

int min() {
	return stack[size - 1].substack_min;
}

int is_empty() {
	return size == 0;
}
