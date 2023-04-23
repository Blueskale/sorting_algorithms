#include "deck.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 *
 * @node1: First node to be swapped
 * @node2: Second node to be swapped
 *
 * Description: This function swaps the positions of two nodes in a doubly
 *              linked list, preserving the links between the nodes.
 */
void swap_nodes(deck_node_t *node1, deck_node_t *node2)
{
	deck_node_t *temp;

	if (node1->prev != NULL)
		node1->prev->next = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;

	node1->prev = node2;
	node2->next = node1;

	temp = node1;
	node1 = node2;
	node2 = temp;
}

/**
 * list_len - Computes the length of a doubly linked list
 *
 * @head: Pointer to the head of the list
 *
 * Return: The number of nodes in the list
 *
 * Description: This function computes the number of nodes in a doubly
 *              linked list.
 */
size_t list_len(deck_node_t *head)
{
	size_t len = 0;

	while (head != NULL)
	{
		head = head->next;
		len++;
	}

	return (len);
}

/**
 * partition - Finds the partition index for quicksort algorithm
 *
 * @deck: Pointer to the head of the list
 * @low: The lowest index of the partition
 * @high: The highest index of the partition
 *
 * Return: The partition index
 *
 * Description: This function takes the last node as pivot and places
 *              all smaller nodes to the left of it and all greater
 *              nodes to the right of it.
 */
int partition(deck_node_t **deck, int low, int high)
{
	deck_node_t *pivot = NULL;
	deck_node_t *current = NULL;
