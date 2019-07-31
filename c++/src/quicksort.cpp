#include <iostream>
#include <quicksort.hpp>

void partition(int **p_array, int *low, int *high);

using namespace std;

void q_sort(int **p_array, int *low, int *high) {
	int *new_partition;
	if (low < high)
	{
		new_partition = partition(p_array, low, high);
		q_sort(p_array, low, (new_partition - 1));
		q_sort(p_array, (new_partition + 1), high);
	}
}

#if (QUICK_SORT_SCHEMA == LOMUTO)
void partition(int **p_array, int *low, int *high) {
	
}
#endif // QUICK_SORT_SCHEMA