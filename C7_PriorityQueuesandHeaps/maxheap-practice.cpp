#include<iostream>
#include<climits>

using namespace std;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

class MaxHeap {

    int *harr;
    int capacity;
    int heap_size;

    public:

    MaxHeap(int size) {
        harr = new int[size];
        capacity = size;
        heap_size = 0;
    }

    void MaxHeapify(int i) {

        int leftIndex = left(i);
        int rightIndex = right(i);

        int largestIndex = i;

        if (leftIndex < heap_size && harr[leftIndex] > harr[i]) {
            largestIndex = leftIndex;
        }

        if (rightIndex < heap_size && harr[rightIndex] > harr[largestIndex]) {
            largestIndex = rightIndex;
        }

        if (largestIndex != i) {
            swap(&harr[largestIndex], &harr[i]);
            MaxHeapify(largestIndex);
        }

    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    int extractMax() {
        if (heap_size <= 0) {
            cout << "Heap is empty";
            return INT_MIN;
        }

        if (heap_size == 1) {
            heap_size -= 1;
            return harr[0];
        }

        int root = harr[0];
        harr[0] = harr[heap_size - 1];
        heap_size--;
        MaxHeapify(0);

        return root;
    }

    void decreaseKey(int i, int new_val) {
        harr[i] = new_val;

        while (i != 0 && harr[parent(i)] < harr[i]) {
            swap(&harr[parent(i)], &harr[i]);
            i = parent(i);
        }
    }

    void insertElement(int k) {

        if (heap_size == capacity) {
            cout << "Heap overflow! Cannot insert " << k;
        }

        heap_size += 1;
        int i = heap_size - 1;
        harr[i] = k;

        while (i != 0 && harr[parent(i)] < harr[i]) {
            swap(&harr[parent(i)], &harr[i]);
            i = parent(i);
        }
    }

    void deleteKey(int i) {
        decreaseKey(i, INT_MAX);
        extractMax();
    }

    int getMax() {
        if (heap_size <= 0) {
            cout << "Heap is empty! cannot return minimum element on the top";
            return INT_MIN;
        }
        return harr[0];
    }

};

int main() {
	MaxHeap h(11);
	h.insertElement(3);
	h.insertElement(2);
	h.deleteKey(1);
	h.insertElement(15);
	h.insertElement(5);
	h.insertElement(4);
	h.insertElement(45);
	cout << h.extractMax() << " ";
	cout << h.getMax() << " ";
	h.decreaseKey(2, 1);
	cout << h.getMax();
	cout << endl;
	return 0;
}