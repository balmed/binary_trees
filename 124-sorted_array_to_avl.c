#include "binary_trees.h"

/**
 * create_tree - creates an AVL tree with recursion
 *
 * @node: pointer node
 * @array: input array of integers
 * @size: size of array
 * @mode: 1 to adding on the left, 2 to adding on the right
 * Return: no return
 */
void create_tree(avl_t **node, int *array, size_t size, int mode)
{
	size_t mdl;

	if (size == 0)
		return;

	mdl = (size / 2);
	mdl = (size % 2 == 0) ? mdl - 1 : mdl;

	if (mode == 1)
	{
		(*node)->left = binary_tree_node(*node, array[mdl]);
		create_tree(&((*node)->left), array, mdl, 1);
		create_tree(&((*node)->left), array + mdl + 1, (size - 1 - mdl), 2);
	}
	else
	{
		(*node)->right = binary_tree_node(*node, array[mdl]);
		create_tree(&((*node)->right), array, mdl, 1);
		create_tree(&((*node)->right), array + mdl + 1, (size - 1 - mdl), 2);
	}
}

/**
 * sorted_array_to_avl - creates root node and calls to create_tree
 *
 * @array: input array of integers
 * @size: size of array
 * Return: pointer to the root
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;
	size_t mdl;

	root = NULL;

	if (size == 0)
		return (NULL);

	mdl = (size / 2);

	mdl = (size % 2 == 0) ? mdl - 1 : mdl;

	root = binary_tree_node(root, array[mdl]);

	create_tree(&root, array, mdl, 1);
	create_tree(&root, array + mdl + 1, (size - 1 - mdl), 2);

	return (root);
}
