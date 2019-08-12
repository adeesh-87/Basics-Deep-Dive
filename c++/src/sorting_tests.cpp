#include <iostream>
#include <cstdlib>
#include <quicksort.hpp>
#include <merge_sort.h>
#include <bubble_sort.h>
#include <bits/stdc++.h>
#include <chrono>
#include <sorting_tests.h>
#include <gtest/gtest.h>

volatile q_sort_schema_t q_sort_partition_style;
int num_tests, num_tests_pass;

void generate_test_array(int * x_addr, int * x_ref_addr, int size, int val_limit);
bool check_arrays_equal(int x[], int y[], int size);
void tester_with_rand_generator(void (*sorter)(int * p_array, int array_size), int test_array_size);
void print_array(int arr[], int size);

using namespace std;
using namespace std::chrono;

void sorting_tests() {
	srand(time(NULL));
	cout << "**********************************************************************" << endl;
	cout << "                      Executing Quicksort Lomuto Tests" << endl;
	cout << "**********************************************************************" << endl;
	q_sort_partition_style = LOMUTO;
	tester_with_rand_generator(q_sort_start, 23);
	tester_with_rand_generator(q_sort_start, 42);
	tester_with_rand_generator(q_sort_start, 200);
	tester_with_rand_generator(q_sort_start, 500);
	tester_with_rand_generator(q_sort_start, 1000);
	tester_with_rand_generator(q_sort_start, 100000);
	cout << "**********************************************************************" << endl;
	cout << "                      Lomuto Test Results" << endl;
	cout << "**********************************************************************" << endl;
	cout << "Number of tests = " << num_tests << " Passed = " << num_tests_pass  << " Failed = " << (num_tests - num_tests_pass) << endl;
	
	// ************************************************************************************************************************************
	
	cout << "**********************************************************************" << endl;
	cout << "                      Executing Merge sort Tests" << endl;
	cout << "**********************************************************************" << endl;
	tester_with_rand_generator(merge_sort_start, 23);
	tester_with_rand_generator(merge_sort_start, 42);
	tester_with_rand_generator(merge_sort_start, 200);
	tester_with_rand_generator(merge_sort_start, 500);
	tester_with_rand_generator(merge_sort_start, 1000);
	tester_with_rand_generator(merge_sort_start, 100000);
	cout << "**********************************************************************" << endl;
	cout << "                      Merge sort Test Results" << endl;
	cout << "**********************************************************************" << endl;
	cout << "Number of tests = " << num_tests << " Passed = " << num_tests_pass  << " Failed = " << (num_tests - num_tests_pass) << endl;
	
	// ************************************************************************************************************************************
	
	cout << "**********************************************************************" << endl;
	cout << "                      Executing Bubble sort Tests" << endl;
	cout << "**********************************************************************" << endl;
	tester_with_rand_generator(bubble_sort, 23);
	tester_with_rand_generator(bubble_sort, 42);
	tester_with_rand_generator(bubble_sort, 200);
	tester_with_rand_generator(bubble_sort, 500);
	tester_with_rand_generator(bubble_sort, 1000);
	tester_with_rand_generator(bubble_sort, 5000);
	cout << "**********************************************************************" << endl;
	cout << "                      Bubble sort Test Results" << endl;
	cout << "**********************************************************************" << endl;
	cout << "Number of tests = " << num_tests << " Passed = " << num_tests_pass  << " Failed = " << (num_tests - num_tests_pass) << endl;

}

void tester_with_rand_generator(void (*sorter)(int * p_array, int array_size), int test_array_size) {
	int rand_array[test_array_size];
	int rand_array_reference[test_array_size];
	int *rand_array_addr = rand_array, *rand_array_reference_addr = rand_array_reference;
	int result;
	num_tests++;
	
	for (int i = 0; i < test_array_size; i++) {
		rand_array[i] = rand();
		rand_array_reference[i] = rand_array[i];
	}
	auto start_ref = high_resolution_clock::now();
	sort(rand_array_reference_addr, (rand_array_reference_addr+test_array_size));
	auto stop_ref = high_resolution_clock::now();
	
	auto start = high_resolution_clock::now(); 
	sorter((rand_array_addr), (test_array_size));
	auto stop = high_resolution_clock::now();
	
	auto duration_ref = duration_cast<microseconds>(stop_ref - start_ref);
	auto duration = duration_cast<microseconds>(stop - start); 
	result = ( check_arrays_equal(rand_array_addr, rand_array_reference_addr, test_array_size) ? 1 : 0 );
	
	if(result)
	{
		num_tests_pass++;
		cout << "\033[32m[Pass]\033[0m";
	} else {
		cout << "\033[31m[Fail]\033[0m";
	}
	cout << " Test " << num_tests << " ";
	cout << "in " << duration.count() << " [ref: " << duration_ref.count() << "]" << " usecs" << endl;
	/* Did just for confirmation
	if(test_array_size < 50) {
		print_array(rand_array, test_array_size);
		print_array(rand_array_reference, test_array_size);
	}*/
}

void print_array(int arr[], int size) {
	cout << "Array: " << arr[0];
	for (int i = 1; i < size; i++) {
		cout << ", " << arr[i];
	}
	cout << endl;
}

bool check_arrays_equal(int x[], int y[], int size) {
	int check_var = 0;
	
	for (int i = 0; i<size; i++)
	{
		if (x[i] != y[i])
		{
			check_var++;
		}
	}
	if (check_var) {
		return false;
	}
	
	return true;
}