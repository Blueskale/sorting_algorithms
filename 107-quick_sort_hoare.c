#include "sort.h"

/**

*hoare_partition - Hoare partition scheme using rightmost index as pivot.

*@array: Array of integers to be sorted.

*@low: Index in source array that begins partition.

*@high: Index in source array that ends partition.

*@size: Amount of elements in array.

*Return: New index at which to start new recursive partition.
*/
int hoare_partition(int *array, size_t low, size_t high, size_t size)
{
int i, j, pivot, temp;

pivot = array[high];
i = (int) low - 1;
j = (int) high + 1;

while (i < j)
{
do {
i++;
} while (array[i] < pivot);
do {
j--;
} while (array[j] > pivot);
if (i < j)
{
temp = array[i];
array[i] = array[j];
array[j] = temp;
print_array(array, size);
}
}

return (j);
}

/**

*hoare_quicksort - Recursively sorts array of integers using Hoare quick sort.

*@array: Array of integers to be sorted.

*@low: Index in source array that begins partition.

*@high: Index in source array that ends partition.

*@size: Amount of elements in array.
*/
void hoare_quicksort(int *array, size_t low, size_t high, size_t size)
{
size_t border;

if (low < high)
{
border = hoare_partition(array, low, high, size);
hoare_quicksort(array, low, border, size);
hoare_quicksort(array, border + 1, high, size);
}
}

/**

*quick_sort_hoare - Sorts array of integers in ascending order using Hoare partition scheme.

*@array: Array of values to be sorted.

*@size: Number of elements in array.
*/
void quick_sort_hoare(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

hoare_quicksort(array, 0, size - 1, size);
}

/*

