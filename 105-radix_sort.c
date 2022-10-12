#include "sort.h"

/**
 * radix_sort - Function
 * Description: sorts an array following the Radix sort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max;
	size_t x, lsd;

	/*check if array is empty*/
	if (!array || size < 2)
		return;

	max = 0;
	for (x = 0; x < size; x++)
		if (array[x] > max)
			max = array[x];

	for (lsd = 1; max / lsd > 0; lsd *= 10)
	{
		count_sort(array, size, lsd);
		print_array(array, size);
	}
}

/**
 * count_sort - helper function
 * Description: count sort with LSD
 * @array: array to sort
 * @size: size of the array
 * @lsd: least significant digit
 */
void count_sort(int *array, size_t size, size_t lsd)
{
	int count_arr[10] = {0}, *output, x, m;
	size_t k, n;

	output = malloc(sizeof(int) * size);

	for (k = 0; k < size; k++)
		count_arr[(array[k] / lsd) % 10]++;
	for (x = 1; x < 10; x++)
		count_arr[x] += count_arr[x - 1];

	for (m = size - 1; m >= 0; m--)
	{
		output[count_arr[(array[m] / lsd) % 10] - 1] = array[m];
		count_arr[(array[m] / lsd) % 10]--;
	}

	for (n = 0; n < size; n++)
		array[n] = output[n];

	free(output);
}
