#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: If no common ancestors return NULL, else return common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *sr, *bd;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	sr = first->parent, bd = second->parent;
	if (first == bd || !sr || (!sr->parent && bd))
		return (binary_trees_ancestor(first, bd));
	else if (sr == second || !bd || (!bd->parent && sr))
		return (binary_trees_ancestor(sr, second));
	return (binary_trees_ancestor(sr, bd));
}
