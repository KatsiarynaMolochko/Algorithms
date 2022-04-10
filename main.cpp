#include <iostream>
#include <fstream>
#include <vector>

#define fast std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);



int multOrder (std::vector<std::pair<int,int>>& matrices, int size) {
    int res = 0;
    std::vector<std::vector<int>> F(size, std::vector<int>(size,0));


    for (int i = 0; i < size - 1; ++i) {
        F[i][i + 1] = matrices[i].first * matrices[i].second * matrices[i+1].second;  //i+1
    }

    int prev = 0;
    int cur = 0;
    int min = std::numeric_limits<int>::max();
//
    for (int j = 0; j < size; ++j) {
        for (int i = j; i >= 0; --i) {

            if(i < j) {
                for (int k = i; (i <= k) && (k < j); ++k) {
                    cur = F[i][k] + F[k + 1][j] + matrices[i].first * matrices[k].second * matrices[j].second;
                    std::cout << "i = " << i << " j = " << j << " k = " << k << " cur= " << cur << "\n";
                    if(cur < min) {
                        min = cur;
                    }
                }
                F[i][j] = min;
                min = std::numeric_limits<int>::max();
            }
        }
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << F[i][j] << "\t";
        }
        std::cout << "\n";
    }

    return F[0][size-1];
}

int main() {
    fast

    std::ifstream file;
    file.open("input.txt");
    int amount = 0;
    file >> amount;

    std::vector<std::pair<int, int>> order;

    std::pair<int, int> matrix;

    while (file >> matrix.first >> matrix.second) {
        order.push_back(matrix);
    }

    int res = multOrder(order, amount);



    std::ofstream out("output.txt");
    out << res;

    out.close();
    file.close();
    return 0;
}
