#include "sort.h"

/**
 * swap_integers - Swap two integers in an array.
 * @k: The first integer to swap.
 * @o: The second integer to swap.
 */
void swap_integers(int *k, int *o)
{
	int tamper;

	tamper = *k;
	*k = *o;
	*o = tamper;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t f, g;

	if (array == NULL || size < 2)
		return;

	for (f = 0; f < size - 1; f++)
	{
		min = array + f;
		for (g = f + 1; g < size; g++)
			min = (array[g] < *min) ? (array + g) : min;

		if ((array + g) != min)
		{
			swap_integers(array + f, min);
			print_array(array, size);
		}
	}
}


