#include "sort.h"

/**
 * swap - swaps two integer positions within a pointed array
 * @a: positon a
 * @b: positon b
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - pivot based sorting algorithm
 * @array: the array to be sorted
 * @size: size of the array
 * @low: low index
 * @high: high index
 * Return: size_t index value
 */

size_t partition(int *array, size_t size, size_t low, size_t high)
{
	size_t i, j;
	int pivot;

	pivot = array[high];
	if (low > 0)
		i = (low - 1);
	else
		i = 0;

	j = low;
	while (j < high)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
		j++;
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, size);
	return (i + 1);
}

/**
 * qk_sort - actual recursive sort algo
 * @array: sorting this array
 * @size: size of the array
 * @low: low index
 * @high: high index
 */

void qk_sort(int *array, size_t size, size_t low, size_t high)
{
	size_t pi;

	if (low < high)
	{
		pi = partition(array, size, low, high);
		qk_sort(array, size, low, pi - 1);
		qk_sort(array, size, pi + 1, high);
	}
}

/**
 * quick_sort - use the quick sort algorithm to sort an int array
 * @array: pointer to the array
 * @size: of the array
 * Return: the endless void
 */

void quick_sort(int *array, size_t size)
{
	size_t low, high;

	if (!array || size < 2)
		return;

	low = 0;
	high = size - 1;

	qk_sort(array, size, low, high);
}
