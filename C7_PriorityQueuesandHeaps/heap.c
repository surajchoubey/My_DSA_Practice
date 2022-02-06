#include<stdio.h>
#include<stdlib.h>

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

struct Heap {
	int *array;
	int count; // Number of elements in Heap
	int capacity; // Size of the heap
	// int heap_type; // Min heap or max heap
};

// create a node
struct Heap *createHeap(int capacity) {// , int heap_type = 0) {

	struct Heap *h = (struct Heap *)malloc(sizeof(struct Heap));

	if(h == NULL) {
		printf("Memory Error");
		return NULL;
	}

	// h -> heap_type = heap_type;
	h -> count = 0;
	h -> capacity = capacity;
	h -> array = (int *) malloc(sizeof(int) * h -> capacity);

	if (h -> array == NULL) {
		printf("Memory Error");
		return NULL;
	}

	return h;
}

// parent of a node
int parent(struct Heap *h, int i) {

	if(i <= 0 || h -> count) {
		return -1;
	}
	return (i - 1)/2;

}

int leftChild(struct Heap *h, int i) {

	int left = 2*i+1; // carefully see here
	if(left >= h -> count) {
		return -1;
	}
	return left;
}

int rightChild(struct Heap *h, int i) {

	int left = 2*i+2; // carefully see here
	if(left >= h -> count) {
		return -1;
	}
	return left;
}

// for max heap max element is always at the root
int getMaximum(struct Heap *h) {

	if(h -> count == 0) {
		return -1;
	}
	return h -> array[0];
}

// heapifying an element at location i
void percolateDown(struct Heap *h, int i) {

	int left, right, max = i;
	left = leftChild(h,i);
	right = rightChild(h,i);

	if (left != -1 && h->array[left] > h -> array[i]) {
		max = left;
	}

	if (right != -1 && h->array[right] > h -> array[i]) {
		max = right;
	}

	if(max != i) {
		swap(&h -> array[max], &h -> array[i]);
		percolateDown(h, max);
	}

}

// deleting an element
// deleting an element in heap is only done at the top
int deleteMax(struct Heap *h) {

	if (h -> count == 0) {
		return -1;
	}

	int data = h -> array[0];
	h -> array[0] = h -> array[h -> count - 1];
	h -> count--; // reducing the heap size

	percolateDown(h, 0);

	return data;
}

// resize the heap
void resizeHeap(struct Heap *h) {
	int i;

	int *array_old = h -> array;
	h -> array = (int *)malloc(sizeof(int) * h -> capacity * 2);

	if(h -> array == NULL) {
		printf("Memory Error!\n");
		return;
	}

	for(i = 0; i < h -> capacity; i++) {
		h -> array[i] = array_old[i];
	}

	h -> capacity *= 2;
	free(array_old);
}


// inserting an element into the heap; the function resizeHeap from above is required to execute the insert function
int insert(struct Heap *h, int data) {
	int i;
	if(h -> count == h -> capacity)
		resizeHeap(h);

	h -> count++;

	i = h -> count - 1;

	while(i >= 0 && data > h -> array[(i-1)/2]) {
		h -> array[i] = h -> array[(i-1)/2];
		i = (i - 1)/2;
	}

	h -> array[i] = data;
}

// destroying the heap
void destroyHeap(struct Heap *h) {

	if(h == NULL) {
		return;
	}
	free(h -> array);
	free(h);
	h = NULL;
}

// heapifying the array
void buildHeap(struct Heap *h, int A[], int n) {

	int i;

	if(h = NULL) {
		return;
	}

	while(n > h -> capacity)
		resizeHeap(h);

	for(i = 0; i < n; i++) {
		h -> array[i] = A[i];
	}

	h -> count = n;

	for(i = (n-1)/2; i >= 0; i--) {
		percolateDown(h, i);
	}

}

// HEAPSORT
void Heapsort(int A[], int n) {

	struct Heap *h = createHeap(n);

	int old_size, i, temp;

	buildHeap(h, A, n);

	old_size = h -> count;

	for(i = n-1; i > 0; i--) {
		// h -> array[0] is the largest element

		temp = h -> array[0];
		h -> array[0] = h -> array[h -> count - 1];
		h -> array[0] = temp;
		h -> count--;

		percolateDown(h, 0);
	}

	h -> count = old_size;
}

int main() {

	// test everything out here

	return 0;
}