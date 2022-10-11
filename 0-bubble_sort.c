#include "sort.h"
/**
 * bubble_sort - Function
 * Description: sorts an array of ints in ascending order
 * using bubble sort
 * @array: the array to sort
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t x = 0, y = 0;
	int temp = 0;

	/*check for empty array and return*/
	if (array == NULL || size == 0)
		return;
	/*loop throught array*/
	for (; x < size - 1; x++)
	{
		/*compare and shuffle values*/
		for (y = 0; y < size - x - 1; y++)
		{
			if (array[x] > array[y + 1])
			{
				temp = array[y + 1];
				array[y + 1] = array[y];
				array[y] = temp;
				print_array(array, size);
			}
		}
	}

}
