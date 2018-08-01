#ifndef HUFFMAN_ENCODING
#define HUFFMAN_ENCODING
#include <stdio.h>
#include <stdlib.h>
#include "../../data_structures/heap.h"

void *calloc(size_t, size_t);

char *compress(char *);
char *decompress(char *);

#endif
