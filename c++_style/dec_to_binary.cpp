#include <iostream>
#include <vector>

std::vector<bool> convertToBinaries(uint32_t n)
{
	size_t vec_size = 1;
	int _n = n;
	while (_n = _n>>1)
	{
		++vec_size;
	}

	std::vector<bool> vec(vec_size);

	for (int i = vec_size-1; i >= 0;--i)
	{
		vec[i]  = n % 2;
		n = n / 2;
	}

	return vec;
}

int main()
{
	auto vec = convertToBinaries(14);
	for (const auto& it : vec)
	{
		std::cout << it;
	}
}