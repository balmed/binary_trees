#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the size of.
 *
 * Return: The size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t s_tree = 0;

	if (tree)
	{
		s_tree += 1;
		s_tree += binary_tree_size(tree->left);
		s_tree += binary_tree_size(tree->right);
	}
	return (s_tree);
}
