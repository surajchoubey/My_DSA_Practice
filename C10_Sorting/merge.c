#include <stdio.h>

// utility
void print(int [], int );
void swap(int *, int *);

// MERGESORT

void merge_sort(int [], int, int);
void merge(int [], int, int, int);

int main() {

	int array[] = {1,2,6,2,6,78,2,5643,23,243,7,23,65,65,234,345,786,234,45,76,234,87,234,78,123,3,2,58,9,3,21};
	int size = sizeof(array)/sizeof(int);

	printf("Original Array: ");
	print(array, size);

	merge_sort(array, 0, size - 1);

	printf("Sorted Array:   ");
	print(array, size);


}

void merge (int arr[], int l, int m, int r) {

	int n1 = m - l + 1, n2 = r - m;
	int L[n1], M[n2];

	for (int i = 0; i < n1; i++) L[i] = arr[l + i];
	for (int i = 0; i < n2; i++) M[i] = arr[m + 1 + i];

	int i = 0, j = 0, k = l;
	
	while (i < n1 && j < n2) {
		if (L[i] < M[j]) arr[k++] = L[i++];
		else arr[k++] = M[j++];
	}

	while (i < n1) arr[k++] = L[i++];
	while (j < n2) arr[k++] = M[j++];
}

void merge_sort (int arr[], int l, int r) {

	if (l >= r) return;

	int m = (l + r) >> 1;
	
	merge_sort(arr, l, m);
	merge_sort(arr, m + 1, r);

	merge(arr, l, m, r);
}

void print(int array[], int size) {

	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}