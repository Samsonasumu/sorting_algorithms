#include "sort.h"

/**
 * max_num - function reutrn max integer
 *
 * @array: pointers array
 * @size: size value the lengeth
 * Return: integer data
 */
int max_num(int *array, int size)
{
	int max_num, j;

	for (max_num = array[0], j = 1; j < size; j++)
	{
		if (array[j] > max_num)
			max_num = array[j];
	}
	return (max_num);
}

/**
 * radix_counting - function radix counting data
 *
 * @array: pointers array
 * @size: size value the lengeth
 * @powten: integer data powten
 * @copy: malloc with copy the array
 */
void radix_counting(int *array, size_t size, int powten, int *copy)
{
	int count[10] = {0};
	int index;


	for (index = 0; index < (int)size; index++)
		count[(array[index] / powten) % 10] += 1;

	for (index = 0; index < 10; index++)
		count[index] += count[index - 1];

	for (index = (int)size - 1; index >= 0; index--)
	{
		copy[count[(array[index] / powten) % 10] - 1] = array[index];
		count[(array[index] / powten) % 10] -= 1;
	}
	for (index = 0; index < (int)size; index++)
		array[index] = copy[index];
}

/**
 * radix_sort - function sorting radix
 *
 * @array: pointers array
 * @size: size value the lengeth
 */
void radix_sort(int *array, size_t size)
{
	int max, powten, *copy;

	if (!array || size < 2)
		return;

	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;

	max = max_num(array, size);

	for (powten = 1; max / powten > 0; powten *= 10)
	{
		radix_counting(array, size, powten, copy);
		print_array(array, size);
	}
	free(copy);
}
