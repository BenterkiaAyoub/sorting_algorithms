#include "sort.h"

/**
 * swap_ints - Function to Swap two intgrs in an array.
 * @a: The first int.
 * @b: The second int.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Function that Sort an array of ints.
 * @array: array of ints.
 * @size: size of array.
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t j, length = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (j = 0; j < length - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_ints(array + j, array + j + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		length--;
	}
}
