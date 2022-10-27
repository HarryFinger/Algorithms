#include <iostream>
#include <memory>

/*	    0
      /   \
	 /     \
	0       0
   / \     / \
  0	  0   0   0   
     / \
    0   0        */
void merge_sort(int* arr, int arr_size)
{
	//base case of recurtion
	if (arr_size <= 1) return; 
	int mid = arr_size / 2;

	int* left_arr = arr; 
	int* right_arr = arr + mid;
	int left_size = mid; 
	int right_size = arr_size - mid;
	
	//recursion
	merge_sort(left_arr, left_size);
	merge_sort(right_arr, right_size);

	//merge two arrays into singe
	auto buffer = std::make_unique<int[]>(arr_size);
	int left_i = 0;
	int right_i = 0;
	int buffer_i = 0;
	while (left_i < left_size && right_i < right_size)
	{
		if (left_arr[left_i] <= right_arr[right_i])
		{
			buffer[buffer_i] = left_arr[left_i];
			++left_i;
			++buffer_i;
		}
		else
		{
			buffer[buffer_i] = right_arr[right_i];
			++right_i;
			++buffer_i;
		}
	}

	while (left_i < left_size)
	{
		buffer[buffer_i] = left_arr[left_i];

		++left_i;
		++buffer_i;
	}

	while (right_i < right_size)
	{
		buffer[buffer_i] = right_arr[right_i];
		++right_i;
		++buffer_i;
	}

	for (size_t i = 0; i < arr_size; i++)
	{
		arr[i] = buffer[i];
	}

}


void fill_arr(int* arr, const int& size)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}
void print_arr(int* arr, const int& size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}


int main()
{
	constexpr int n = 10;
	int* arr = new int[n];
	fill_arr(arr, n);
	print_arr(arr, n);

	merge_sort(arr, n);

	print_arr(arr, n);
	delete[] arr;
	return 0;
}