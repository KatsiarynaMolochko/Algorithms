#include <iostream>
#include <fstream>
#include <vector>



int main() {
    std::ifstream in ("input.txt");
    std::ofstream out ("output.txt");

    int vertices = 0;
    in >> vertices;

    std::vector<std::pair<int, int>> family;

    std::pair<int, int> friends;

    while(in >> friends.first >> friends.second) {
        family.push_back(friends);
    }

    std::vector<int> canonian (vertices, 0);

    for (auto & i : family) {
        canonian[i.second - 1] = i.first;
    }

    for (int i : canonian) {
        out << i << ' ';
    }

    return 0;
}
