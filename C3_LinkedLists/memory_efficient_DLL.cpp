#include<iostream>
#include<cinttypes>
using namespace std;

struct Node {
	int data;
	Node *ptrdiff;
};

/*
class Node {
    public : int data;
    // Xor of next node and previous node
    Node* ptrdiff;
};
*/

Node *XOR(Node *x, Node *y) {
	return reinterpret_cast<Node*> (
		reinterpret_cast<uintptr_t>(x) ^ reinterpret_cast<uintptr_t>(y)
	);
}

void insert(Node **head_ref, int data) {

	Node *new_node = new Node();
	new_node -> data = data;
	
	new_node -> ptrdiff = XOR(NULL, (*head_ref));
	
	if((*head_ref) != NULL) {
		(*head_ref) -> ptrdiff = XOR(new_node, (*head_ref)-> ptrdiff);
	}
	
	*head_ref = new_node;

}

void printlist(Node *head_ref) {

	Node *previous = new Node();
	Node *next = new Node();
	Node *current = new Node();
	
	previous = NULL;
	current = head_ref;
	
	while(current != NULL) {
		cout << " <-> " << current->data << " <-> ";
		next = XOR(previous, current -> ptrdiff);
		previous = current;
		current = next;
	}
	
	cout << "\n";

}

int main()
{
    Node* head = NULL;
    Node* behind = NULL;
    insert(&head, 10);
    behind = head;
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
 
    // Printing the created list
    printlist(head);
    printlist(behind);
 
    return (0);
}
