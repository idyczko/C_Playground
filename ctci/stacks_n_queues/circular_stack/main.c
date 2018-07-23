#include <stdio.h>
#include "stack.h"

int main(int argc, char* argv[]) {
	initialize_stacks(3, 10);
	push(0, 1);
	push(0, 2);
	push(0, 3);
	push(0, 4);
	push(0, 5);
	push(0, 6);
	push(0, 7);
	push(0, 8);
	push(0, 9);
	push(0, 10);
	push(0, 11);
	push(0, 12);
	push(0, 13);
	push(0, 14);
	push(0, 15);
	push(0, 16);
	pop(0);
	pop(0);
	pop(0);
	push(1, 4);
	push(1, 5);
	push(1, 6);
	push(2, 7);
	push(2, 8);
	push(2, 9);
	push(2, 10);
	push(2, 11);
	printf("There you go: %d, %d, %d, %d, %d\n", pop(0), top(0), top(0), pop(0), top(0));
	printf("There you go: %d\n",top(0));
	printf("There you go: %d, %d, %d, %d, %d\n", pop(2), top(2), top(2), pop(2), top(2));
	printf("There you go: %d\n",top(2));
	printf("There you go: %d, %d, %d, %d, %d\n", pop(1), top(1), top(1), pop(1), top(1));
	printf("There you go: %d\n",top(1));
	return 0;
}
