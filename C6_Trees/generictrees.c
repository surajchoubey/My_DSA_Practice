#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
	int data;
	struct TreeNode *firstChild;
	struct TreeNode *nextSibling;
};

struct TreeNode *createNewNode(int data) {

	struct TreeNode *temp = (struct TreeNode *)malloc(sizeof(struct TreeNode));

	temp -> data = data;

	if(temp) {
		printf("Node formation successful!\n");
		return temp;
	} else  {
		printf("Node formation failed!\n");
		return NULL;
	}

}

void traverse(struct TreeNode *element) {

	if (element == NULL) return;
	else {
		printf("%d\n", element -> data);
		traverse(element -> firstChild);
		traverse(element -> nextSibling);
	}
}

int main() {

	// 1 is super ancestor
	struct TreeNode *GTree = createNewNode(1);

	// children of 1 are 2,3,4
	GTree -> firstChild = createNewNode(2);
	GTree -> firstChild -> nextSibling = createNewNode(3);
	GTree -> firstChild -> nextSibling -> nextSibling = createNewNode(4);

	// children of 2 are 6,7
	GTree -> firstChild -> firstChild = createNewNode(6);
	GTree -> firstChild -> firstChild -> nextSibling = createNewNode(7);

	// children of 3 are 8,9
	GTree -> firstChild -> nextSibling -> firstChild = createNewNode(8);
	GTree -> firstChild -> nextSibling -> firstChild -> nextSibling = createNewNode(9);

	// children of 4 are 10,11
	GTree -> firstChild -> nextSibling -> nextSibling -> firstChild = createNewNode(10);
	GTree -> firstChild -> nextSibling -> nextSibling -> firstChild -> nextSibling = createNewNode(11);

	traverse(GTree);

	return 0;
}