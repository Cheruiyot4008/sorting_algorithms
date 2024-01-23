#include "sort.h"

/**
 * get_maximum - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_maximum(int *array, int size)
{
	int maximum, w;

	for (maximum = array[0], w = 1; w < size; w++)
	{
		if (array[w] > maximum)
			maximum = array[w];
	}

	return (maximum);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, maximum, w;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	maximum = get_maximum(array, size);
	count = malloc(sizeof(int) * (maximum + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (w = 0; w < (maximum + 1); w++)
		count[w] = 0;
	for (w = 0; w < (int)size; w++)
		count[array[w]] += 1;
	for (w = 0; w < (maximum + 1); w++)
		count[w] += count[w - 1];
	print_array(count, maximum + 1);

	for (w = 0; w < (int)size; w++)
	{
		sorted[count[array[w]] - 1] = array[w];
		count[array[w]] -= 1;
	}

	for (w = 0; w < (int)size; w++)
		array[w] = sorted[w];

	free(sorted);
	free(count);
}
