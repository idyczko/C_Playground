#ifndef HEAP
#define HEAP

void *calloc(size_t, size_t);
double log2(double);

struct binary_table_heap {
  int elements;
  int size;
  int *data;
};

int parent(int index);

int left_child(int index);

int right_child(int index);

void swap(struct binary_table_heap *h, int index_1, int index_2);

void printf_heap(const struct binary_table_heap h);

void heapify_down(struct binary_table_heap *h);

int pop(struct binary_table_heap *h);

void heapify_up(struct binary_table_heap *h);

void add(struct binary_table_heap *h, int n);

#endif
