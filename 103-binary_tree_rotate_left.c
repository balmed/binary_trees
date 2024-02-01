#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Left-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot, *tp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	pivot = tree->right;
	tp = pivot->left;
	pivot->left = tree;
	tree->right = tp;
	if (tp != NULL)
		tp->parent = tree;
	tp = tree->parent;
	tree->parent = pivot;
	pivot->parent = tp;
	if (tp != NULL)
	{
		if (tp->left == tree)
			tp->left = pivot;
		else
			tp->right = pivot;
	}

	return (pivot);
}
