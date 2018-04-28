#include <stdio.h>

void *calloc(size_t, size_t);

struct binary_table_heap {
  int elements;
  int size;
  int *data;
};

int parent(int index) {
  return (index - 1)/2;
}

int left_child(int index) {
  return 2*index + 1;
}

int right_child(int index) {
  return 2*index + 2;
}

void swap(struct binary_table_heap *h, int index_1, int index_2) {
  int temp = h->data[index_1];
  h->data[index_1] = h->data[index_2];
  h->data[index_2] = temp;
}

void heapify(struct binary_table_heap *h) {
  int new_element_index = h->elements -1;
  while(h->data[new_element_index] < h->data[parent(new_element_index)]) {
    swap(h, new_element_index, parent(new_element_index));
    new_element_index = parent(new_element_index);
  }
}

void add(struct binary_table_heap *h, int n) {
  if(h->size <= 1.5*h->elements)
    return;
  h->data[h->elements++] = n;
  heapify(h);
}

int main(int argc, char *argv[]) {
  int numbers[20] = {10, 12, 32, 123, 124, 121, 2, 3, 12, 21, 121, 1, 1212, 12, 1, 0563, 39492, 2, 3, 23};
  struct binary_table_heap h = {0, 100, (int *) calloc(100, sizeof(int))};
  int i = 0;
  for(i; i<20;i++)
    add(&h, numbers[i]);

  for(i=0; i<20;i++)
    printf("%d ", h.data[i]);

  printf("\n");
  return 0;
}
