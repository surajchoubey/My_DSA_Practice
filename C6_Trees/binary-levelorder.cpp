#include<iostream>
#include<queue>
using namespace std;

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

void levelOrder(struct BinaryTreeNode *root) {

	if(!root)
		return;
	else {
		queue<struct BinaryTreeNode *> Q;
		struct BinaryTreeNode *temp = (struct BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));

		Q.push(root);

		while(!Q.empty()) {
			temp = Q.front();
			printf("%d ", temp -> data);
			Q.pop();

			if(temp -> left) {
				Q.push(temp -> left);
			}
			if(temp -> right) {
				Q.push(temp -> right);
			}
		}
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



	/*
		tree formed here
			   1
			 /   \
			2	  3
		   / \	 / \
		  4	  5 6	7

		LEVELORDER TRAVERSAL : 1 2 3 4 5 6 7
	*/

	levelOrder(myTree);
	printf("\n");

	return 0;
}