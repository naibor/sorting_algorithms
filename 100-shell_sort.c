#include "sort.h"

/**
  * shell_sort - Function
  * Description: sorts an array using shell algorithm.
  * @array: The array to sort.
  * @size: The length of the array.
  */
void shell_sort(int *array, size_t size)
{
	unsigned int x = 0, y = 0, gap = 0;
	int temp = 0;

	/*check if array is empty*/
	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (x = gap; x < size; x++)
		{
			temp = array[x];
			for (y = x; y >= gap && array[y - gap] > temp;
					y -= gap)
			{
				if (array[y] != array[y - gap])
					array[y] = array[y - gap];
			}
			if (array[y] != temp)
				array[y] = temp;

		}
		print_array(array, size);
	}
}
