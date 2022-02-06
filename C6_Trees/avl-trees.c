/* Adelson's Velskii and Landis Trees */
/* It is a BST, and at any node, the difference between the left subtree and the right subtree is at most 1 */

#include<stdio.h>
#include<stdlib.h>

int max(int p, int q) {
	if(p > q) return p;
	else return q;
}

struct AVLTreeNode {
	int key;
	struct AVLTreeNode *left;
	struct AVLTreeNode *right;
	int height;
};

int height(struct AVLTreeNode *root) {

	if(!root) return -1;
	else return root -> height;
}

struct AVLTreeNode *createNode(int key) {

	struct AVLTreeNode *newNode = (struct AVLTreeNode *)malloc(sizeof(struct AVLTreeNode));

	newNode -> left = NULL;
	newNode -> right = NULL;
	newNode -> key = key;
	newNode -> height = 0;

	if(newNode) {
		printf("Node creation successful for data = %d!\n", key);
		return newNode;
	} else {
		printf("Node creation failed!\n");
		return NULL;
	}

}
 
// Get Balance factor of node N
int getBalance(struct AVLTreeNode *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// SINGLE ROTATIONS

// Left Left Rotation
// Make left child as the root child
struct AVLTreeNode *leftRotate(struct AVLTreeNode *X) {

	struct AVLTreeNode *W = X -> right;
	X -> right = W -> left;
	W -> left = X;

	X -> height = max(height(X -> left), height(X -> right)) + 1;
	W -> height = max(height(W -> left), height(W -> right)) + 1;

	return W;
}

// Right Right Rotation
// Make right child as the root child
struct AVLTreeNode *rightRotate(struct AVLTreeNode *X) {

	struct AVLTreeNode *W = X -> left;
	X -> left = W -> right;
	W -> right = X;

	X -> height = max(height(X -> left), height(X -> right)) + 1;
	W -> height = max(height(W -> left), height(W -> right)) + 1;

	return W;
}

// INSERTION INTO AN AVL TREE
struct AVLTreeNode *insertIntoAVL(struct AVLTreeNode* node, int key)
{
    /* 1.  Perform the normal BST insertion */
    if (node == NULL)
        return(createNode(key));
 
    if (key < node->key)
        node->left  = insertIntoAVL(node->left, key);
    else if (key > node->key)
        node->right = insertIntoAVL(node->right, key);
    else // Equal keys are not allowed in BST
        return node;
 
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),
                           height(node->right));
 
    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = getBalance(node);
 
    // If this node becomes unbalanced, then
    // there are 4 cases
 
    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
 
    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
 
    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
		node -> left = leftRotate(node -> left);
		return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
		node -> right = rightRotate(node -> right);
		return leftRotate(node);
    }
 
    /* return the (unchanged) node pointer */
    return node;
}


void inOrder(struct AVLTreeNode *root) {

	if(root) {
		inOrder(root -> left);
		printf("%d ", root -> key);
		inOrder(root -> right);
	}
}

int main() {

	struct AVLTreeNode *mytree = createNode(10);
	mytree = insertIntoAVL(mytree, 8);
	mytree = insertIntoAVL(mytree, 9);
	mytree = insertIntoAVL(mytree, 5);
	mytree = insertIntoAVL(mytree, 6);
	mytree = insertIntoAVL(mytree, 11);
	mytree = insertIntoAVL(mytree, 4);
	mytree = insertIntoAVL(mytree, 3);
	mytree = insertIntoAVL(mytree, 2);
	mytree = insertIntoAVL(mytree, 1);

	inOrder(mytree); printf("\n");
	return 0;
}

// Rotations are performed in an AVL Tree in order to restore the AVL tree property
/*

*/