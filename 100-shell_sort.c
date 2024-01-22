#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @s: The first integer to swap.
 * @t: The second integer to swap.
 */
void swap_ints(int *s, int *t)
{
	int tmp;

	tmp = *s;
	*s = *t;
	*t = tmp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @length: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t length)
{
	size_t gap, k, p;

	if (array == NULL || length < 2)
		return;

	for (gap = 1; gap < (length / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (k = gap; k < size; k++)
		{
			p = k;
			while (p >= gap && array[p - gap] > array[p])
			{
				swap_ints(array + p, array + (p - gap));
				p -= gap;
			}
		}
		print_array(array, size);
	}
}
