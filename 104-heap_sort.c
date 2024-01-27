#include "sort.h"

/**
 * heap_sort - Sorts an array following the Heap sort algorithm.
 * @array: Array of integers to sort.
 * @size: Size of the array to sort.
 */
void heap_sort(int *array, size_t size)
{
    int i, tmp;

    if (size < 2)
        return;

    for (i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, (size_t)i);

    for (i = size - 1; i > 0; i--)
    {
        tmp = array[i];
        array[i] = array[0];
        array[0] = tmp;
        print_array(array, size);
        heapify(array, (size_t)i, 0);
    }
}

/**
 * heapify - Turns an array into a heap tree.
 * @array: Array to turn into a heap.
 * @s: Size of the subtree.
 * @root: Index of the subtree in the heap.
 */
void heapify(int *array, size_t s, size_t root)
{
    size_t max, left, right;
    int tmp;

    max = root;
    left = (root * 2) + 1;
    right = (root * 2) + 2;

    if (left < s && array[left] > array[max])
        max = left;

    if (right < s && array[right] > array[max])
        max = right;

    if (max != root)
    {
        tmp = array[root];
        array[root] = array[max];
        array[max] = tmp;
        print_array(array, s);
        heapify(array, s, max);
    }
}

