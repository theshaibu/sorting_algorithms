#include "sort.h"

/**
 * counting_sort - Sorts an array with the Counting sort algorithm.
 * @array: Array to sort.
 * @size: Size of the array.
 */
void counting_sort(int *array, size_t size)
{
    if (size < 2 || array == NULL)
        return;

    int *count_arr, *out_arr, max, num;
    size_t i, k, m, n;

    max = array[0];
    for (i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];

    count_arr = malloc(sizeof(int) * (max + 1));
    out_arr = malloc(sizeof(int) * size);

    if (count_arr == NULL || out_arr == NULL)
    {
        free(count_arr);
        free(out_arr);
        return;
    }

    for (k = 0; k <= max; k++)
        count_arr[k] = 0;

    for (k = 0; k < size; k++)
    {
        num = array[k];
        count_arr[num] += 1;
    }

    for (k = 1; k <= max; k++)
        count_arr[k] += count_arr[k - 1];

    print_array(count_arr, max + 1);

    for (m = 0; m < size; m++)
    {
        out_arr[count_arr[array[m]] - 1] = array[m];
        count_arr[array[m]]--;
    }

    for (n = 0; n < size; n++)
        array[n] = out_arr[n];

    free(count_arr);
    free(out_arr);
}

