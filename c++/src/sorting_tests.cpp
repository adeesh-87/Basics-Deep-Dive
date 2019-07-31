#include <iostream>
#include <cstdlib>
#include <quicksort.hpp>

const int list_size = 5;
int list[list_size];
int *list_addr;
using namespace std;

int main() {
	srand(time(NULL));
	for(int i = 0; i<list_size; i++)
	{
		list[i] = rand() % 100;
	}
	list_addr = list;
	sort_ints((&list_addr),list_size);
	cout << "list : ";
	for(int i = 0; i<list_size; i++)
	{
		cout << list[i] << ", ";
	}
	cout << endl;
	return 0;
}