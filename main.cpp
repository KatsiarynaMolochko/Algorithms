#include <iostream>
#include <vector>
#include <fstream>

int main() {
    std::ifstream  in ("input.txt");
    std::ofstream out ("output.txt");

    int vertex = 0;
    int edge = 0;

    in >> vertex;
    in >> edge;


    std::vector<std::pair<int, int>> edges;
    std::pair<int, int> road;

    while(in >> road.first >> road.second){
        edges.push_back(road);
    }

    std::vector<std::vector<int>> adjacency(vertex);


    for (int i = 0; i < edge; ++i) {
        adjacency[edges[i].first - 1].push_back(edges[i].second);
        adjacency[edges[i].second - 1].push_back(edges[i].first);
    }

    for (int i = 0; i < vertex; ++i) {
        out << adjacency[i].size() << " ";
        for (int j = 0; j < adjacency[i].size(); ++j) {
            out << adjacency[i][j] << ' ';
        }
        out << "\n";
    }


    in.close();
    out.close();
    return 0;
}
