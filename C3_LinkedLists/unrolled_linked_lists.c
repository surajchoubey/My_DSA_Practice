/*
	For your reference refer to the Narusimha Karumanchi book Pg59
*/
  
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include<time.h>

int blocksize = 5; // max number of nodes in a block

struct LinkedBlock {
	struct ListNode *head;
	struct LinkedBlock *next;
	int nodeCount;
};

struct ListNode {
	struct ListNode *next;
	int data;
};

struct LinkedBlock *newLinkedBlock() {
	struct LinkedBlock *newBlock = (struct LinkedBlock *)malloc(sizeof(struct LinkedBlock));
	newBlock -> head = NULL;
	newBlock -> next = NULL;
	newBlock -> nodeCount = 0;
	return newBlock;
}

struct LinkedBlock *blockhead;

struct ListNode *newListNode(int data) {
	struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
	newNode -> next = NULL;
	newNode -> data = data;
	return newNode;
}

/*
	in searchElement() method we traverse through the unrolled linked list and check if we are able to find the element (or its occurence)
*/

void searchElement(int k, struct LinkedBlock **fLinkedBlock, struct ListNode **fListNode) {
	
	// find the block
	// ceil(x/y) = (x + y - 1)/y
	int j = (k + blocksize - 1)/blocksize;	
	struct LinkedBlock *p = (struct LinkedBlock *)malloc(sizeof(struct LinkedBlock));
	p = blockhead;
	while(--j && p -> next != NULL) p = p -> next;	
	*fLinkedBlock = p;
	
	// find the node	
	struct ListNode *q= (struct ListNode *)malloc(sizeof(struct ListNode));
	q = p -> head;	
	k = k % blocksize;
	if(k == 0) k = blocksize;	
	
	k = p -> nodeCount - k + 1;
	
	while(k--) q = q -> next;	
	*fListNode = q;
}

/*
	start shift operation from block *p
	*p is the main block from which the unrolled linked list actually points to
*/
void shift(struct LinkedBlock *A) {
	
	struct LinkedBlock *B = newLinkedBlock();
	struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
	
	while(A -> nodeCount > blocksize) {
		
		if(A -> next == NULL) {
			A -> next = newLinkedBlock();
			B = A -> next;
			temp = A -> head -> next; // temp stores the 2nd listnode from A
			
			A -> head -> next = A -> head -> next -> next; // 1st listnode points to 3rd listNode in A
			B -> head = temp; // temp is assigned as B -> head
			temp -> next = temp; // temp will now point to itself
			
			A -> nodeCount--;
			B -> nodeCount++;
			
		} else {
			B = A -> next;
			
			temp = A -> head -> next; // temp stores the 2nd listnode from A
			A -> head -> next = A -> head -> next -> next; // 1st listnode points to 3rd listNode in A
			
			temp -> next = B -> head -> next; // temp points to 2nd listnode in B
			B -> head -> next = temp; // 1st listnode in B points to temp
			B -> head = temp; // temp is assigned as B -> head
			
			A -> nodeCount--;
			B -> nodeCount++;
			
		}
		
		B = A;
	
	}

}


/*	
	To add an element in the list
	While adding an element in here you need to ensure if you add an element in the empty block it is easy
	You also need to carry out the shifting operations if one block is of more size than the preferred size of the block
*/
void addElement(int k, int value) {
	struct ListNode *p,*q;
	struct LinkedBlock *r;

	if(!blockhead) { // initial, firstnode and block
		blockhead = newLinkedBlock();
		blockhead -> head = newListNode(value);
		// blockhead -> next = NULL; // redundant line
		blockhead -> head -> next = blockhead -> head;
		blockhead -> nodeCount++;
	} else {
		if(k == 0) { // special case for k = 0
			p = blockhead -> head;
			q = p -> next;
			p -> next = newListNode(value);
			p -> next -> next = q;
			blockhead -> head = p -> next;
			blockhead -> nodeCount++;
			shift(blockhead);
		} else {
			searchElement(k, &r, &p);
			q = p;
			while(q -> next != p) q = q-> next;
			q -> next = newListNode(value);
			q -> next -> next = p;
			r -> nodeCount++;
			shift(r);
		}
	}
}


// to search the elements in the unrolled linked list
int Search(int k) {
	struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct LinkedBlock *q = newLinkedBlock();
	searchElement(k, &q, &p);
	return p -> data;
}

void Print() {
	
	struct LinkedBlock *p = newLinkedBlock();
	struct ListNode *q = (struct ListNode *)malloc(sizeof(struct ListNode));
	p = blockhead;
	
	printf("\nElements of the Unrolled Linked Lists are: \n");
	
	 while(p) {
		q = p -> head;
		do {
			printf("%d -> ", q -> data);
			q = q -> next;
		}while(q != p -> head);
		p = p -> next;
		printf("\n");
	}
	
}

// for carrying out the test operations
int main() {
	
	/* All the main operations on the unrolled linked list are meant to be carried out here */
	/* int testUnrolledLinkedList() test it right here */
	 
		
	*/
	
	addElement(1, 1);
	Print();
	addElement(2, 2);
	Print();
	addElement(3, 3);
	Print();
	addElement(4, 4);
	Print();
	addElement(5, 5);
	Print();
	addElement(6, 6);
	Print();
	addElement(7, 8);
	Print();
	addElement(8, 7);
	Print();
	addElement(3, 8);
	Print();
	addElement(4, 9);
	Print();
	addElement(5, 10);
	Print();
	addElement(6, 11);
	Print();
	addElement(7, 12);
	Print();
	addElement(8, 13);
	Print();
	return 0;
}

