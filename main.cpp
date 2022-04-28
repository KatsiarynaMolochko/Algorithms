#include <iostream>
#include <fstream>
#include <vector>
#include <queue>


#define fast std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
int next_index = 1;

void BFS(std::vector<std::vector<int>>& matrix, std::vector<bool>& visited, std::vector<int>& order, int vertex) {
    std::queue<int> q;
    visited[vertex] = true;
    order[vertex] = next_index;
    next_index += 1;
    q.push(vertex);

    while (!q.empty()) {
        int new_vertex = q.front();
        q.pop();

        for (int i = 1; i < matrix.size(); ++i) {
            if (matrix[new_vertex][i] && !visited[i]) {
                visited[i] = true;

                order[i] = next_index;
                next_index += 1;
                q.push(i);
            }
        }
    }



}

int main() {
    fast;
    std::ifstream in ("input.txt");
    std::ofstream out ("output.txt");

    int size = 0 ;
    in >> size;

    std::vector<std::vector<int>> matrix (size + 1, std::vector<int>(size + 1,0));

    for (int i = 1; i <= size; ++i) {
        for (int j = 1; j <= size; ++j) {
            in >> matrix[i][j];
//            std::cout << matrix[i][j] << " ";
        }
//        std::cout << "\n";
    }

    std::vector<bool> visited (size + 1, false);
    std::vector<int> order (size + 1, 0);
    for (int i = 1; i <= size; ++i) {
        if (!visited[i]) {
            BFS(matrix, visited, order, i);
        }

    }


    for (int i = 1; i <= size; ++i) {
        out << order[i] << " ";
    }


    in.close();
    out.close();
    return 0;
}
