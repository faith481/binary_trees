#include "binary_trees.h"

// Structure for a node in BST
typedef struct bst_node {
    int value;
    struct bst_node *left;
    struct bst_node *right;
} bst_t;

// Function to find the minimum value node in a BST
bst_t *find_min(bst_t *node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

// Function to remove a node from BST
bst_t *bst_remove(bst_t *root, int value) {
    if (root == NULL) // Base case: tree is empty or value not found
        return NULL;
    
    if (value < root->value) // If value is smaller, go left
        root->left = bst_remove(root->left, value);
    else if (value > root->value) // If value is greater, go right
        root->right = bst_remove(root->right, value);
    else { // Value found, remove this node
        // Case 1: Node has no children or only one child
        if (root->left == NULL) {
            bst_t *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            bst_t *temp = root->left;
            free(root);
            return temp;
        }
        
        // Case 2: Node has two children
        bst_t *temp = find_min(root->right); // Find in-order successor
        root->value = temp->value; // Copy the successor's value to this node
        root->right = bst_remove(root->right, temp->value); // Remove the successor
    }
    return root;
}
