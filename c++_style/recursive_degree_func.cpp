#include <iostream>

uint64_t degree(const uint32_t& val, const uint16_t& n)
{
	if (n == 0) return 1;
	else
	{
		if (n % 2 == 0)
			return val * degree(val, n / 2);
		else
			return val * degree(val, n - 1);
	}
}

int main()
{
	//value
	uint16_t val = 2;

	std::cout << "Type degree: \n";
	uint16_t n = 0;
	std::cin >> n;
	std::cout << degree(val, n);
	return 0;
}