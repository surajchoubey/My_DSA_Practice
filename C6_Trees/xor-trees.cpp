#include<iostream>
#include<cinttypes>
#include<typeinfo>
using namespace std;

struct XORtreesNode {
	char data;
	XORtreesNode *leftdiff;
	XORtreesNode *rightdiff;
};

XORtreesNode *createNode(char data) {
	XORtreesNode *temp = new XORtreesNode();
	temp -> data = data;
	temp -> leftdiff = NULL;
	temp -> rightdiff = NULL;
	return temp;
}

XORtreesNode *XOR(XORtreesNode *x, XORtreesNode *y) {
	return reinterpret_cast<XORtreesNode*> (
		reinterpret_cast<uintptr_t>(x) ^ reinterpret_cast<uintptr_t>(y)
	);
}

void insertRight(XORtreesNode **head_ref, XORtreesNode **new_xor_node) {

	(*head_ref) -> rightdiff = XOR(*new_xor_node, *head_ref);
	(*new_xor_node) -> leftdiff = XOR(NULL, *head_ref);
	(*new_xor_node) -> rightdiff = XOR(NULL, *head_ref);
}


void insertLeft(XORtreesNode **head_ref, XORtreesNode **new_xor_node) {

	(*head_ref) -> leftdiff = XOR(*new_xor_node, *head_ref);
	(*new_xor_node) -> leftdiff = XOR(NULL, *head_ref);
	(*new_xor_node) -> rightdiff = XOR(NULL, *head_ref);
}

// print XOR trees sometime in future

int main() {
	
	XORtreesNode *A = createNode('A');
	XORtreesNode *B = createNode('B');
	XORtreesNode *C = createNode('C');
	XORtreesNode *D = createNode('D');
	XORtreesNode *E = createNode('E');
	XORtreesNode *F = createNode('F');
	XORtreesNode *G = createNode('G');

	insertLeft(&A,&B);
	insertRight(&A,&C);

	insertLeft(&B,&D);
	insertRight(&B,&E);

	insertLeft(&C,&F);

	insertLeft(&E,&G);

	// printXORtrees(A);

	printf("\n");
	return 0;
}