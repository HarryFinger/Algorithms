#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> getBitStrings(unsigned int n)
{
	std::vector<std::string> result;

	if (n <= 1)
	{
		result.push_back("0");
		result.push_back("1");
	}
	else
	{   // recurse, then add extra bit chars
		std::vector<std::string> sub = getBitStrings(n - 1);
		for (std::vector<std::string>::const_iterator it = sub.cbegin();
			it != sub.cend(); ++it)
		{
			result.push_back(*it + '0');
			result.push_back(*it + '1');
		}
	}
	return result;
}

int main()
{
	std::vector<std::string> bs = getBitStrings(3);
	std::copy(bs.begin(), bs.end(),
		std::ostream_iterator<std::string>(std::cout, "\n"));
	return 0;
}