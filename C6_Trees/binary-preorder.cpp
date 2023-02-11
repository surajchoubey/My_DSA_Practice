#include<iostream>
#include<stack>
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

void preOrder(struct BinaryTreeNode *root) {

	if(root) {
		printf("%d ", root -> data);
		preOrder(root -> left);
		preOrder(root -> right);
	}
}

void preOrderNonRecursive(struct BinaryTreeNode *root) {
	
	stack<struct BinaryTreeNode *> st;

	while(true) {
		while(root) {
			printf("%d ", root -> data);
			st.push(root);
			root = root -> left;
		}
		if(st.empty()) break;

		root = st.top();
		st.pop();
		root = root -> right;
	}

	while(!st.empty()) st.pop();

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

		PREORDER TRAVERSAL : 1 2 4 5 3 6 7 (DLR)
	*/

	preOrder(myTree);
	printf("\n");

	preOrderNonRecursive(myTree);
	printf("\n");

	return 0;
}