#include "sort.h"

/**
* shell_sort - function sorts an array of integers using
* the shell sort algorithm with Knuth sequence
* @array: the array of integers
* @size: size of the array
*
* Return: none
*/
void shell_sort(int *array, size_t size)
{
	size_t gap, j, i;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < size / 3;)
		gap = gap * 3 + 1;

	for (; gap > 0; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= gap && tmp < array[j - gap]; j -= gap)
				array[j] = array[j - gap];
			array[j] = tmp;
		}
		print_array(array, size);
	}
}

