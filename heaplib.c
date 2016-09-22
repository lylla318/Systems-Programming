#include <stdlib.h>
#include <stdio.h>
#include "heaplib.h"

/*
 * Include a description of your approach here.
 *
 */



/* Implementation of Binary Search Tree */



// test search(), insert(), remove(), calculateNeighbor() 

// hard part: partition() and adding coalescing algorithm to insert()


// Node struct for BST
typedef struct node {
    int size;
    struct node* parent;
    struct node* left;
    struct node* right;
} node;

int search(node* root, node* nodeToFind);
int* calculateNeighbor(node* root, node* n);
void insert(node* root, int free_size);
void remove(node* root, node* nodeToRemove);
void partition(node* root, int alloc_size);

// insert new free block into its proper place in the tree
// returns unchanged node ptr.
// CHANGE WHEN NAIVE TREE IMPLEMENTATION WORKS: ADD COALESCING HERE
struct node* insert (struct node* node, int alloc_size) {
	// create a new node
	struct node* newNode = new(struct node);
	newNode->size = alloc_size;
	newNode->left = NULL;
	newNode->right = NULL;

	// if the tree is empty, return the new node
	if (node == NULL) {
		return (newNode);
	}
	else {
		// otherwise recurse down the tree
		if (alloc_size <= node->size) node->left = insert(node->left, alloc_size);
		else node->right = insert(node->right, alloc_size);
		return (node); 

		// COALESCE ALGORITHM
	}
}



// recursive search function, called in remove()
int search (struct node* root, struct node* nodeToFind) {
    // base case: empty tree
    // block not found; return (false);
    struct node* curr = root;
    if (curr == NULL) {
        return 0;
    } else if (nodeToFind == NULL) {
    	return 0;
    } else {
    	if ((curr->size == nodeToFind->size) && (curr->left == nodeToFind->left) 
    		&& (curr->right == nodeToFind->right)) return true;
    	// otherwise recurse down the corrent subtree
    	else {
    		if (nodeToFind->size < curr->size) return (search(curr->left,nodeToFind));
    		else return (search(curr->right, nodeToFind));
    	}
    }
    return 1;
}


void remove (struct node* root, struct node* parent, struct node* nodeToRemove) {
	// remove node
	int found = search(nodeToRemove);
	struct node* curr = root;
	if (root == NULL) { 
		printf("\nEmpty tree.");
		return;
	} else if (found == 0) {
		printf("\nNode not in tree.")
		return;
	} else {
		if (!((curr->size == nodeToRemove->size) && (curr->left == nodeToRemove->left) 
    		&& (curr->right == nodeToRemove->right))) {
    		if (nodeToRemove->size < curr->size) {
    			return (remove(curr->left, curr, nodeToRemove));
    		} else { 
    			return (remove(curr->right, curr, nodeToRemove));
    		}
    	} // Now curr should be the node to remove.

    	// Case 1: the node to delete has 2 children
    	if (curr->left != NULL && curr->right != NULL) {
    		if (parent->left == curr) {
    			next = curr->left
    			while(next != NULL) {
    				parent->left = next
    			}

    		} else {

    		}
    	} // Case 2: the node to delete has no children
    	else if (curr->left == NULL && curr->right == NULL) {
    		if (parent->right == curr) {
    			parent->right = NULL;
    		} else {
    			parent->left = NULL;
    		}
    		return;
    	} // Case 3: the node to delete has 1 right child
    	else if (curr->left == NULL && curr->right != NULL) {
    		if (parent->left == curr) {
    			parent->left = curr->right;
    		} else {
    			parent->right = curr->right;
    		}
    		return;

    	} // Case 4: the node to delete has 1 left child
    	else if (curr->left != NULL && curr->right == NULL) {
    		if (parent->left == curr) {
    			parent->left = x->left;
    		} else {
    			parent->right = curr->left;
    		}
    		return;
    	}
	}
}


// removes "alloc_size" portion from largest block
// returns unchanged node ptr.
struct node* partition (struct node* node, int alloc_size) {
	// find largest free block in the tree
	struct node* current = node;
	while (current->right != NULL) {
		parent = current;
		current = current->right;
	}

	// partition this block
	current->size = current->size - alloc_size;
    void *tmp = (void*) current;
    int meta_data 

    int total_size = (tmp + sizeof(node) + alloc_size) % 8; 

	// remove block from tree

	// insert first new block

	// insert second new block


}

void heap_partition (node* root, int alloc_size){
    // Find largest free block in the tree
    node *current = root;
    node *parent  = NULL;
    while (current->right != NULL){
        parent = current;
        current = current->right;
    }
    // Partition the current block (decrease free size)
    current->size = current->size - alloc_size;
    // Change parent's pointer to the new location of the current free block
    size_t addr = (size_t) parent->right;
    size_t beg = addr;
    printf("Base address is %zx\n", addr);
    addr += 12;
    printf("Base address + header is %zx\n", addr);
    int padding = addr % 8;
    printf("Padding required is %d\n", padding);
    if (padding != 0){
        addr += padding;
    }
    addr += alloc_size + 8;
    printf("Base address + header + padding + alloc_size is %zx\n", addr);
    padding = addr % 8;
    printf("Padding required is %d\n", padding);
    if (padding != 0){
        addr -= padding;
    }
    size_t end = addr;
    // Update parent pointer
    printf("Final address is %zx\n", addr);
    printf("difference is %zd", end - beg);
    parent->right = (node*) (addr + 1);
}



int hl_init(void *heapptr, unsigned int heap_size) {

	// initialize the tree
	// we do this by initializing the root and setting up its data values
	// every node in the tree has three attributes: size, left, and right


	// make the tree 8 byte aligned!

	return 0; // Failed

}

void *hl_alloc(void *heapptr, unsigned int block_size) {

	// call partition(heapptr, block_size)
	// 

	return NULL; // Failed

}

void hl_release(void *heapptr, void *blockptr) {

	// 

}

void *hl_resize(void *heapptr, void *blockptr, unsigned int new_block_size) {

	//
  	
  	return NULL; // Failed

}








