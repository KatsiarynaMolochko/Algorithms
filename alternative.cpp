#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>

#define fast std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);


int findSet(std::vector<int>& towns, int town) {
    if (town == towns[town]) {
        return town;
    }
    return  towns[town] = findSet(towns, towns[town]);
}
//function of union dsu
int buildingRoads(std::vector<int>& size, std::vector<int>& towns, std::pair<int, int>& req) {
    int unions = 0;
    int from = findSet(towns, req.first);
    int to = findSet(towns, req.second);
    if (from != to) {
        if (size[from] < size[to]) {
            std::swap(from, to);
        }
        towns[to] = from;
        size[from] += size[to];
        unions++;
    }


//    for (int i = 0; i < towns.size(); ++i) {
//        std::cout << towns[i] + 1 << " ";
//    }
//    std::cout << '\n';
//
//    for (int i = 0; i < size.size(); ++i) {
//        std::cout << size[i] << " ";
//    }
//    std::cout << "component is: " << component << "\n";
//    std::cout << '\n';

    return unions;

}


//void bruteforce() {
//    const int AMOUNT_VERTEXES = 500000;
//    const int AMOUNT_QUERIES = 500000;
//    std::ofstream output ("output_bruteforce.txt");
//
//    output << AMOUNT_VERTEXES << " " << AMOUNT_QUERIES << "\n";
//
//    for (int i = 1; i < AMOUNT_QUERIES; ++i) {
//        output << i << " " << i + 1 << "\n";
//    }
//}



int main() {
//    bruteforce();

    auto start = std::chrono::system_clock::now();
    fast;
    std::ifstream in ("input.txt");
    std::ofstream out ("output.txt");
    int towns_amount = 0;
    int requests = 0;
    in >> towns_amount >> requests;
    int component = towns_amount;


    // initialization of separated towns without roads
    std::vector<int> size (towns_amount,1);
    std::vector<int> towns (towns_amount,0);
//    std::cout << "vector of towns: ";
    for (int i = 1; i <= towns_amount; ++i) {
        towns[i] = i;
//        std::cout << towns[i] << " ";
    }

    //reading all request to build roads
    std::pair<int, int> road;
    std::vector<std::pair<int, int>> roads(requests);

//    while (in >> road.first >> road.second) {
//        road.first - 1;
//        road.second - 1;
//        roads.push_back(road);
//    }

    for (int i = 1; i <= requests; ++i) {
        in >> road.first >> road.second;
        roads[i] = road;
    }

//    std::cout << "vector of roads to build:\n";
//    for (int i = 0; i < roads.size(); ++i) {
//        std::cout << roads[i].first << " " << roads[i].second << '\n';
//    }



    for (int i = 1; i <= requests; ++i) {
        component -= buildingRoads(size, towns, roads[i]);
        out << component << "\n";
    }


    in.close();
    out.close();

//    auto end = std::chrono::system_clock::now();
//    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;
    return 0;
}