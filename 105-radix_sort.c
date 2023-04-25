#include "sort.h"
#include <stdlib.h>

/**

init_bucket_count - resets bucket_count values to 0

@bucket_count: array containing amounts of members for arrays in buckets

Return: Nothing.
*/
void init_bucket_count(int *bucket_count)
{
size_t i;

for (i = 0; i < 10; i++)
bucket_count[i] = 0;
}

/**

build_buckets - allocates space for arrays to be held in buckets

@buckets: array of arrays each containing sorted members of array

@bucket_count: array containing amounts of members for arrays in buckets

Return: Nothing.
*/
void build_buckets(int *bucket_count, int **buckets)
{
int *bucket;
size_t i;

for (i = 0; i < 10; i++)
{
bucket = malloc(sizeof(int) * bucket_count[i]);
if (!bucket)
{
while (i--)
free(buckets[i]);
free(buckets);
exit(EXIT_FAILURE);
}
buckets[i] = bucket;
}
init_bucket_count(bucket_count);
}

/**

find_max - searches array of integers for highest value

@array: array of values to be searched

@size: number of elements in array

Return: largest integer stored in array
*/
int find_max(int *array, size_t size)
{
int max;
size_t i;

max = array[0];
for (i = 1; i < size; i++)
if (array[i] > max)
max = array[i];
return (max);
}

/**

into_array - flattens buckets into array sorted by current digit place,

then prints results and frees current buckets for next pass

@array: array of values to be printed

@size: number of elements in array

@buckets: array of arrays each containing sorted members of array

@bucket_count: array containing amounts of members for arrays in buckets

Return: Nothing.
*/
void into_array(int *array, size_t size, int **buckets, int *bucket_count)
{
size_t i, j, k;

/* flatten bucket members in order into array sorted by place /
for (k = 0, i = 0; k < 10; k++)
{
for (j = 0; j < bucket_count[k]; j++, i++)
array[i] = buckets[k][j];
}
/ print results /
print_array(array, size);
/ free buckets from current pass */
for (i = 0; i < 10; i++)
free(buckets[i]);
}

/**

radix_sort - Sorts array of integers in ascending order using a Radix sort

algorithm starting with the LSD, the 'least significant (1s place) digit',

and sorting by next digit to left. Size of bucket_count here determined

by max range of key variance (digits 0-9), other solutions may be needed for

much larger ranges.

@array: array of values to be sorted

@size: number of elements in array

Return: Nothing.
*/
void radix_sort(int *array, size_t size)
{
int **buckets;
int bucket_count[10];
int max, max_digits, pass, divisor, digit;
size_t i;

if (!array || size < 2)
return;
buckets = malloc(sizeof(int ) * 10);
if (!buckets)
exit(EXIT_FAILURE);
/ find amount of places in largest element */
max = find_max(array, size);
for (max_digits = 0)
