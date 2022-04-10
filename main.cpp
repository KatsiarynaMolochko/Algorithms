#include <iostream>
#include <vector>
#include <algorithm>
#define fast std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);


const int INF_INF= -5000;

int main() {
    fast;
    int size = 0;
    std::cin >> size;
    std::vector<int> mosquitos(size);

    for (int i = 0; i < size; ++i) {
        std::cin >> mosquitos[i];
    }

    std::vector<int> eaten_mosq(size);
    std::vector<int> indecies(size);

    eaten_mosq[0] = mosquitos[0];
    eaten_mosq[1] = INF_INF;


    if (size == 2){
        std::cout << "-1";
        return 0;
    }

    if(size == 1) {
        std::cout << mosquitos[0] << "\n";
        std::cout << "1";
        return 0;
    }

    if(size == 3) {
        std::cout << mosquitos[0] + mosquitos[2] << "\n";
        std::cout << "1 3";
        return 0;
    }

    eaten_mosq[2] = eaten_mosq[0] + mosquitos[2];

    for (int i = 3; i < size; ++i) {
        eaten_mosq[i] = std::max(eaten_mosq[i - 2], eaten_mosq[i - 3]) + mosquitos[i];
        int max = std::max(eaten_mosq[i - 2], eaten_mosq[i - 3]);

        if(max == eaten_mosq[i-2]){
            indecies[i] = i - 2;
        } else {
            indecies[i] = i - 3;
        }

    }

    std::cout << eaten_mosq[size - 1] << "\n";             // 1 -1 1 10 1

    std::vector<int> path;

    for(int i = size - 1; i != 0; i = indecies[i]) {
        path.push_back(i + 1);
    }

    std::reverse(path.begin(), path.end());

    std::cout << 1 << " ";
    for(const auto& it: path) {
        std::cout << it << " ";
    }



    return 0;
}