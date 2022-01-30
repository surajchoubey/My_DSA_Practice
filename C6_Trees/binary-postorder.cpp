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

void postOrder(struct BinaryTreeNode *root) {

	if(root) {
		postOrder(root -> left);
		postOrder(root -> right);
		printf("%d ", root -> data);
	}
}

void postOrderNonRecursive(struct BinaryTreeNode *root) {
	stack<struct BinaryTreeNode *> st;
	struct BinaryTreeNode *previous = (struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));
	previous = NULL;

	do {

		// traversing to the lefty nodes
		while(root != NULL) {
			st.push(root);
			root = root -> left;
		}

		root = st.top();

		/* 
			traversing to the righty nodes
			if(root -> right == NULL) print that node
			or if(root -> right == previous) print that node `D` because L and R have been traversed in D  
																							           / \
																	                                  L   R
			
			if root -> right is not NULL or it has not been traversed, traverse through root = root -> right																	                                  
		*/
		if(root -> right == NULL || root -> right == previous) {
			printf("%d ", root -> data);
			st.pop();
			previous = root;
			root = NULL;
		} else {
			root = root -> right;
		}
	}while(!st.empty());

}

/*
void postOrderNonRecursive(struct BinaryTreeNode *root) {
	
	stack<struct BinaryTreeNode *> st;
	struct BinaryTreeNode *previous = (struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));

	int p = 10;

	while(true && p--) {

		while(root) {
			st.push(root);
			previous = root;
			root = root -> left;
		}

		if(st.empty()) break;

		root = st.top();
		st.pop();

		printf("%d ", root -> data);

		if(st.top()) {
			root = st.top() -> right;
			printf("%d ", root -> data);
		}
	}

}
*/

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

		POSTORDER TRAVERSAL : 4 2 5 1 6 3 7 (LRD)
	*/

	postOrder(myTree);
	printf("\n");

	postOrderNonRecursive(myTree);
	printf("\n");

	return 0;
}