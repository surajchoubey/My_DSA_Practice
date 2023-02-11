#include <stdio.h>

// utility
void print(int [], int );
void swap(int *, int *);

void counting_sort(int [], int, int [], int);
void counting_sort_two(int [], int, int[], int);

int main () {

	int k = 100, n = 12;
	
	int B[n];
	int array[] = { 1, 5, 67, 69, 2, 65, 7, 2, 4, 6, 7, 10};
	counting_sort(array, n, B, k);
	print(B, n);

	// int B2[n];
	// int array2[] = { 1, 5, 67, 69, 2, 65, 7, 2, 4, 6, 7, 10};
	// counting_sort_two(array2, n, B2, k);
	// print(B2, n);
}

void counting_sort(int arr[], int n, int sorted[], int k) {

	int count[k + 1];

	for (int i = 0; i <= k; ++i) count[i] = 0;

	for (int i = 0; i < n; ++i) ++count[arr[i]];

	for (int i = 0; i <= k; ++i) count[i] += count[i - 1];

	for (int i = n - 1; i >= 0; --i) {

		sorted[count[arr[i]] - 1] = arr[i];
		--count[arr[i]];
	}

}

void counting_sort_two(int arr[], int n, int arr2[], int k) {

	int count[k + 1];

	for (int i = 0; i <= k; i++) count[i] = 0;

	for (int i = 0; i < n; i++) ++count[arr[i]];

	int j = 0;

	for (int i = 0; i <= k; i++) {

		while(count[i]--) {

			arr2[j++] = i;
		}
	}
}


void print(int array[], int size) {

	int i = 0;

	for (i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}