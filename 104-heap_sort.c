 #include "sort.h"

void swap_ints(int *s, int *j);
void max_heapify(int *array, size_t size, size_t layer, size_t square);
void heap_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @s: The first integer to swap.
 * @j: The second integer to swap.
 */
void swap_ints(int *s, int *j)
{
	int tmp;

	tmp = *s;
	*s = *j;
	*j = tmp;
}

/**
 * max_heapify - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array
 * @layer: The index of the base row of the tree.
 * @square: The root node of the binary tree.
 */
void max_heapify(int *array, size_t size, size_t layer, size_t square)
{
	size_t left, right, large;

	left = 2 * square + 1;
	right = 2 * square + 2;
	large = square;

	if (left < layer && array[left] > array[large])
		large = left;
	if (right < layer && array[right] > array[large])
		large = right;

	if (large != square)
	{
		swap_ints(array + square, array + large);
		print_array(array, size);
		max_heapify(array, size, layer, large);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int p;

	if (array == NULL || size < 2)
		return;

	for (p = (size / 2) - 1; p >= 0; p--)
		max_heapify(array, size, size, p);

	for (p = size - 1; p > 0; p--)
	{
		swap_ints(array, array + p);
		print_array(array, size);
		max_heapify(array, size, p, 0);
	}
}
