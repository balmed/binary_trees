#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *curr, *n_node;

	if (tree != NULL)
	{
		curr = *tree;

		if (curr == NULL)
		{
			n_node = binary_tree_node(curr, value);
			if (n_node == NULL)
				return (NULL);
			return (*tree = n_node);
		}

		if (value < curr->n) /* insert in left subtree */
		{
			if (curr->left != NULL)
				return (bst_insert(&curr->left, value));

			n_node = binary_tree_node(curr, value);
			if (n_node == NULL)
				return (NULL);
			return (curr->left = n_node);
		}
		if (value > curr->n) /* insert in right subtree */
		{
			if (curr->right != NULL)
				return (bst_insert(&curr->right, value));

			n_node = binary_tree_node(curr, value);
			if (n_node == NULL)
				return (NULL);
			return (curr->right = n_node);
		}
	}
	return (NULL);
}

