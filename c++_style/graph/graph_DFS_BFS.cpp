#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

class Graph
{
public:
    void input(std::ifstream &in)
    {
        in >> vertices;
        in >> edges;
        lists_of_adjacency.resize(vertices);
        for (size_t i = 0; i < edges; i++)
        {
            uint32_t a, b;
            in >> a >> b;
            lists_of_adjacency[a].insert(b);
            lists_of_adjacency[b].insert(a);
        }
    }

    void print()
    {
        for (size_t i = 0; i < vertices; i++)
        {
            std::cout << i << " : [";

            for (const auto &el : lists_of_adjacency[i])
            {
                std::cout << el << ", ";
            }
            std::cout << "\b\b]\n";
        }
    }

    // Depth-first search. Recursive realization
    void DFS(uint32_t start_index)
    {
        std::vector<bool> used;
        used.resize(vertices, false);
        DFS_print(used, start_index);
    }

    // Breadth-first search. FIFO realization
    void BFS(uint32_t start_index)
    {
        std::vector<bool> used;
        used.resize(vertices, false);

        used[start_index] = true;
        std::queue<uint32_t> firing_list;
        firing_list.push(start_index);

        std::cout << start_index << " "; // firing

        while (!firing_list.empty())
        {
            uint32_t current = firing_list.front();
            firing_list.pop();

            for (auto neighbour : lists_of_adjacency[current])
            {
                if (!used[neighbour])
                {
                    std::cout << neighbour << " "; // firing
                    used[neighbour] = true;
                    firing_list.push(neighbour);
                }
            }
        }
    }

private:
    uint32_t vertices = 0;
    uint32_t edges = 0;
    std::vector<std::set<uint32_t>> lists_of_adjacency;

private:
    void DFS_print(std::vector<bool> &used, uint32_t vertex)
    {
        used[vertex] = true;
        std::cout << vertex << " ";
        for (uint32_t neighbour : this->lists_of_adjacency[vertex])
        {
            if (!used[neighbour])
            {
                DFS_print(used, neighbour);
            }
        }
    }
};

int main()
{
    std::ifstream file;
    file.open("./test.txt");

    if (file.is_open())
    {
        std::cout << "file is open" << std::endl;
    }
    else
    {
        std::cout << "file is NOT open" << std::endl;
        return 1;
    }

    Graph graph;
    graph.input(file);
    graph.print();
    std::cout << std::endl;

    graph.DFS(4);
    std::cout << std::endl;

    graph.BFS(4);
}