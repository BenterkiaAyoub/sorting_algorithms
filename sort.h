#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/* Macros defining the comparison direction in bitonic sort */
#define ASCENDING 0
#define DESCENDING 1

/**
 * enum boolean - Enumeration of Boolean values.
 * @FALSE: Represents the value false, equivalent to 0.
 * @TRUE: Represents the value true, equivalent to 1.
 */
typedef enum boolean
{
	FALSE = 0,
	TRUE
} boolean;

/**
 * struct listint_s - Definition of a doubly linked list node.
 *
 * @n: Integer value stored in the node.
 * @prev: Pointer to the previous element in the list.
 * @next: Pointer to the next element in the list.
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Helper functions for printing arrays and linked lists */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Sorting algorithms */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

#endif /* SORT_H */

