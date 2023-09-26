#include "sort.h"

/**
 * set_pivot_position - function
 *
 * @array: array
 * @i: i
 * @idx: idx
 * @size: size
 *
 * Return: size_t
 */
size_t set_pivot_position(int *array, size_t i, size_t idx, size_t size)
{
	int tmp, signe = -1;
	int *start = array;

	for (; i != idx; i += signe)
	{
		if (array[i] < *start || array[i] > *start)
		{
			tmp = array[i];
			array[i] = *start;
			*start = tmp;
			start += -1 * signe * (i - idx);
			tmp = i;
			i = idx;
			idx = tmp;
			signe *= -1;
			print_array(array, size);
		}
	}
	return (i);
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: pointer to an array of integer
 * @size: size of the array
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	size_t pos, i = size - 1, idx = 0;

	if (size > 0)
	{
		pos = set_pivot_position(array, i, idx, size);
		quick_sort(array, &array[pos + 1] - array + 1);
		quick_sort(&array[pos + 1], size - 1 - pos);
	}
}
