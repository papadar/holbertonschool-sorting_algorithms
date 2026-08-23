#include "sort.h"

/**
 * selection_sort - sort an array using the selection algo
 * @array: pointer to the int array
 * @size: size of the array
 * Return: endless void
 */

void selection_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, min;

	if (!array || size == 0)
		return;

	i = 0;
	while (i < size - 1)
	{
		min = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[min])
				min = j;
			j++;
		}
		if (min != i)
		{
			temp = array[min];
			array[min] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
		i++;
	}
}
