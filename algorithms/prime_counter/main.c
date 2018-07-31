#include <stdio.h>
#include <stdlib.h>

static int primes[] = {2, 3, 5, 7, 11, 13, 17, 19};

unsigned long encode(int *, int);
void decode(unsigned long);

int main(int argc, char *argv[]){
	int input, i, j;
	scanf("%d", &input);
	int *ints = (int *) calloc(input, sizeof(int));
	for(i = 0; i < input; i++ ) {
		scanf("%d", &j);
		ints[i] = j;
	}
	unsigned long encoding = encode(ints, input);
	printf("%lu\n", encoding);
	decode(encoding);
}

unsigned long encode(int *ints, int size) {
	int i, p = 0, counter = 0;
	unsigned long encoding = 1l;
	while (size--) {
		printf("%d\n", *ints);
		i = *ints;
		while(i--) {
			encoding *= primes[p];		
		} 
		p++;
		ints++;
	}
	return encoding;
}

void decode (unsigned long i) {
	int counter = 0, p = 0;
	while (i > 1) {
		while (!(i % primes[p])) {
			counter++;
			i /= primes[p];
		}
		printf("%d\n", counter);
		counter = 0;
		p++;
	}
}
