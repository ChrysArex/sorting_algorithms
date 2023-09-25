#include "sort.h"
/**
 * bubble_sort - sorts an array of integers
 * in ascending order using the Bubble sort algorithm
 *
 * @array: pointer to the array to sort
 * @size: size of this array
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	int tmp, swap = 1;
	size_t i;

	while (swap)
	{
		swap = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i + 1] < array[i])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				swap += 1;
				print_array(array, size);
			}
		}
	}
}
