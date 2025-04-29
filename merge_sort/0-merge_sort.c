#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - Merges two subarrays into original array in sorted order
 * @array: Original array
 * @left: Left subarray
 * @right: Right subarray
 * @l_size: Size of left subarray
 * @r_size: Size of right subarray
 */
void merge(int *array, int *left, int *right, size_t l_size, size_t r_size)
{
size_t i = 0, j = 0, k = 0;

printf("Merging...\n[left]: ");
print_array(left, l_size);
printf("[right]: ");
print_array(right, r_size);

while (i < l_size && j < r_size)
array[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];

while (i < l_size)
array[k++] = left[i++];

while (j < r_size)
array[k++] = right[j++];

printf("[Done]: ");
print_array(array, l_size + r_size);
}

/**
 * merge_sort_rec - Recursive merge sort logic
 * @array: The array to sort
 * @size: Size of array
 * @temp: Allocated memory to reuse
 */
void merge_sort_rec(int *array, size_t size, int *temp)
{
size_t mid, i;
int *left, *right;

if (size < 2)
return;

mid = size / 2;
left = temp;
right = temp + mid;

for (i = 0; i < size; i++)
temp[i] = array[i];

merge_sort_rec(left, mid, array);
merge_sort_rec(right, size - mid, array + mid);
merge(array, left, right, mid, size - mid);
}

/**
 * merge_sort - Entry point to perform merge sort
 * @array: The array to sort
 * @size: Size of array
 */
void merge_sort(int *array, size_t size)
{
int *temp;

if (!array || size < 2)
return;

temp = malloc(sizeof(int) * size);
if (!temp)
return;

merge_sort_rec(array, size, temp);
free(temp);
}
