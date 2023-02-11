#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Queue {
	int front,rear;
	int capacity;
	int size;
	int *array;	
};

// Create an empty queue
struct Queue *createQueue(int capacity) {

	struct Queue *Q = (struct Queue *)malloc(sizeof(struct Queue));
	Q -> capacity = capacity;
	Q -> front = Q -> rear = -1;
	Q -> array = malloc(sizeof(int) * Q -> capacity);
	Q -> size = 0;

	if(Q -> array) return Q;
	else {
		printf("Queue array formation failed!\n");
		return NULL;
	}
}

// Returns queue size
int size(struct Queue *Q) {
	return Q -> size;
}

// Returns front element
int frontElement(struct Queue *Q) {
	return (Q -> front != -1 ? Q -> front : -1);
}

// Return last element
int rearElement(struct Queue *Q) {
	return (Q -> rear != -1 ? Q -> front : -1);
}

// checks if queue is empty
int isEmpty(struct Queue *Q) {
	return (Q -> size == 0);
}

// checks if queue is full
int isFull(struct Queue *Q) {
	return (Q -> size == Q -> capacity);
}

// adds element to the queue
void enQueue(struct Queue *Q, int data) {
	if(isFull(Q)) {
		// printf("Queue overflow!\n");
		Q -> capacity *= 2;
		Q -> array = realloc(Q -> array, Q -> capacity * sizeof(int));
		if(Q -> array) {
			printf("Memory doubling successful!\n");
		} else {
			printf("Memory doubling UNSUCCESSFULL!\n");
			Q -> capacity /= 2;
			return;
		}
	}
	Q -> rear = (Q -> rear + 1);
	Q -> array[Q -> size++] = data;
	if(Q -> front == -1) 
		Q -> front = Q -> rear;
	printf("%d is added from the Queue!\n", Q -> array[Q -> rear]);
}

// removes element from the queue
void deQueue(struct Queue *Q) {
	if(isEmpty(Q)) {
		printf("Queue underflow!\n");
	} else {
		int popped = Q -> array[Q -> front];
		if(Q -> front == Q -> rear) {
			Q -> front = Q -> rear = -1;
			Q -> size = 0;
			printf("%d is popped from the Queue!\n", popped);
		} else {
			Q -> front = (Q -> front + 1);
			Q -> size--;
			printf("%d is popped from the Queue!\n", popped);
		}
	}
}

// deletes the entire queue
void deleteQueue(struct Queue *Q) {
	if(Q && Q -> array)  {
		Q -> front = Q -> rear = -1;
		Q -> size = 0;
		Q -> capacity = 0;
		free(Q -> array);
		printf("Queue deletion successful!\n");
	}
}

void printQueue(struct Queue * Q) {
	if(Q && Q -> array && Q -> size > 1) {
		for(int i = Q -> front; i <= Q -> rear; i++) printf("%d -> ", Q -> array[i]);
		printf("\n");
	}
}

int main() {

	struct Queue *Q = createQueue(10);

	int i;

	for(i = 90; i <= 155; i++) {
		enQueue(Q,i);
	}

	printQueue(Q);

	for(i = 1; i <= 25; i++) {
		deQueue(Q);
	}

	printQueue(Q);
	
	printf("Q -> front -> data = %d \n",Q -> array[Q -> front]);
	printf("Q -> rear -> data = %d \n",Q -> array[Q -> rear]);

	deleteQueue(Q);

	printf("%d is queue size\n",Q -> size);

	printQueue(Q);

	return 0;
}
