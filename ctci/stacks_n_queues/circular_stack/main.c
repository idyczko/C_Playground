#include <stdio.h>
#include "stack.h"

int main(int argc, char* argv[]) {
	initialize_stacks(3, 10);
	push(0, 1);
	push(0, 2);
	push(0, 3);
	push(1, 4);
	push(1, 5);
	push(1, 6);
	push(2, 7);
	push(2, 8);
	push(2, 9);
	printf("There you go: %d, %d, %d, %d, %d\n", pop(0), top(0), top(0), pop(0), top(0));
	printf("There you go: %d\n",top(0));
	printf("There you go: %d\n",top(0));
	printf("There you go: %d\n",top(0));
	return 0;
}
