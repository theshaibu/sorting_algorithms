#include "sort.h"

/**
 * merge_sort - Sorts an array with the Merge Sort algorithm.
 * @array: Array of integers to sort.
 * @size: Size of the array.
 */
void merge_sort(int *array, size_t size)
{
    int *arr;

    if (!array || size < 2)
        return;

    arr = malloc(sizeof(int) * size);

    if (arr == NULL)
        return;

    merge_recursion(arr, array, 0, size);

    free(arr);
}

/**
 * merge_recursion - Recursive function that merge sorts an array.
 * @arr: Copy array.
 * @array: Array to merge sort.
 * @left: Index of the left element.
 * @right: Index of the right element.
 */
void merge_recursion(int *arr, int *array, size_t left, size_t right)
{
    size_t middle;

    if (right > left)
    {
        middle = left + (right - left) / 2;
        merge_recursion(arr, array, left, middle);
        merge_recursion(arr, array, middle + 1, right);
        merge_subarray(arr, array, left, middle, right);
    }
}

/**
 * merge_subarray - Merges subarrays.
 * @arr: Copy array.
 * @array: Array to merge.
 * @left: Index of the left element.
 * @middle: Index of the middle element.
 * @right: Index of the right element.
 */
void merge_subarray(int *arr, int *array, size_t left,
                    size_t middle, size_t right)
{
    size_t i, j, k = 0;

    printf("Merging...\n");
    printf("[left]: ");
    print_array(array + left, middle - left);
    printf("[right]: ");
    print_array(array + middle, right - middle);

    for (i = left, j = middle; i < middle && j < right; k++)
    {
        if (array[i] < array[j])
            arr[k] = array[i++];
        else
            arr[k] = array[j++];
    }

    while (i < middle)
        arr[k++] = array[i++];
    while (j < right)
        arr[k++] = array[j++];

    for (k = 0, i = left; i < right; k++, i++)
        array[i] = arr[k];

    printf("[Done]: ");
    print_array(array + left, right - left);
}

