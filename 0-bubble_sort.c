#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - sorts an array in ascending order using the Bubble sort algorithm
 * @array: array of integers to sort
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
    if (size < 2)
        return;

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                /* Swap elements */
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;

                /* Print the array after each swap */
                print_array(array, size);
            }
        }
    }
}

