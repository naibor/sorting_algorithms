#include "sort.h"

/**
  * counting_sort - function
  * Description: sorts an array using counting algorithm.
  * @array: The array to sort.
  * @size: The length of the array.
  */
void counting_sort(int *array, size_t size)
{
	unsigned int x = 1;
	int *counter = NULL, k = 0, y = 0;

	/*check if empty*/
	if (array == NULL || size < 2)
		return;

	k = array[0];
	for (; x < size; x++)
	{
		if (array[x] > k)
			k = array[x];
	}

	counter = malloc(sizeof(int) * (k + 1));
	if (counter == NULL)
		return;

	for (y = 0; y <= k; y++)
		counter[y] = 0;
	for (x = 0; x < size; x++)
		counter[array[x]] += 1;
	for (y = 0; y < k; y++)
	{
		counter[y + 1] += counter[y];
		printf("%d, ", counter[y]);
	}
	counter[y + 1] += counter[y];
	printf("%d\n", counter[y + 1]);
	for (x = 0; x < size; x++)
	{
		y = counter[array[x]] - 1;
		if (array[x] != array[y])
		{
			k = array[x];
			array[x] = array[y];
			array[y] = k;
		}
	}
	free(counter);
}
