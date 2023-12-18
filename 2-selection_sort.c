#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array.
 * @a: Pointer to the first integer to be swapped.
 * @b: Pointer to the second integer to be swapped.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sort an array of integers.
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 *
 */
void selection_sort(int *array, size_t size)
{
	int *minimum;
	size_t t, q;

	if (array == NULL || size < 2)
		return;

	for (t = 0; t < size - 1; t++)
	{
		minimum = array + t;
		for (q = t + 1; q < size; q++)
			minimum = (array[q] < *minimum) ? (array + q) : minimum;

		if ((array + t) != minimum)
		{
			swap_ints(array + t, minimum);
			print_array(array, size);
		}
	}
}
