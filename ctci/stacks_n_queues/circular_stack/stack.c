#include "stack.h"

void *calloc(size_t, size_t);

struct stack_info {
	int start_index;
	int size;
	int capacity;
};

static int *stack_memory;
static int stack_size;
static int stack_number;
static struct stack_info *info;

int *illegal_action() {
	return stack_memory;
}

void initialize_stacks(int stacks, size_t size) {
	stack_number = stacks;
	stack_size = stacks*size;
	stack_memory = calloc(stacks*size, sizeof(int));
	info = calloc(stacks, sizeof(struct stack_info));
	auto int i;
	for (i = 0; i < stacks; i++) {
		info[i].size = 0;
		info[i].capacity = size;
		info[i].start_index = i*size;
	}
}

void free_stacks() {
	free(stack_memory);
	free(info);
	stack_size = stack_number = 0;
}

int get_index_within_range(int index) {
	return ((index % stack_size) + stack_size) % stack_size;
}

int get_top_index(int stack) {
	return (info[stack].start_index + info[stack].size - 1) % stack_size;
}

int get_next_index(int stack) {
	return (get_top_index(stack) + 1) % stack_size;
}

int is_empty(int stack) {
	return info[stack].size == 0;
}

int pop(int stack) {
	const int top_index = get_top_index(stack);
	auto int result = stack_memory[top_index];
	stack_memory[top_index] = 0;
	info[stack].size--;
	return result;
}

int top(int stack) {
	return stack_memory[get_top_index(stack)];
}

void shift_elements(int stack) {
	auto int index;
	for (index = get_next_index(stack); index != info[stack].start_index; index = get_index_within_range(index - 1)) {
		stack_memory[index] = stack_memory[index - 1];
	}
	info[stack].start_index = (info[stack].start_index + 1) % stack_size;
	info[stack].capacity--;
}

int shift_stack_recursively(int stack, int depth) {
	if (info[stack].size < info[stack].capacity) {
		shift_elements(stack);
		stack_memory[info[stack].start_index] = 0;
		return 1;
	}

	if (depth > 0)
		return shift_stack_recursively((stack + 1) % stack_number, --depth);
	return 0;
}

int shift_stack(int stack) {
	return shift_stack_recursively(stack, stack_number);
}

void push(int stack, int value) {
	if(info[stack].size < info[stack].capacity) {
		stack_memory[get_next_index(stack)] = value;
		info[stack].size++;
	} else if (shift_stack(stack + 1 % stack_number)) {
		info[stack].capacity++;	
		stack_memory[get_next_index(stack)] = value;
		info[stack].size++;
	}
}
