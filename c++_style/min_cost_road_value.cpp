#include <iostream>
#include <vector>

//minimum cost road value from point 1 to n

uint64_t minCostRoadCounter(const std::vector<int>& value_array, size_t n)
{
	std::vector<int> min_cost_array;
	min_cost_array.resize(value_array.size());
	min_cost_array[0] = value_array[0];
	min_cost_array[1] = value_array[0] + value_array[1];
	for (size_t i = 2; i < value_array.size(); i++)
	{
		min_cost_array[i] = std::min(min_cost_array[i - 1], min_cost_array[i - 2]) + value_array[i];
	}
	return min_cost_array[n];
}


int main()
{
	std::vector<int> value_array{ 1,5,3,2,5,1,7 };
	std::cout << minCostRoadCounter(value_array, 5);
}