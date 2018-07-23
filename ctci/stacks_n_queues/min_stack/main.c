#include <stdio.h>
#include "min_stack.h"

int main(int argc, char *argv[]) {
	init_stack();
	push(1);
	push(2);
	push(3);
	push(2);
	push(4);
	push(0);
	push(-1);
	push(10);
	printf("%d\n", pop());
	printf("%d\n", min());
	printf("%d\n", pop());
	printf("%d\n", min());
	printf("%d\n", pop());
	printf("%d\n", min());
}
