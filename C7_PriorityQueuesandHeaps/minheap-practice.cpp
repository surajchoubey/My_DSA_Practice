#include<iostream>
#include<climits>

using namespace std;

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

// A class for Min heap

class MinHeap {
	int *harr;
	int capacity;
	int heap_size;

	public:
		// constructor
		MinHeap(int cap) {
			heap_size = 0;
			capacity = cap;
			harr = new int[cap];		
		}

		//  to heapify a subtree with the root at given index
		void MinHeapify(int i) {
			int l = left(i);
			int r = right(i);

			int smallest = i;

			if(l < heap_size && harr[l] < harr[i]) {
				smallest = l;
			}

			if(r < heap_size && harr[r] < harr[smallest]) {
				smallest = r;
			}

			if(smallest != i) {
				swap(&harr[i], &harr[smallest]);
				MinHeapify(smallest);
			}
		}

		// return parent node
		int parent(int i) {
			return (i - 1)/2;
		}

		// to get the index of left child
		int left(int i) {
			return (2 * i + 1);
		}

		// to get the index of the right child
		int right(int i) {
			return (2 * i + 2);
		}

		// to extract the minimum element
		int extractMin() {
			if(heap_size <= 0) {
				return INT_MAX;
			}

			if(heap_size == 1) {
				heap_size--;
				return harr[0];
			}

			// store the minimum value, and remove if from heap
			int root = harr[0];
			harr[0] = harr[heap_size - 1];
			heap_size--;
			MinHeapify(0);

			return root;
		}

		// to decrease the key value at index i to new_val
		void decreaseKey(int i, int new_val) {
			harr[i] = new_val;

			while(i != 0 && harr[parent(i)] > harr[i]) {
				swap(&harr[i], &harr[parent(i)]);
				i = parent(i);
			}
		}

		// returns the minimum key (key at root) from minimum heap
		int getMin() {
			return harr[0];
		}

		// delete a key stored at index i
		void deleteKey(int i) {
			decreaseKey(i, INT_MIN);
			extractMin();
		}

		// inserts a new key 'k'
		void insertElement(int k) {

			if(heap_size == capacity) {
				cout << "\nOverflow: Could not insertkey";
				return;
			}

			// First insert the new key at the end
			heap_size++;
			int i = heap_size - 1;
			harr[i] = k;

			// Fix the min heap property if it is violated
			// goes in upward direction
			while(i != 0 && harr[parent(i)] > harr[i]) {
				swap(&harr[i], &harr[parent(i)]);
				i = parent(i);
			}	
		}
};

// Driver program to test above functions
int main()
{
	MinHeap h(11);
	h.insertElement(3);
	h.insertElement(2);
	h.deleteKey(1);
	h.insertElement(15);
	h.insertElement(5);
	h.insertElement(4);
	h.insertElement(45);
	cout << h.extractMin() << " ";
	cout << h.getMin() << " ";
	h.decreaseKey(2, 1);
	cout << h.getMin();
	cout << endl;
	return 0;
}
