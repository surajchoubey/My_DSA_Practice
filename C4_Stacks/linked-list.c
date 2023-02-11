#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct ListNode {
	int data;
	struct ListNode *next;
};

struct Stack {
	struct ListNode *top;
	int size;
};

struct Stack *createStack() {

	struct Stack *S = (struct Stack *)malloc(sizeof(struct Stack));
		
	if(!S) return NULL;
	else {
		S -> size = 0;
		S -> top = NULL;
	}

	return S;
}

struct ListNode *newListNode(int data) {
	
	struct ListNode *LN = (struct ListNode *)malloc(sizeof(struct ListNode));
	
	if(LN) {
		LN -> data = data;
		LN -> next = NULL;
		return LN;
	}
	else return NULL;
	
}

int isEmpty(struct Stack *S) {
	return (S -> size == 0);
}

int size(struct Stack *S) {
	return (S -> size);
}

void push(struct Stack *S, int data) {
	
	if(isEmpty(S)) {
		struct ListNode *temp = newListNode(data);
		S -> top = temp;
		S -> size++;
		printf("Element %d successfully inserted into the stack\n", data);
	} else { 
		struct ListNode *temp = newListNode(data);
		temp -> next = S -> top;
		S -> top = temp;
		S -> size++;
		printf("Element %d successfully inserted into the stack\n", data);
	}
}

int pop(struct Stack *S) {
	
	if(isEmpty(S)) {
		printf("Stack is empty!\n");
		return INT_MIN;
	} else { /* Removing element from the top and reducing it by -1 */
		int popper = S -> top -> data;
		struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
		temp = S -> top;
		S -> top = S -> top -> next;
		temp -> next = NULL;
		free(temp);
		S -> size--;
		return popper;
	}
}

int peek(struct Stack *S) {
	
	if(isEmpty(S)) {
		printf("Stack is empty!\n");
		return INT_MIN;
	} else {
		return (S -> top -> data);
	}
}

void deleteStack(struct Stack *S) {
	if(S && S -> top && S -> size > 0) {

		printf("---------------------> Stack deletion using deleteStack()\n");
		
		while(S -> size) {
			printf("Popped element is %d \(from using deleteStack())\n", pop(S));
		}
		
		if(S -> size == 0) 
			printf("Stack deletion successful!\n");
		else 
			printf("Stack deletion failed!\n");
	} else {
		printf("Stack deletion failed!\n");
	}
}

void printStack(struct Stack *S) {

	if(S && S -> top && S -> size > 0) {
		int i;
		struct ListNode *current = (struct ListNode *)malloc(sizeof(struct ListNode));
		current = S -> top;
		while(current) {
			printf("%d <- ", current -> data);
			current = current -> next;
		}
		
		printf("\n");
		
	} else {
		printf("Stack is empty");
	}
	printf("\n");
	
}

int main() {

	int i = 0;
	
	// create a stack of capacity 15
	struct Stack *stk = createStack();
	
	for(i = 5; i <= 19; i++) {
		push(stk,i);
	}
	
	printStack(stk);
	
	printf("Top element is %d\n", peek(stk));
	printf("Stack size %d\n", size(stk));
	
	for(i = 0; i <= 7; i++) {
		printf("Popped element is %d\n", pop(stk));
	}
	
	printf("Top element is %d\n", peek(stk));
	printStack(stk);
	printf("Stack size %d\n", size(stk));
	
	int p = 78;
	
	for(i = 0; i <= 7; i++) {
		push(stk,p++);
	}
	
	printf("Top element is %d\n", peek(stk));
	printStack(stk);
	printf("Stack size %d\n", size(stk));
	
	
	if(isEmpty(stk)) {
		printf("Stack is empty (from main)\n");
	} else {
		printf("Stack is not empty(from main)\n");
	}
	
	printf("Top element is %d\n", peek(stk));
	printStack(stk);
	printf("Stack size %d\n", size(stk));
	
	deleteStack(stk);
	
	printf("Stack size %d\n", size(stk));
	printStack(stk);

	return 0;
}




























