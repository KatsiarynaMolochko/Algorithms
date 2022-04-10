#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream  input;
    input.open("input.txt");
    std::ofstream output;
    output.open("output.txt");

    int size = 0;
    input >> size;
    
    std::vector<int> heap(size);
    for (int i = 0; i < size; ++i) {
        input >> heap[i];
    }

    for (int i = 0; i < size; ++i) {
        if (2 * i + 2 < size) {
            if (heap[2 * i + 2] < heap[i]) {
                output << "No";
                output.close();
                return 0;
            }
        }

        if (2 * i + 1 < size) {
            if (heap[2 * i + 1] < heap[i]) {
                output << "No";
                output.close();
                return 0;
            }
        }
    }
    output << "Yes";



    input.close();
    output.close();
    return 0;
}
