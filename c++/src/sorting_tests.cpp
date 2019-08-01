#include <iostream>
#include <cstdlib>
#include <quicksort.hpp>
#include <bits/stdc++.h>


const int rand_array_size = 100;
int rand_array[rand_array_size];
int rand_array_copy[rand_array_size];
int *rand_array_addr, *rand_array_copy_addr;


using namespace std;

int main() {
	srand(time(NULL));
	
	

	sort(rand_array_copy_addr, (rand_array_copy_addr+rand_array_size));
	q_sort((rand_array_addr), 0, (rand_array_size-1));
	int check_var;
	
	for(int i = 0; i<rand_array_size; i++)
	{
		if(rand_array[i] != rand_array_copy[i])
		{
			check_var++;
		}
	}
	if(check_var) {
		cout << "Fail :(!" << endl;
	} else {
		cout << "Success!" << endl;
	}
	return 0;
}

