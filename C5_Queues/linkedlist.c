#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct ListNode {
	int data;
	struct ListNode *next;
};

struct Queue {
	struct ListNode *front;
	struct ListNode *rear;
	int size;
};

// Create an empty queue
struct Queue *createQueue() {

	struct Queue *Q = (struct Queue *)malloc(sizeof(struct Queue));

	if(Q) {
		Q -> front = Q -> rear = NULL;
		Q -> size = 0;
		return Q;
	} else {
		printf("Queue array formation failed!\n");
		return NULL;
	}
}

struct ListNode *createNewListNode(int data) {
	struct ListNode *newListNode = (struct ListNode *)malloc(sizeof(struct ListNode));
	newListNode -> next = NULL;
	newListNode -> data = data;

	if(newListNode) return newListNode;
	else {
		printf("New ListNode formation failed!\n");
		return NULL;
	}
}

// Returns queue size
int size(struct Queue *Q) {
	return Q -> size;
}

// Returns front element
int frontElement(struct Queue *Q) {
	if(Q -> front) {
		return Q -> front -> data;
	} else {
		printf("Q -> front points is NULL");
		return INT_MIN;
	}
}

// Return last element
int rearElement(struct Queue *Q) {
	if(Q -> rear) {
		return Q -> rear -> data;
	} else {
		printf("Q -> rear points to NULL");
		return INT_MIN;
	}
}

// checks if queue is empty
int isEmpty(struct Queue *Q) {
	return (Q -> size == 0);
}

// adds element to the queue
void enQueue(struct Queue *Q, int data) {
	struct ListNode *temp = createNewListNode(data);
	if(temp) {
		if(Q -> rear) Q -> rear -> next = temp;
		Q -> rear = temp;
		Q -> size++;
		if(Q -> size == 1) Q -> front = Q -> rear;
		printf("%d is added to the Queue!\n", Q -> rear -> data);
	} else {
		printf("enQueue of %d failed!\n", data);
	}
}

// removes element from the queue
void deQueue(struct Queue *Q) {
	if(isEmpty(Q)) {
		printf("Queue underflow!\n");
	} else {
		int popped = Q -> front -> data;
		struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
		temp = Q -> front;
		Q -> front = Q -> front -> next;
		temp -> next = NULL;
		Q -> size--;
		if(Q -> size == 0) Q -> front = Q -> rear = NULL;
		free(temp);
		printf("%d is removed from the Queue!\n", popped);
	}
}

// deletes the entire queue
void deleteQueue(struct Queue *Q) {
	if(Q && !isEmpty(Q) && Q -> front && Q -> rear)  {
		while(Q -> size) deQueue(Q);
		printf("Queue deletion successful!\n");
	} else {
		printf("Queue deletion failed!\n");
	}
}

void printQueue(struct Queue *Q) {

	struct ListNode *current = Q -> front;
	if(Q && Q -> front && Q -> rear) {
		while(current) {
			printf("%d -> ", current -> data);
			current = current -> next;
		}
		printf("\n");
	} else {
		printf("Queue cannot be printed");
	}
}

int main() {

	struct Queue *Q = createQueue();

	int i;

	for(i = 90; i <= 100; i++) {
		enQueue(Q,i);
	}

	printQueue(Q);
	
	for(i = 1; i <= 5; i++) {
		deQueue(Q);
	}

	printQueue(Q);

	printf("%d is queue size\n",Q -> size);

	printQueue(Q);

	printf("%d is the front of the queue\n", Q -> front -> data);
	printf("%d is the rear of the queue\n", Q -> rear -> data);

	deleteQueue(Q);


	return 0;
}
