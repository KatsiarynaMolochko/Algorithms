#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

#define fast std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);


int findSet(std::vector<int>& towns, int town) {
    if(towns[town] == town) {
        return town;
    }
    return towns[town] = findSet(towns, towns[town]);
}



int ruiningRoads (std::vector<int>& towns, std::vector<int>& size, std::pair<int, int>& request) {
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

    int towns_amt = 0;
    int roads_amt = 0;
    int eq_amt = 0;

    in >> towns_amt >> roads_amt >> eq_amt;

    std::vector<int> towns (towns_amt + 1);
    std::vector<int> size (towns_amt + 1, 1);
    for (int i = 1; i < towns.size(); ++i) {
        towns[i] = i;
    }

    std::vector<std::pair<int, int>> roads (roads_amt + 1);
    for (int i = 1; i < roads.size(); ++i) {
        in >> roads[i].first >> roads[i].second;
    }

    std::vector<int> earthquakes (eq_amt + 1);
    for (int i = 1; i < earthquakes.size(); ++i) {
        in >> earthquakes[i];
    }

    std::vector<bool> build_this_road (roads.size(), true);

    for (int i = 1; i < earthquakes.size(); ++i) {
        if (earthquakes[i]) {
            build_this_road[earthquakes[i]] = false;
        }
    }

    int components = towns_amt;
    for (int i = 1; i < roads.size() ; ++i) {
        if (build_this_road[i]) {
            components -= ruiningRoads(towns, size, roads[i]);
        }
    }


    std::string result;
    int counter = 0;

    for (int i = eq_amt; i > 0 ; --i) {
        int prev_comp = components;
        components -= ruiningRoads(towns, size, roads[earthquakes[i]]);
        if (components == 1) {
            if (prev_comp != 1) {
                result += "0";
            } else {
                result += "1";
                for (int j = i - 1; j > 0 ; --j) {
                    result += "1";
                }
                break;
            }
        } else {
            result += "0";
        }


    }

    std::reverse(result.begin(), result.end());
    out << result;


//    std::cout << "Hello, World!" << std::endl;
    in.close();
    out.close();
    return 0;
}
