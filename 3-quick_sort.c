#include "sort.h"

void swap_ints(int *r, int *s);
int lomuto_partition(int *array, size_t length, int left, int right);
void lomuto_sort(int *array, size_t length, int left, int right);
void quick_sort(int *array, size_t length);

/**
 * swap_ints - Swap two integers in an array.
 * @r: The first integer to swap.
 * @s: The second integer to swap.
 */
void swap_ints(int *r, int *s)
{
	int tmp;

	tmp = *r;
	*r = *s;
	*s = tmp;
}

/**
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @length: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t length, int left, int right)
{
	int *pivot, high, low;

	pivot = array + right;
	for (high = low = left; low < high; low++)
	{
		if (array[low] < *pivot)
		{
			if (high < low)
			{
				swap_ints(array + low, array + high);
				print_array(array, length);
			}
			high++;
		}
	}

	if (array[high] > *pivot)
	{
		swap_ints(array + high, pivot);
		print_array(array, length);
	}

	return (high);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @length: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t length, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, length, left, right);
		lomuto_sort(array, length, left, part - 1);
		lomuto_sort(array, length, part + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @length: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t length)
{
	if (array == NULL || length < 2)
		return;

	lomuto_sort(array, length, 0, length - 1);
}


