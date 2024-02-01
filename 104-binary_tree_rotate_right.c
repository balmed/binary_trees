#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Right-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot, *tp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	pivot = tree->left;
	tp = pivot->right;
	pivot->right = tree;
	tree->left = tp;
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

