#include "binary_trees.h"
#include "10-binary_tree_depth.c"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if not found
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
										const binary_tree_t *second)
{
	int diff;

	if (first && second)
	{
		diff = binary_tree_depth(first) - binary_tree_depth(second);
		if (diff < 0)
		{
			diff *= -1;
			while (diff--)
				second = second->parent;
		}
		else
		{
			while (diff--)
				first = first->parent;
		}
		while (first)
		{
			if (first == second)
				return ((binary_tree_t *) first);
			first = first->parent;
			second = second->parent;
		}
	}
	return (NULL);
}