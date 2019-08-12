#include <iostream>
#include <merge_sort.h>

int *worker_array_addr;
static void merge_sort (int *p_array, int left, int right, int *p_worker_array);
static void merge_arrays (int *A, int l, int m, int r, int *B);

using namespace std;

void merge_sort_start (int *p_array, int size) {
	int worker_array[size];
	for (int i = 0; i < size; i++) {
		worker_array[i] = p_array[i];
	}
	/*cout << "first :: ";
	for ( int w = 0; w < size; w++) {
		cout << worker_array[w] << ", ";
	}
	cout << endl;*/
	worker_array_addr = (int *)worker_array;
	merge_sort(p_array, 0, (size-1), worker_array_addr);
}

static void merge_sort (int *p_array, int left, int right, int *p_worker_array) {
	
		// Find the middle point
		int mid = (left + right) / 2;
	if ((right - left) > 1) {
		//if (mid > left) {
			// Merge sort the first half
			merge_sort(p_array, left, (mid-1), p_worker_array);
		//}
		//if (mid < right) {
			// Merge sort the second half
			merge_sort(p_array, mid, right, p_worker_array);
		//}
		// Merge the two halves sorted in previous steps
		merge_arrays(p_array, left, mid, right, p_worker_array);
	}
	
	else if ((right - left) == 1){
		if (p_array[left] > p_array[right]) {
			int temp = p_array[left];
			p_array[left] = p_array[right];
			p_array[right] = temp;
		}
		for (int k = left; k <= right; k++)
			p_worker_array[k] = p_array[k];
	}
	
	return;
}

static void merge_arrays (int *A, int l, int m, int r, int *B) {
	int i = l, j = m;
	//cout << "Step :: ";
	for (int k = l; k <= r; k++) {
		if ((i < m) 
			&& ((j > r) || B[i] <= B[j])) 
		{
			A[k] = B[i];
			i++;
		} 
		else {
			A[k] = B[j];
			j++;
		}
		//cout << A[k] << ", ";
	}
	for (int k = l; k <= r; k++)
		B[k] = A[k];
	//cout << endl;
	/*
	cout << "L = " << l <<" M = " << m << " R = " << r << endl;
	cout << "Step :: ";
	for ( int w = l; w <= r; w++) {
		cout << A[w] << ", ";
	}
	cout << endl << "--------------------------" << endl;
	*/
}