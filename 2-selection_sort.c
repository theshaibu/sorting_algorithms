#include "sort.h"

/**
 * selection_sort - Sorts an array using the selection sort algorithm.
 * @array: Array to sort.
 * @size: Size of the array.
 */
void selection_sort(int *array, size_t size)
{
    if (size < 2 || array == NULL)
        return;

    unsigned int i, j, min;
    int tmp;

    for (i = 0; i < size - 1; i++)
    {
        min = i;

        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min])
                min = j;
        }

        if (min != i)
        {
            tmp = array[i];
            array[i] = array[min];
            array[min] = tmp;

            print_array(array, size);
        }
    }
}

