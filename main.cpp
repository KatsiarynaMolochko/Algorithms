#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream in ("input.txt");
    std::ofstream out ("output.txt");

    int vertex = 0;
    int edge = 0;

    in >> vertex;
    in >> edge;

    std::vector<std::pair <int, int>> edges;
    std::pair<int,int> s_edge;

    while (in >> s_edge.first >> s_edge.second) {
        edges.push_back(s_edge);
    }

    std::vector<std::vector<int>> F(vertex, std::vector<int >(vertex, 0));

    for (int i = 0; i < edge; ++i) {
        std::cout << edges[i].first << " " << edges[i].second << "\n";
    }



    for (int i = 0; i < edge; ++i) {
        F[edges[i].first - 1][edges[i].second - 1] = 1;
        F[edges[i].second - 1][edges[i].first - 1]  = 1;
    }


    for (int i = 0; i < vertex; ++i) {
        for (int j = 0; j < vertex; ++j) {
            out << F[i][j] << " ";
        }
        out << '\n';
    }


    in.close();
    out.close();
    return 0;
}
