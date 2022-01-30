#include<stdio.h>
#include<cstdlib>

struct BinaryTreeNode {
	int data;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;	
};

struct BinaryTreeNode *createNewNode(int data) {
	struct BinaryTreeNode *newNode = (struct BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
	newNode -> data = data;
	newNode -> left = NULL;
	newNode -> right = NULL;

	if(newNode) {
		printf("Node formation of %d successful\n",newNode -> data);
		return newNode;
	} else {
		printf("Node formation of %d failed\n",data);
		return NULL;
	}
}

int main() {

	struct BinaryTreeNode *myTree = createNewNode(1);

	myTree -> left = createNewNode(2);
	myTree -> right = createNewNode(3);

	myTree -> left -> left = createNewNode(4);
	myTree -> left -> right = createNewNode(5);

	myTree -> right -> left = createNewNode(6);
	myTree -> right -> right = createNewNode(7);

	return 0;
}