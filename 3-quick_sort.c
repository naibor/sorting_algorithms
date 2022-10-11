#include"sort.h"
/**
 * quick_sort - Function
 * Description: sorts an array of ints in ascending
 * using quick sort
 * @array: the array to sort
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	quick_recurs(array, 0, (int)size - 1, size);
}

/**
 * quick_recurs - helper function
 * Description: perform recursive checks
 * @array: array to sort
 * @left: index of the left element
 * @right: index of the right element
 * @size: size of the array
 */
void quick_recurs(int *array, int left, int right, size_t size)
{
	int temp;

	if (left < right)
	{
		temp = partition(array, left, right, size);
		quick_recurs(array, left, temp - 1, size);
		quick_recurs(array, temp + 1, right, size);
	}
}

/**
 * partition - helper function
 * Description: gives a temp index for Quicksort
 * @array: array to find the piv in
 * @left: index of the left element
 * @right: index of the right element
 * @size: size of the array
 *
 * Return: the index of the piv element
 */
int partition(int *array, int left, int right, size_t size)
{
	int temp, x;
	int y;

	x = left - 1;

	for (y = left; y < right; y++)
	{
		if (array[y] < array[right])
		{
			x++;
			if (x != y)
			{
				temp = array[x];
				array[x] = array[y];
				array[y] = temp;
				print_array(array, size);
			}
		}
	}

	if (array[right] < array[x + 1])
	{
		temp = array[x + 1];
		array[x + 1] = array[right];
		array[right] = temp;
		print_array(array, size);
	}

	return (x + 1);
}
