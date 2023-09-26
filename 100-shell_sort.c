#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 *
 * @array: pointer to array of int
 * @size: size of @array
 *
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t i, idx;
	int tmp;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			idx = i;

			while (idx >= gap && array[idx - gap] > tmp)
			{
				array[idx] = array[idx - gap];
				idx -= gap;
			}

			array[idx] = tmp;
		}
		print_array(array, size);

		gap /= 3;
	}
}
