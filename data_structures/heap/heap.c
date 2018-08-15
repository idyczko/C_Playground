#include <stdio.h>
#include <math.h>
#include "heap.h"

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
