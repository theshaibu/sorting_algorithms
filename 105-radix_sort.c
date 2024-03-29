#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
    int max = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
    int count[10] = {0};
    size_t i;

    for (i = 0; i < size; i++)
        count[(array[i] / sig) % 10] += 1;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size; i > 0; i--)
    {
        buff[count[(array[i - 1] / sig) % 10] - 1] = array[i - 1];
        count[(array[i - 1] / sig) % 10] -= 1;
    }

    for (i = 0; i < size; i++)
        array[i] = buff[i];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    int *buff = malloc(sizeof(int) * size);
    if (buff == NULL)
        return;

    int max = get_max(array, size);
    for (int sig = 1; max / sig > 0; sig *= 10)
    {
        radix_counting_sort(array, size, sig, buff);
        print_array(array, size);
    }

    free(buff);
}

