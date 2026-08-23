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
 * Return: index value
 */

int partition(int *array, size_t size, int low, int high)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
		j++;
	}

	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_actual - actual recursive sort algo
 * @array: sorting this array
 * @size: size of the array
 * @low: low index
 * @high: high index
 */

void quick_sort_actual(int *array, size_t size, int low, int high)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, size, low, high);
		quick_sort_actual(array, size, low, pi - 1);
		quick_sort_actual(array, size, pi + 1, high);
	}
}

/**
 * quick_sort - use the quick sort algorithm to sort an int array
 * @array: pointer to the array
 * @size: of the array
 */

void quick_sort(int *array, size_t size)
{
	quick_sort_actual(array, size, 0, size - 1);
}
