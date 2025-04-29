#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/* Function prototypes */
void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void swap(int *array, size_t a, size_t b);
void sift_down(int *array, size_t size, size_t root, size_t end);

#endif /* SORT_H */
