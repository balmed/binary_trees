#include "binary_trees.h"

/**
 * tree_size - measures the sum of heights of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t ht_l = 0;
	size_t ht_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		ht_l = 1 + tree_size(tree->left);

	if (tree->right)
		ht_r = 1 + tree_size(tree->right);

	return (ht_l + ht_r);
}

/**
 * heap_to_sorted_array - converts a Binary Max Heap
 * to a sorted array of integers
 *
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 *
 * Return: pointer to array sorted in descending order
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int j, *p = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	p = malloc(sizeof(int) * (*size));

	if (!p)
		return (NULL);

	for (j = 0; heap; j++)
		p[j] = heap_extract(&heap);

	return (p);
}
