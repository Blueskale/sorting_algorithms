#include "sort.h"

/**
 * i_parent - returns index of parent node for an array arranged as a binary
 * tree, for index i
 * @i: starting index to determine parent node index
 * Return: index of parent node
 */
int i_parent(int i)
{
	return ((i - 1) / 2);
}

/**
 * i_left_child - returns index of left child branch for an array arranged as
 * a binary tree, for index i
 * @i: starting index to determine left child branch index
 * Return: index of left child node
 */
int i_left_child(int i)
{
	return ((2 * i) + 1);
}

/**
 * heapify - arranges array of integers into a heap/binary tree scheme
 * @array: array of integers
 * @size: number of elements in array
 * @start: starting index
 * @end: ending index
 */
void heapify(int *array, size_t size, int start, int end)
{
	int root, swap, temp, child;

	root = start;

	while (i_left_child(root) <= end)
	{
		child = i_left_child(root);
		swap = root;

		if (array[swap] < array[child])
			swap = child;
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;
		if (swap != root)
		{
			temp = array[root];
			array[root] = array[swap];
			array[swap] = temp;
			print_array(array, size);
			root = swap;
		}
		else
			return;
	}
}

/**
 * heap_sort - sorts array of integers in ascending order using a heap sort
 * sift-down algorithm
 * @array: array of values to be sorted
 * @size: number of elements in array
 */
void heap_sort(int *array, size_t size)
{
	int i_end, temp;

	if (!array || size < 2)
		return;

	/* Convert array into a heap */
	int start = i_parent(size - 1);
	while (start >= 0)

	{
		heapify(array, size, start, size - 1);
		start--;
	}

	/* Repeatedly extract the maximum element and heapify the remaining array */
	i_end = (int)size - 1;
	while (i_end > 0)
	{
		temp = array[i_end];
		array[i_end] = array[0];
		array[0] = temp;
		print_array(array, size);
		i_end--;
		heapify(array, size, 0, i_end);
	}
}
