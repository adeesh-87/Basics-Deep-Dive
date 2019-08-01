#include <iostream>
#include <quicksort.hpp>

int partition(int *p_array, int low, int high);
extern q_sort_schema_t q_sort_partition_style;
using namespace std;

void q_sort_start(int *p_array, int size) {
	q_sort(p_array, 0, size);
}

void q_sort(int *p_array, int low, int high) {
	int new_partition;
	if (low < high)
	{
		new_partition = partition(p_array, low, high);
		q_sort(p_array, low, (new_partition - 1));
		q_sort(p_array, (new_partition + 1), high);
	}
}

int partition(int *p_array, int low, int high) {
	if(q_sort_partition_style == LOMUTO) {
		volatile int pivot = p_array[high];
		volatile int i = low, temp_var;
		for (int j = low; j < (high); j++)
		{
			if (p_array[j] < pivot)
			{
				temp_var = p_array[i];
				p_array[i] = p_array[j];
				p_array[j] = temp_var;
				i++;
			}
		}
		temp_var = p_array[i];
		p_array[i] = p_array[high];
		p_array[high] = temp_var;

		return i;
	} else {
		return 0;
	}
	return 0;
}