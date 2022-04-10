#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

#define fast std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main() {
    fast;
    std::ifstream in ("huffman.in");
    std::ofstream out ("huffman.out");

    int size = 0;
    in >> size;

    std::vector<long long> nodes(size);
    for (int i = 0; i < size; ++i) {
        in >> nodes[i];
    }

    std::priority_queue<long long, std::vector<long long >, std::greater<>> queue(nodes.begin(), nodes.end());

    long long sum = 0;
    while (queue.size() > 1){
        long long new_node = 0;
        new_node += queue.top();
        sum += queue.top();
        queue.pop();
        new_node += queue.top();
        sum += queue.top();
        queue.push(new_node);
        queue.pop();
    }

//    for (int i = 0; i < nodes.size(); ++i) {
//        std::cout << queue.top() << " ";
//        queue.pop();
//    }

    std::cout << sum << " ";

    out << sum;
    in.close();
    out.close();
    return 0;
}
