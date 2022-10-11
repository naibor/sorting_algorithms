#include"sort.h"
/**
 * selection_sort - Function
 * Description: sorts an array of ints in ascending
 * using selection sort
 * @array: the array to sort
 * @size: the size of array
 */
void selection_sort(int *array, size_t size)
{
	int temp = 0;
	size_t x = 0, y = 0, position = 0;

	/*check if array is empty*/
	if (array == NULL || size == 0)
		return;
	/* loop and check values then swap*/
	for (; x < size - 1; x++)
	{
		position = x;
		for (y = x + 1; y < size; y++)
		{
			if (array[y] < array[position])
				position = y;
		}
		if (position != x)
		{
			temp = array[x];
			array[x] = array[position];
			array[position] = temp;
			print_array(array, size);
		}
	}
}
