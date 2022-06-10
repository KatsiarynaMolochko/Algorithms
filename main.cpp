#include <iostream>
#include <fstream>
#include <vector>

#define fast std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int next_ind = 1;

void DFS(std::vector<std::vector<int>>& matrix, std::vector<bool>& visited, std::vector<int>& order, int vertex){
    visited[vertex] = true;
    order[vertex] = next_ind;
    next_ind += 1;

    for (int j = 1; j < matrix.size(); ++j) {
        if (!visited[j] && matrix[vertex][j]) {
            DFS(matrix, visited, order, j);
        }
    }

}

int main() {
    fast;
    std::ifstream in ("input.txt");
    std::ofstream out ("output.txt");
    int size = 0;
    in >> size;
    std::vector<std::vector<int>> adj_matrix (size + 1, std::vector<int>(size + 1,0));

    for (int i = 1; i <= size; ++i) {
        for (int j = 1; j <= size; ++j) {
            in >> adj_matrix[i][j];
            std::cout << adj_matrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::vector<bool> visited (size + 1,false);
    std::vector<int> order (size + 1, -1);

    for (int i = 1; i <= size ; ++i) {
        if (!visited[i]) {
            DFS(adj_matrix, visited, order, i);
        }
    }

    for (int i = 1; i <= size; ++i) {
        out << order[i] << " ";
    }

    in.close();
    out.close();
    return 0;
}
