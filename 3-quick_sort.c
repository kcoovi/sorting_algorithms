#include "sort.h"
void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);
/**
 * swap_ints - function
 * @a: int
 * @b: int
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - function
 * @array: array
 * @size: size
 * @left: left
 * @right: right
 * Return: above
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot;
	int above;
	int below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
	if (array[below] < *pivot)
	{
	if (above < below)
	{
	swap_ints(array + below, array + above);
	print_array(array, size);
	}
	above++;
	}
	}

	if (array[above] > *pivot)
	{
	swap_ints(array + above, pivot);
	print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - function
 * @array: array
 * @size: right
 * @left: left
 * @right: right
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
int pt;

if (right - left > 0)
{
pt = lomuto_partition(array, size, left, right);
lomuto_sort(array, size, left, pt - 1);
lomuto_sort(array, size, pt + 1, right);
}
}

/**
 * quick_sort - function
 * @array: array
 * @size: size
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	return;

	lomuto_sort(array, size, 0, size - 1);
}
