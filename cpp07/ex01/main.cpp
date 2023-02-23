#include <iostream>
#include "iter.hpp"

int main()
{
	int arr[10] = {0,};
	char str[7] = {'c', 'h', 'i', 'c', 'k', 'e', 'n'};
	
	::iter(arr, 10, ::printArr);
	::iter(str, 7, ::printArr);
	
	return (0);
}