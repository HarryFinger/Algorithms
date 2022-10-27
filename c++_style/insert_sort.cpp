#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vec {5,1,2,3,7,1,2};
    std::vector<int> new_vec;
    
    new_vec.push_back(vec[0]);
    int j = 0;
    for (size_t i = 1; i < vec.size(); i++)
    {
        new_vec.push_back(vec[i]);
        j = i;
        while ((new_vec[j] < new_vec[j-1]) && (j > 0) )
        {
            std::swap(new_vec[j], new_vec[j-1]);
            --j;
        }    
    } 
    std::for_each(new_vec.begin(),new_vec.end(), [](const auto& a){std::cout << a << " ";});    
}