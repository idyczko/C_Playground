#ifndef HUFFMAN_ENCODING
#define HUFFMAN_ENCODING
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *calloc(size_t, size_t);

char *compress(char *);
char *decompress(char *);
void print_dictionary();

#endif
