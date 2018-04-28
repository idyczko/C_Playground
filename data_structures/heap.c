#include <stdio.h>
#include <math.h>

void *calloc(size_t, size_t);
double log2(double);

struct binary_node {
  int value;
  struct binary_node *parent;
  struct binary_node *left;
  struct binary_node *right;
};

struct binary_node_heap {
  struct binary_node root;
};

struct binary_table_heap {
  int elements;
  int size;
  int *data;
};
// 
// void add(struct binary_node_heap *h, binary_node *node) {
//   if (h->root == NULL)
//     h->root = node;
//   else
//     while
//
// }

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

void printf_heap(const struct binary_table_heap h) {
  int i = 0;
  int last_log = 0;
  for(; i < h.elements; i++) {
    if (((int) log2(i+1)) > last_log) {
      last_log =  log2(i + 1);
      printf("\n");
    }
    printf("%d\t", h.data[i]);
  }
  printf("\n\n");
}

void heapify_down(struct binary_table_heap *h) {
  int child_index, top_index = 0;
  while(h->data[top_index] > h->data[left_child(top_index)] && left_child(top_index) < h->elements ||
        h->data[top_index] > h->data[right_child(top_index)] && right_child(top_index) < h->elements) {
    child_index = h->data[left_child(top_index)] < h->data[right_child(top_index)] &&  left_child(top_index) < h->elements ?
      left_child(top_index) : right_child(top_index);
    swap(h, top_index, child_index);
    top_index = child_index;
  }
}

int pop(struct binary_table_heap *h) {
  if(h->elements == 0)
    return -1;
  int result = h->data[0];
  h->data[0] = h->data[--h->elements];
  heapify_down(h);
  return result;
}

void heapify_up(struct binary_table_heap *h) {
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
  heapify_up(h);
}

int main(int argc, char *argv[]) {
  int numbers[20] = {10, 12, 32, 123, 124, 121, 2, 3, 12, 21, 121, 1, 1212, 12, 1, 0563, 39492, 2, 3, 23};
  struct binary_table_heap h = {0, 100, (int *) calloc(100, sizeof(int))};
  int i = 0;
  for(i; i<20;i++)
    add(&h, numbers[i]);

  printf_heap(h);
  pop(&h);
  add(&h, 0);
  printf_heap(h);
  for(i=0; i<20;i++)
    numbers[i] = pop(&h);
  for(i=0; i<20;i++)
    printf("%d ", numbers[i]);

  return 0;
}
