#include <stdio.h>

void shell_sort(int [], int);
void print(int [], int );

int main() {

	int array[] = {1,2,6,2,6,78,2,5643,23,243,7,23,65,65,234,345,786,234,45,76,234,87,234,78,123,3,2,58,9,3,21};

	int size = sizeof(array)/sizeof(int);

	printf("Original Array: ");
	print(array, size);

	shell_sort(array, size);

	printf("Sorted Array:   ");
	print(array, size);

}

void shell_sort(int array[], int n) {

	// for (int interval = n / 2; interval > 0; 
	int interval = n;

	while (interval /= 2) {

		for (int i = interval; i < n; ++i) {

			int temp = array[i];
			int j = i;

			while (j >= interval && array[j - interval] > temp) {
				
				array[j] = array[j - interval];
				
				j -= interval;
			}

			array[j] = temp;
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