/* Binary Search Tree */

#include<stdio.h>
#include<stdlib.h>

struct BSTNode {
	int data;
	struct BSTNode *left;
	struct BSTNode *right;	
};

// create BSTNode 
struct BSTNode *createNode(int element) {
	struct BSTNode *newNode = (struct BSTNode *)malloc(sizeof(struct BSTNode));
	newNode -> data = element;
	newNode -> left = NULL;
	newNode -> right = NULL;

	if(newNode) return newNode;
	else {
		printf("Node creation failed\n");
		return NULL;
	}
}

// Searching an element in the BST - non recursive style
int find(struct BSTNode *root, int element) {

	struct BSTNode *temp = root;

	while(temp != NULL) {
		if(temp -> data > element) temp = temp -> left;
		else if(temp -> data < element) temp = temp -> right;
		else return temp -> data;
	}

	return -1;
}

// Searching an element in the BST - recursive style
int find_recursive(struct BSTNode *root, int element) {

	if(root == NULL) return -1;
	else if (root -> data > element) return find_recursive(root -> left, element);
	else if (root -> data < element) return find_recursive(root -> right, element);
	else return root -> data;
}

// finding minimum element
int findMin(struct BSTNode *root) {
	if(root == NULL) return -1;
	else {
		while(root -> left != NULL) {
			root = root -> left;
		}
	}
	return root -> data;
}

// finding minimum element - recursive style
int findMin_recursive(struct BSTNode *root) {
	if(root == NULL) return -1;
	else if(root -> left) return findMin_recursive(root -> left);
	else return root -> data;
}

// finding maximum element
int findMax(struct BSTNode *root) {
	if(root == NULL) {
		printf("Element not there!\n");
		return -1;

	} else {
		while(root -> right != NULL) {
			root = root -> right;
		}
	}
	return root -> data;
}

// finding maximum element - recursive style
int findMax_recursive(struct BSTNode *root) {
	if(root == NULL) return -1;
	else if(root -> right) return findMax_recursive(root -> right);
	else return root -> data;
}

// insertion of an element in the binary tree
void insert(struct BSTNode **root, int element) {

	struct BSTNode *current = *root;
	struct BSTNode *newNode = createNode(element);

	if(current == NULL) {
		printf("Root node is a failure node\n");
		return;
	} else {
		while(current) {
			if (current -> data > newNode -> data) {
				if(current -> left) current = current -> left;
				else {
					current -> left = newNode;
					printf("Node insertion successful for %d\n", element);
					return;
				}
			} else if (current -> data < newNode -> data) {
				if(current -> right) current = current -> right;
				else {
					current -> right = newNode;
					printf("Node insertion successful for %d\n", element);
					return;
				}
			} else {
				printf("Cannot insert in element already in the Binary Search Tree\n");
				free(newNode);
				return;
			}
		}
	}
}

// insertion of an element in the binary tree - recursive style
void insert_recursive(struct BSTNode **current, int element) {

	struct BSTNode *root = (*current);

	if(root == NULL) {
		return;
	} else {
		if (root -> data > element) {
			if(root -> left) insert_recursive(&(root -> left), element);
			else root -> left = createNode(element);
		} else if (root -> data < element) {
			if(root -> right) insert_recursive(&(root -> right), element);
			else root -> right = createNode(element);
		} else {
			printf("Cannot insert in element already in the Binary Search Tree %d , %d \n", root -> data, element);
			return;
		}
	}
}

void inOrder(struct BSTNode *root) {

	if(root) {
		inOrder(root -> left);
		printf("%d ", root -> data);
		inOrder(root -> right);
	}
}

struct BSTNode *Temp = NULL;

// Searching an element in the BST - non recursive style
struct BSTNode *find_memory_block(struct BSTNode *root, int element) {

	struct BSTNode *temp = root;

	while(temp != NULL) {

		if(temp -> data > element) { Temp = temp; temp = temp -> left; }
		else if(temp -> data < element) { Temp = temp; temp = temp -> right; }
		else return temp;
	}

	return NULL;
}

/*
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root) {
            if(key < root -> val) {
                root -> left = deleteNode(root -> left, key);
            } else if(key > root -> val) {
                root -> right = deleteNode(root -> right, key);
            } else {
                
                // No child condition
                if(root -> left == NULL && root -> right == NULL) return NULL;
                
                // One child condition replace the node with its child
                if(root -> left == NULL || root -> right == NULL) return root -> left ? root -> left : root -> right;
                
                // Two child condition
                TreeNode *temp = root -> left;
                while(temp -> right != NULL)  temp = temp -> right; 
                // closely look here: go left once and then right right right to store its precedessor
                // store the predecessor in temp and root -> val = root -> predecessor -> val
                // delete the predecessor node as it has no child
                root -> val = temp -> val;
                root -> left = deleteNode(root -> left, temp -> val);
            }
        }
        return root;
    }
*/


void deleteNode(struct BSTNode **root, int element) {

	struct BSTNode *toDelete = find_memory_block(*root, element);

	// inOrder(head); printf("\n");

	if(toDelete == NULL) { 
		printf("Element not found\n");
		return;
	} else if(toDelete -> left && toDelete -> right) {

		toDelete -> data = findMax(toDelete -> left);
		deleteNode(&(toDelete -> left), toDelete -> data);

	} else if (toDelete -> left || toDelete -> right) {

		Temp = toDelete;
		if(toDelete -> left) {
			toDelete -> data = toDelete -> left -> data;
			deleteNode(&(toDelete -> left), toDelete -> data);
		} else if(toDelete -> right) {
			toDelete -> data = toDelete -> right -> data;
			deleteNode(&(toDelete -> right), toDelete -> data);
		}
		
	} else {

		if(Temp) { Temp -> left = NULL; Temp -> right = NULL; free(toDelete); }
		else printf("Deletion error\n");
		
	}

}


int main() {

	// test all your code here
	struct BSTNode *myNode = createNode(10);

	// insert(&myNode, 5);
	// insert(&myNode, 6);
	// insert(&myNode, 4);
	// insert(&myNode, 7);
	// insert(&myNode, 3);
	// insert(&myNode, 8);	
	// insert(&myNode, 2);

	// insert(&myNode, 15);
	// insert(&myNode, 16);
	// insert(&myNode, 14);
	// insert(&myNode, 17);
	// insert(&myNode, 13);
	// insert(&myNode, 18);	
	// insert(&myNode, 12);

	insert_recursive(&myNode, 5);
	insert_recursive(&myNode, 6);
	insert_recursive(&myNode, 4);
	insert_recursive(&myNode, 7);
	insert_recursive(&myNode, 3);
	insert_recursive(&myNode, 8);	
	insert_recursive(&myNode, 2);
	insert_recursive(&myNode, 15);
	insert_recursive(&myNode, 16);
	insert_recursive(&myNode, 14);
	insert_recursive(&myNode, 17);
	insert_recursive(&myNode, 13);
	insert_recursive(&myNode, 18);	
	insert_recursive(&myNode, 12);
	
	inOrder(myNode); printf("\n");

	printf("Max element = %d\n", findMax(myNode));
	printf("Min element = %d\n", findMin(myNode));
	printf("Max element recursive = %d\n", findMax_recursive(myNode));
	printf("Min element recursive = %d\n", findMin_recursive(myNode));

	printf("find(18) = %d\n", find(myNode, 18));
	printf("find(8) = %d\n", find(myNode, 8));
	printf("find(2) = %d\n", find(myNode, 15));
	printf("find(1) = %d\n", find(myNode, 1));

	printf("find_recursive(18) = %d\n", find_recursive(myNode, 18));
	printf("find_recursive(8) = %d\n", find_recursive(myNode, 8));
	printf("find_recursive(2) = %d\n", find_recursive(myNode, 15));
	printf("find_recursive(1) = %d\n", find_recursive(myNode, 1));

	inOrder(myNode); printf("\n");
	deleteNode(&myNode, 15);
	printf("\nAfter deletion: \nfind_recursive(15) = %d\n", find_recursive(myNode, 15));
	inOrder(myNode); printf("\n");


	inOrder(myNode); printf("\n");
	deleteNode(&myNode, 5);
	printf("\nAfter deletion: \nfind_recursive(15) = %d\n", find_recursive(myNode, 15));
	inOrder(myNode); printf("\n");

	return 0;
}