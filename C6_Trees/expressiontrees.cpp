#include<iostream>
#include<stack>
#include<queue>
using namespace std;

struct BinaryTreeNode {
	char data;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;	
};

struct BinaryTreeNode *createNewNode(char data) {
	struct BinaryTreeNode *newNode = (struct BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
	newNode -> data = data;
	newNode -> left = NULL;
	newNode -> right = NULL;

	if(newNode) return newNode;
	else return NULL;
}

struct BinaryTreeNode *buildExprTree(char postfixExpr[], int size) {

	stack<struct BinaryTreeNode *> st;
	BinaryTreeNode *temp = NULL;

	for(int i = 0; i < size; i++) {

		temp = createNewNode(postfixExpr[i]);

		if(postfixExpr[i] <= 'Z' && postfixExpr[i] >= 'A') {
			st.push(temp);
		} else {
			temp -> right = st.top();
			st.pop();
			temp -> left = st.top();
			st.pop();

			st.push(temp);
		}
	}

	temp = st.top();
	return temp;
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
			printf("%c ", (char)temp -> data);
			Q.pop();

			if(temp -> left) {
				Q.push(temp -> left);
			}
			if(temp -> right) {
				Q.push(temp -> right);
			}
		}
	}
	printf("\n");
}

int main() {

	char postfix[] = "ACB*+D/";

	BinaryTreeNode *tree = buildExprTree(postfix,7);

	levelOrder(tree);

	return 0;

}