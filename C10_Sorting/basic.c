#include <stdio.h>

// utility
void print(int [], int );
void swap(int *, int *);

// O(n^2) ALGORITHMS
void bubble_sort(int [], int );
void selection_sort(int [], int );
void insertion_sort(int [], int );

int main() {

	int array[] = {1,2,6,2,6,78,2,5643,23,243,7,23,65,65,234,345,786,234,45,76,234,87,234,78,123,3,2,58,9,3,21};
	int array2[] = {6, 3, 9, 7, 1, 3};
	int size = sizeof(array)/sizeof(int);
	printf("Original Array: ");
	print(array, size);

	// bubble_sort(array, size);
	// selection_sort(array, size);
	insertion_sort(array, size);

	printf("Sorted Array:   ");
	print(array, size);

}

void bubble_sort(int array[], int size) {

	int i, step, no_swap;

	for (step = 0; step < size - 1; ++step) {

		no_swap = 1;

		for (i = 0; i < size - step - 1; ++i) {

			if (array[i] > array[i + 1]) {

				swap(&array[i], &array[i + 1]);
				no_swap = 0;
			}
		}

		if(no_swap) break;
	}
}

void selection_sort(int array[], int size) {

	int i,j;

	for (i = 0; i < size - 1; ++i) {

		int min = i;

		for (j = i + 1; j < size; j++) {

			if (array[j] < array[min]) {
				min = j;
			}	
		} 
		swap(&array[min], &array[i]);
	}

}

void insertion_sort(int array[], int size) {

	for (int i = 1; i < size; i++) {

		int store = array[i];
		int j = i - 1;

		while (store < array[j] && j >= 0) {

			array[j + 1] = array[j];
			--j;
		}

		array[j + 1] = store;
	}

}

void print(int array[], int size) {

	int i = 0;

	for (i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
