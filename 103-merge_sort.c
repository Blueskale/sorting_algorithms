#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - prints array of integers for range of indices
 * @array: array of values to be printed
 * @size: amount of elements in array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (i != 0)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * merge - merges the two sorted subarrays
 * @array: array of integers to be sorted
 * @left: pointer to the left subarray
 * @left_size: size of left subarray
 * @right: pointer to the right subarray
 * @right_size: size of right subarray
 * @work_array: array to store sorted integers
 **/
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size, int *work_array)
{
	size_t i = 0, j = 0, k = 0;

	while (i < left_size && j < right_size)
	{
		if (left[i] < right[j])
		{
			work_array[k] = left[i];
			i++;
		}
		else
		{
			work_array[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < left_size)
	{
		work_array[k] = left[i];
		i++;
		k++;
	}

	while (j < right_size)
	{
		work_array[k] = right[j];
		j++;
		k++;
	}

	for (i = 0; i < k; i++)
		array[i] = work_array[i];
}

/**
 * merge_sort - sorts an array of integers in ascending order using a
 * top-down merge sort algorithm
 * @array: array of integers to be sorted
 * @size: amount of elements in array
 **/
void merge_sort(int *array, size_t size)
{
	size_t mid, i;
	int *left, *right, *work_array;

	if (array == NULL || size < 2)
		return;

	if (size == 2)
	{
		if (array[0] > array[1])
		{
			int temp = array[0];
			array[0] = array[1];

			array[1] = temp;
			print_array(array, size);
		}
		return;
	}

	mid = size / 2;
	left = (int *)malloc(sizeof(int) * mid);
	right = (int *)malloc(sizeof(int) * (size - mid));
	work_array = (int *)malloc(sizeof(int) * size);

	for (i = 0; i < mid; i++)
		left[i] = array[i];
	for (i = mid; i < size; i++)
		right[i - mid] = array[i];

	merge_sort(left, mid);
	merge_sort(right, size - mid);
	merge(array, left, mid, right, size - mid, work_array);

	free(left);
	free(right);
	free(work_array);
}
