#include <bubble_sort.h>
#include <iostream>

using namespace std;

void bubble_sort (int *p_array, int size) {
	bool is_sorted = false;
	int temp_var, num_swaps;
	while((false == is_sorted) && (size > 1)) {
		num_swaps = 0;
		for (int i = 0; i < (size - 1); i++) {
			if (p_array[i] > p_array[i+1]) {
				temp_var = p_array[i];
				p_array[i] = p_array[i+1];
				p_array[i+1] = temp_var;
				num_swaps++;
			}
			//cout << "i = " << i << " n_s = " << num_swaps << endl;
		}
		if (0 == num_swaps) {
			is_sorted = true;
		}
	}
	return;
}