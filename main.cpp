#include <iostream>
#include <vector>
#include <limits>

unsigned long long towerUnite(std::vector<std::pair<unsigned long long, unsigned long long>> cubes, int size){
    std::vector<std::vector<unsigned long long>> F(size, std::vector<unsigned long long >(size, std::numeric_limits<unsigned long long>::max()));

    for (int i = 0; i < size; ++i) {
        F[i][i] = 0;
        if (i + 1 < size) {
            F[i][i + 1] = cubes[i].first * cubes[i + 1].second;
        }
    }

    unsigned long long cur = 0;

    for (int j = 0; j < size; ++j) {
        for (int i = j; i >= 0; --i) {
            if (i < j) {
                for (int k = i;  (i <= k) && (k < j); ++k) {
                    cur = F[i][k] + F[k + 1][j] + cubes[i].first * cubes[j].second;
                    if (cur < F[i][j]) {
                        F[i][j] = cur;
                    }
                }
            }
        }

    }

    unsigned long long res = F[0][size - 1];
    return res;
}

int main(){
    int size = 0;
    std::cin >> size;

    std::vector<std::pair<unsigned long long, unsigned long long>> cubes(size);
    int x = 0;
    int y = 0;

    for (int i = 0; i < size; ++i) {
        std::cin >> x >> y;
        cubes[i] = std::make_pair(x,y);
    }

    std::cout << towerUnite(cubes, size);


    return 0;
}