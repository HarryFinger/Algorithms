#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vec {5,2,1,5,1,2,5,6,3,2,1,5,1,2,13};
    std::vector<int> counter(15);
    for (size_t i = 0; i < vec.size(); i++)
    {
        //std::cout << vec[i] << " ";
        (counter[vec[i]])++;
    }
    vec.clear();
    std::for_each(vec.begin(), vec.end(), [](const auto& a){std::cout << a<< " ";});

    for(size_t i = 0; i < counter.size(); ++i)
    {
        for (size_t j = 0; j < counter[i]; ++j)
        {
            vec.push_back(i);
        }
    }
    
    std::for_each(vec.begin(), vec.end(), [](const auto& a){std::cout << a<< " ";});
}