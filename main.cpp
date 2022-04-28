#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>

#define fast std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);



int findSet(std::vector<int>& towns, int town) {
    if(towns[town] == town) {
        return town;
    }
    return towns[town] = findSet(towns, towns[town]);
}

int buildingRoads (std::vector<int>& towns, std::vector<int>& size, std::pair<int, int>& request) {
    int from_index = findSet(towns, request.first);
    int to_index = findSet(towns, request.second);
    int unions = 0;
    if (from_index != to_index) {

        if (size[from_index] < size[to_index]) {
            std::swap(from_index, to_index);
        }
        towns[to_index] = from_index;
        size[from_index] += size[to_index];
        unions++;
    }

    return unions;
}

int main() {
    fast;
    std::ifstream in ("input.txt");
    std::ofstream out ("output.txt");

    int towns_amount = 0;
    int requests_amount = 0;
    in >> towns_amount >> requests_amount;

    std::vector<int> towns(towns_amount + 1, 0);
    for (int i = 1; i <= towns_amount; ++i) {
        towns[i] = i;
    }

    std::vector<int> size (towns_amount + 1, 1);


    std::pair<int, int> road;
    std::vector<std::pair<int, int>> roads (requests_amount + 1);
    for (int i = 1; i <= requests_amount; ++i) {
        in >> road.first >> road.second;
        roads[i] = road;
    }

    int components = towns_amount;
    for (int i = 1; i < requests_amount + 1; ++i) {
        components -= buildingRoads(towns, size, roads[i]);
        out << components  << "\n";
    }



    in.close();
    out.close();

    return 0;
}