#include "sort.h"

/**
 * merge_sort - Function
 * Description: sorts an array with the Merge Sort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *arr;
	/*check if array is empty*/
	if (!array || size < 2)
		return;
	/*allocate memeory to array*/
	arr = malloc(sizeof(int) * size);

	merge_recurs(arr, array, 0, size);
	free(arr);
}

/**
 * merge_recurs - helper function
 * Description: recusive function that merge sorts an array
 * @arr: copy array
 * @array: array to merge sort
 * @left: index of the left element
 * @right: index of the right element
 */
void merge_recurs(int *arr, int *array, size_t left, size_t right)
{
	size_t middle;

	if (right - left > 1)
	{
		middle = (right - left) / 2 + left;
		merge_recurs(arr, array, left, middle);
		merge_recurs(arr, array, middle, right);
		merge_subarray(arr, array, left, middle, right);
	}
}

/**
 * merge_subarray - helper function
 * Description: merges subarrays
 * @arr: copy array
 * @array: array to merge
 * @left: index of the left element
 * @middle: index of the middle element
 * @right: index of the right element
 */
void merge_subarray(int *arr, int *array, size_t left,
		size_t middle, size_t right)
{
	size_t x, y, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, middle  - left);
	printf("[right]: ");
	print_array(array + middle, right - middle);

	for (x = left, y = middle; x < middle && y < right; k++)
	{
		if (array[x] < array[y])
			arr[k] = array[x++];
		else
			arr[k] = array[y++];
	}

	while (x < middle)
		arr[k++] = array[x++];
	while (y < right)
		arr[k++] = array[y++];

	for (k = left, x = 0; k < right; k++)
		array[k] = arr[x++];

	printf("[Done]: ");
	print_array(array + left, right - left);
}
