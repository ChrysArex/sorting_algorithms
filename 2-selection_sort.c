#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 *
 * @array: pointer to an array of integer
 * @size: size of the array
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, idx;
	int tmp;

	for (i = 0; i < size - 1; i++)
	{
		idx = i;
		tmp = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < tmp)
			{
				idx = j;
				tmp = array[j];
			}
		}
		if (array[idx] < array[i])
		{
			tmp = array[i];
			array[i] = array[idx];
			array[idx] = tmp;
			print_array(array, size);
		}
	}
}
