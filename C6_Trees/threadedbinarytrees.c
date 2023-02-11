/*
	THIS ALL IS MEANT SPECIFICALLY FOR INORDER THREADED BINARY TREE
*/

#include<stdio.h>
#include<stdlib.h>

struct ThreadedBinaryTreeNode {
	struct ThreadedBinaryTreeNode *left;
	int LTag;
	int data;
	int RTag;
	struct ThreadedBinaryTreeNode *right;	
};

struct ThreadedBinaryTreeNode *createNewNode(int data) {
	
	struct ThreadedBinaryTreeNode *newNode = (struct ThreadedBinaryTreeNode *)malloc(sizeof(struct ThreadedBinaryTreeNode));
	// newNode -> LTag = 1;
	// newNode -> RTag = 1;
	newNode -> left = NULL;
	newNode -> right = NULL;
	newNode -> data = data;

	return newNode;
}

// LDR successor
struct ThreadedBinaryTreeNode *inOrderSuccessor(struct ThreadedBinaryTreeNode *P) {

	struct ThreadedBinaryTreeNode *Position;

	if(P -> RTag == 0) {
		return P -> right;
	} else {
		Position = P -> right;
		while(Position -> LTag == 1) {
			Position = Position -> left;
		}
		return Position;
	}
}

// LDR traversal
void TraversalLDR(struct ThreadedBinaryTreeNode *root) {

	struct ThreadedBinaryTreeNode *Position = root;

	// to find the leftmost node
	while(Position -> LTag) Position = Position -> left;

	while(Position != NULL) {
		printf("%d ", Position -> data);
		Position = inOrderSuccessor(Position);
	}
	printf("\n");
}

// DLR successor
struct ThreadedBinaryTreeNode *preOrderSuccessor(struct ThreadedBinaryTreeNode *P) {

	struct ThreadedBinaryTreeNode *Position;

	if(P -> LTag == 1) {
		return P -> left;
	} else {
		Position = P;
		while(Position -> RTag == 0) {
			Position = Position -> right;
		}
		return Position -> right;
	}
}

// DLR traversal
void TraversalDLR(struct ThreadedBinaryTreeNode *root) {

	struct ThreadedBinaryTreeNode *rightMost = root, *Position = root;

	// to find the rightmost node
	while(rightMost -> RTag) rightMost = rightMost -> right;

	while(Position != rightMost) {
		printf("%d ", Position -> data);
		Position = preOrderSuccessor(Position);
	}
	printf("%d \n", rightMost -> data);

}

void insertionRight(struct ThreadedBinaryTreeNode *P, int data) {

	struct ThreadedBinaryTreeNode *Q = createNewNode(data);
	struct ThreadedBinaryTreeNode *temp;

	Q -> right = P -> right;
	Q -> RTag = P -> RTag;
	Q -> LTag = 0;
	Q -> left = P;
	P -> right = Q;
	P -> RTag = 1;
	
	if(Q -> RTag) {

		temp = Q -> right;
		while(temp -> LTag) {
			temp = temp -> left;
		}
		temp -> left = Q;
	}

	// printf("For data = %d, Q -> RTag = %d, Q -> LTag = %d, P -> LTag = %d\n", data, Q -> RTag, Q -> LTag, P -> RTag);
}

void insertionLeft(struct ThreadedBinaryTreeNode *P, int data) {

	struct ThreadedBinaryTreeNode *Q = createNewNode(data);
	struct ThreadedBinaryTreeNode *temp;

	Q -> left = P -> left;
	Q -> LTag = P -> LTag;
	Q -> RTag = 0;
	Q -> right = P;
	P -> LTag = 1;
	P -> left = Q;
	
	if(Q -> LTag) {
		temp = Q -> left;

		while(temp -> RTag) {
			temp = temp -> right;
		}
		temp -> right = Q;
	}

	// printf("For data = %d, Q -> RTag = %d, Q -> LTag = %d, P -> LTag = %d\n", data, Q -> RTag, Q -> LTag, P -> LTag);

}

int main() {
	
	struct ThreadedBinaryTreeNode *start = createNewNode(1);
	insertionLeft(start, 5);
	insertionRight(start, 11);
	insertionLeft(start -> left, 2);
	insertionRight(start -> left, 3);
	insertionRight(start -> right, 31);
	insertionLeft(start -> right, 16);


	TraversalLDR(start);

	TraversalDLR(start);

	return 0;
}
