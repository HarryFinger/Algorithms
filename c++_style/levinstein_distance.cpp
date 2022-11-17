#include <iostream>
#include <algorithm>

//the Levenshtein distance between two words is the minimum number
//of single-character edits (insertions, deletions or substitutions) required to change one word into the other
//for example we need 2 operations to change string "rubd" into "run" (delete last "d" symbol and substitute "b" on "n")

void makeZeroArray(int** array, uint32_t N, uint32_t M)
{
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			array[i][j] = 0;
		}
	}
}
void printArray(int** array, uint32_t N, uint32_t M)
{
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			std::cout << array[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

uint32_t leviDistance(const std::string& str_1, const std::string& str_2)
{
	uint32_t N = str_1.size() + 1; //bigger than original string!!!
	uint32_t M = str_2.size() + 1; //bigger than original string!!!
	int** distance_array = new int*[N];
	for (size_t i = 0; i < N; i++){ distance_array[i] = new int[M]; }

	makeZeroArray(distance_array, N, M);
	for (size_t i = 0; i < N; i++) { distance_array[i][0] = i; }
	for (size_t j = 0; j < M; j++){ distance_array[0][j] = j; }
	
	for (size_t i = 1; i < N; i++)
	{
		for (size_t j = 1; j < M; j++)
		{
			char char_1 = str_1[i-1];
			char char_2 = str_2[j-1];
			size_t additional = 1;
			if (char_1 == char_2)
			{
				additional = 0;
			}

			uint32_t val_1 = distance_array[i][j - 1] + 1;
			uint32_t val_2 = distance_array[i - 1][j] + 1;
			uint32_t val_3 = distance_array[i - 1][j - 1] + additional;

			distance_array[i][j] = std::min({ val_1, val_2, val_3 });
		}
	}

	uint32_t result = distance_array[N-1][M-1];
	//printArray(distance_array, N, M);

	for (size_t i = 0; i < N; i++) { delete distance_array[i]; }
	delete[] distance_array;

	return result;
}



int main()
{
	std::string str_1 = "rubd";
	std::string str_2 = "run";
	std::cout << leviDistance(str_1, str_2) << std::endl;
}