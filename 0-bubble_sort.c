#include "sort.h"

/**
 * bubble_sort - the sorting method called bubble
 * @array: the array of values to sort
 * @size: the size of the array
 */

void bubble_sort(int *array, size_t size)
{
	int temp, swap;
	size_t i, j;

	i = 0;
	while (i < size - 1)
	{
		j = swap = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swap = 1;
				print_array(array, size);
			}
			j++;
		}
		i++;
		if (swap == 0)
		{
			break;
		}
	}
}
