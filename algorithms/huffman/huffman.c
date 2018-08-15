#include "huffman.h"

struct node {
	char *group;
	int ocurrences;
	node *left;
	node *right;
};

struct dictionary {
	node *top_node;
};

static struct dictionary *dict;

char *compress(char *text) {
	struct node *heap;
	heap = (struct node *) calloc(strlen(text), sizeof(struct node *));
	
}

char *decompress(char *compressed) {

}

void print_dictionary() {

}
