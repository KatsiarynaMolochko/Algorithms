#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream in ("input.txt");
    std::ofstream  out ("output.txt");

    int size = 0;
    in >> size;
    std::vector<std::vector<int>> F(size, std::vector<int >(size, 0));

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            in >> F[i][j];
        }
    }

    std::vector<int> tree(size, 0);


    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if(F[i][j] == 1) {
                tree[j] = i + 1;
            }
        }
    }

    for (int i = 0; i < size; ++i) {
        out << tree[i] << " ";
    }



    std::cout << "Hello, World!" << std::endl;

    return 0;
}
