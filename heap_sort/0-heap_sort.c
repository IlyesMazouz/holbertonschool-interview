#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);

/**
 * swap - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap(int *a, int *b)
{
 int temp = *a;
 *a = *b;
 *b = temp;
}

/**
 * sift_down - Move an element down the heap to restore the heap property.
 * @array: The array to sort.
 * @size: The size of the array.
 * @root: The index of the element to sift down.
 * @end: The index of the last element in the heap.
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
 size_t left, right, largest;

 left = 2 * root + 1;
 right = 2 * root + 2;
 largest = root;

 if (left <= end && array[left] > array[largest])
  largest = left;
 if (right <= end && array[right] > array[largest])
  largest = right;

 if (largest != root)
 {
  swap(&array[root], &array[largest]);
  print_array(array, size);
  sift_down(array, size, largest, end);
 }
}

/**
 * heapify - Convert an array into a max heap.
 * @array: The array to heapify.
 * @size: The size of the array.
 */
void heapify(int *array, size_t size)
{
 ssize_t start = (size / 2) - 1;
 ssize_t end = size - 1;

 while (start >= 0)
 {
  sift_down(array, size, start, end);
  start--;
 }
}

/**
 * heap_sort - Sort an array of integers in ascending order using heap sort.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
 ssize_t end = size - 1;

 if (!array || size < 2)
  return;

 heapify(array, size);

 while (end > 0)
 {
  swap(&array[0], &array[end]);
  print_array(array, size);
  end--;
  sift_down(array, size, 0, end);
 }
}
