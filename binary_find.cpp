#include <iostream>
#include <vector>
#include <algorithm>

bool left_bound(int* _arr, int N, int val)
{
	int left_bound = -1;
	int right_bound = N;
	while (right_bound - left_bound > 1)
	{
		int middle = (right_bound + left_bound) / 2;

		if (val > _arr[middle])
			left_bound = middle;
		else
			right_bound = middle;
	}
	//return left_bound;
	if (_arr[left_bound+1]  == val)
		return true;
	else 
		return false;
}

int main()
{
	int arr[] = { 1,2,2,4,6,6,6,8,8,15,16 };

	int arr_not_sorted[] = { 1,1,51,-2,31,0,161,21,11,3 };

	std::sort(arr_not_sorted, arr_not_sorted+10);

	std::cout << left_bound(arr_not_sorted, 10, -11);

	std::cout << std::endl;
	
}