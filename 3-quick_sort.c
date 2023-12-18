#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t sz, int lft, int rght);
void lomuto_sort(int *array, size_t sz, int lft, int rght);
void quick_sort(int *array, size_t sz);

/**
 * swap_ints - Swap two integers in an array.
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
 * lomuto_partition - Order a subset of an array of integers.
 * @array: The array of integers.
 * @sz: The sz of the array.
 * @lft: The starting index of the subset to be ordered.
 * @rght: The ending index of the subset to be ordered.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t sz, int lft, int rght)
{
	int *pvt, abv, blw;

	pvt = array + rght;
	for (abv = blw = lft; blw < rght; blw++)
	{
		if (array[blw] < *pvt)
		{
			if (abv < blw)
			{
				swap_ints(array + blw, array + abv);
				print_array(array, sz);
			}
			abv++;
		}
	}

	if (array[abv] > *pvt)
	{
		swap_ints(array + abv, pvt);
		print_array(array, sz);
	}

	return (abv);
}

/**
 * lomuto_sort - Implement the quicksort algorithm.
 * @array: An array of integers to be sorted.
 * @sz: The sz of the array.
 * @lft: The starting index of the array partition to be ordered.
 * @rght: The ending index of the array partition to be ordered.
 */
void lomuto_sort(int *array, size_t sz, int lft, int rght)
{
	int prt;

	if (rght - lft > 0)
	{
		prt = lomuto_partition(array, sz, lft, rght);
		lomuto_sort(array, sz, lft, prt - 1);
		lomuto_sort(array, sz, prt + 1, rght);
	}
}

/**
 * quick_sort - Sort an array of integers.
 * @array: An array of integers.
 * @sz: The sz of the array.
 *
 */
void quick_sort(int *array, size_t sz)
{
	if (array == NULL || sz < 2)
		return;

	lomuto_sort(array, sz, 0, sz - 1);
}
