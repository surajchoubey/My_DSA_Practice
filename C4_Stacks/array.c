#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Stack {
	int top;
	int capacity;
	int *array;
};

struct Stack *createStack(int capacity) {

	struct Stack *S = (struct Stack *)malloc(sizeof(struct Stack));
	
	if(!S) return NULL;
	
	S -> capacity = capacity;
	S -> top = -1;
	S -> array = malloc(sizeof(int) * S -> capacity);
	
	if(!S -> array) return NULL;
	
	return S;
}

int isEmpty(struct Stack *S) {
	return (S -> top == -1);
}

int size(struct Stack *S) {
	return (S -> top + 1);
}

int isFull(struct Stack *S) {
	return (S -> top == S -> capacity - 1);
}

void push(struct Stack *S, int data) {
	/* S -> top == -1 indicates empty stack */
	
	if(isFull(S)) {
		printf("Stack overflow!\n");
		return;
	} else { /* Increasing the top by 1 and storing the value at top bottom */
		S -> array[++S -> top] = data;
		printf("Element %d successfully inserted into the stack\n", data);
	}
}

int pop(struct Stack *S) {
	/* S -> top == -1 indicates empty stack */
	
	if(isEmpty(S)) {
		printf("Stack is empty!\n");
		return INT_MIN;
	} else { /* Removing element from the top and reducing it by -1 */
		return (S -> array[S -> top--]);
	}
}

int peek(struct Stack *S) {
	/* S -> top == -1 indicates empty stack */
	
	if(isEmpty(S)) {
		printf("Stack is empty!\n");
		return INT_MIN;
	} else {
		return (S -> array[S -> top]);
	}
}

void deleteStack(struct Stack *S) {
	if(S && S -> array && S -> capacity != 0 && S -> top != -1) {
		free(S -> array);
		S -> capacity = 0;
		S -> top = -1;
		printf("Stack deletion successful!\n");
	} else {
		printf("Stack deletion failed!\n");
	}
}

void printStack(struct Stack *S) {

	if(S && S -> array && S -> capacity != 0 && S-> top != -1) {
		int i;
		for(i = S -> top; i >= 0; i--) printf("%d <- ", S -> array[i]);
	} else {
		printf("Stack is empty");
	}
	printf("\n");
	
}

int main() {
	int i = 0, capacity = 15;
	
	// create a stack of capacity 15
	struct Stack *stk = createStack(capacity);
	
	for(i = 0; i <= capacity; i++) {
		push(stk,i);
	}
	
	printf("Top element is %d\n", peek(stk));
	printf("Stack size %d\n", size(stk));
	
	for(i = 0; i <= capacity/2; i++) {
		printf("Popped element is %d\n", pop(stk));
	}
	
	int p = 78;
	
	for(i = 0; i <= capacity/2; i++) {
		push(stk,p++);
	}
	
	if(isEmpty(stk)) {
		printf("Stack is empty (from main)\n");
	} else {
		printf("Stack is not empty(from main)\n");
	}
	
	printStack(stk);
	deleteStack(stk);
	printStack(stk);
	return 0;
}




























