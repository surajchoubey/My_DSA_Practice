#include <stdio.h>

// utility
void print(int [], int );
void swap(int *, int *);

// QUICKSORT
void quick_sort(int [], int, int);
int partition(int [], int, int);

int main () {

	int array[] = {1,2,6,2,6,78,2,5643,23,243,7,23,65,65,234,345,786,234,45,76,234,87,234,78,123,3,2,58,9,3,21};
	int size = sizeof(array)/sizeof(int);

	printf("Original Array: ");
	print(array, size);

	quick_sort(array, 0, size - 1);

	printf("Sorted Array:   ");
	print(array, size);

}

void quick_sort(int arr[], int l, int r) {

	if (l >= r) return;

	int pivot = partition(arr, l, r);

	quick_sort(arr, l, pivot - 1);

	quick_sort(arr, pivot + 1, r);
}

int partition (int arr[], int l, int r) {

	int pivot = arr[r], i = l - 1;

	for (int j = l; j < r; j++) {

		if(pivot < arr[j]) continue;

		i++;
		swap(&arr[i], &arr[j]);
	}

	swap(&arr[i + 1], &arr[r]);

	return (i + 1);
}

void print(int arr[], int size) {

	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}