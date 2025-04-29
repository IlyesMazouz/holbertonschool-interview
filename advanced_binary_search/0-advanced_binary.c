#include <stdio.h>
#include "search_algos.h"

/**
 * print_subarray - Prints the current subarray.
 * @array: The array to print.
 * @start: The start index of the subarray.
 * @end: The end index of the subarray.
 */
void print_subarray(int *array, size_t start, size_t end)
{
    size_t i;

    printf("Searching in array: ");
    for (i = start; i < end; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("%d\n", array[end]);
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * using the binary search algorithm (recursive approach).
 * @array: The array to search in.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The index where value is located or -1 if not found.
 */
int advanced_binary(int *array, size_t size, int value)
{
    size_t mid;

    if (!array || size == 0)
        return (-1);

    mid = size / 2;

    print_subarray(array, 0, size - 1);

    if (array[mid] == value)
    {
        if (mid == 0 || array[mid - 1] != value)
            return (mid);
        else
            return (advanced_binary(array, mid, value));
    }
    else if (array[mid] < value)
        return (advanced_binary(array + mid + 1, size - mid - 1, value));
    else
        return (advanced_binary(array, mid, value));
}
