#include <stdio.h>

int linear_search(int [], int, int);
int binary_search(int [], int, int);
int interpolation_search(int [], int, int);

int main() {

	int array[] = {0,1,2,3,4,5,6,7,8,9,10};
	int n = sizeof(array)/sizeof(int);

	printf ("Linear Search Position = %d \n\n", linear_search(array, 2, n));
	printf ("Binary Search Position = %d \n\n", binary_search(array, 8, n));
	printf ("Interpolation Search Position = %d \n\n", interpolation_search(array, 9, n));

	return 0;
}

int linear_search(int arr[], int target, int n) {

	for (int i = 0; i < n; i++) {

		if (arr[i] == target)
			return i;
	}

	return -1;
}

int binary_search(int arr[], int target, int n) {

	int low = 0;
	int high = n - 1;

	while (low <= high) {

		int mid = (low + high) >> 1;

		if (target == arr[mid]) return mid;

		else if (target < arr[mid]) high = mid - 1;

		else low = mid + 1;
	}

	return -1;

}

int interpolation_search(int arr[], int target, int n) {

	int low = 0;
	int high = n - 1;

	while (low <= high && target >= arr[low] && target <= arr[high]) {

		int mid = low + (target - arr[low]) * (high - low) / (arr[high] - arr[low]);

		if (target == arr[mid]) return mid;

		else if (target < arr[mid]) low = mid + 1;

		else high = mid - 1;
	}

	return -1;

}