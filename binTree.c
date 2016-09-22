#include <stdio.h>
#include <stdlib.h>

// Node struct for BST
typedef struct node {
    int size;
    struct node* left;
    struct node* right;
} node;


int search(node* root, node* nodeToFind);

/* Functions to implement
int* calculateNeighbor(node* root, node* n);
void insert(node* root, int free_size);
void remove(node* root, node* nodeToRemove);
void partition(node* root, int alloc_size);
*/


// Recursive search function. 
// Returns 1 if node input is fount in tree, 0 otherwise.

int search(node* root, node* nodeToFind) {
    // Base case: empty tree. Node not found.
    node* current = root;
    if (current == NULL) {
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



int main(){
    node* root = malloc(300);
    root->size = 20;
    root->parent = NULL;
    root->right = NULL;
    root->left = NULL;

    node* c1 = malloc(300);
    root->size = 10;
    root->parent = root;
    root->right = NULL;
    root->left = NULL;

    node* c2 = malloc(300);
    root->size = 30;
    root->parent = root;
    root->right = NULL;
    root->left = NULL;

    root->left = c1;
    root->right = c2



    //insert(root, 280);
    //printf("Right child size is: %d\n", (root->right)->size);
    //heap_partition(root, 29);
    return 0;
}
