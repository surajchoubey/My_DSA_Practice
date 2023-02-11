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

void inOrder(struct BinaryTreeNode *root) {

	if(root) {
		inOrder(root -> left);
		printf("%d ", root -> data);
		inOrder(root -> right);
	}
}

void inOrderNonRecursive(struct BinaryTreeNode *root) {
	
	stack<struct BinaryTreeNode *> st;

	while(true) {
		while(root) {
			st.push(root);
			root = root -> left;
		}
		if(st.empty()) break;

		root = st.top();
		printf("%d ", root -> data);
		st.pop();
		root = root -> right;
		// if root -> right is NULL while(root) won't run
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

		INORDER TRAVERSAL : 4 2 5 1 6 3 7 (LDR)
	*/

	inOrder(myTree);
	printf("\n");

	inOrderNonRecursive(myTree);
	printf("\n");

	return 0;
}