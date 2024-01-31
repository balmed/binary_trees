#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t gh = 0, dt = 0;

		gh = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		dt = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((gh > dt) ? gh : dt);
	}
	return (0);
}
