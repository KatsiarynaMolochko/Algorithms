#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

#define fast std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int upper_bound(const std::vector<int>& arr, int key) {
    int mid;
    int begin = 0;
    int end = arr.size();

    while (begin < end) {
        mid = (begin + end) / 2;
        if (key > arr[mid]) {
            begin = mid + 1;
        } else {
            end = mid;
        }
    }
    return begin;
}



std::vector<int> assendingSub (std::vector<int> array, int size) {
    std::vector <int> res;
    std::vector <int> length;
    res.push_back(array[0]);
    length.push_back(1);
    int little = -1;
    for (int i = 1; i < size; ++i) {
        little = upper_bound(res,array[i]);
        if (little == res.size() && res[res.size() - 1] != array[i]) {
            res.push_back(array[i]);
        } else if (res[little] > array[i]) {
            res[little] = array[i];
        }
        length.push_back(res.size());
    }
    return length;
}






int main() {
    fast;
    std::ifstream in ("input.txt");
    std::ofstream out ("output.txt");

    int size;
    in >> size;

    std::vector <int> sequence (size);
    for (int i = 0; i < size; ++i) {
        in >> sequence[i];
    }

    std::vector<int> from_begin_to_i;
    from_begin_to_i = assendingSub(sequence, size);

//    std::cout << "from 0 index to i length of strictly increasing subsequence\n" ;
//    for (int i = 0; i < from_begin_to_i.size(); ++i) {
//        std::cout << from_begin_to_i[i] << " ";
//    }

    std::vector<int> from_i_to_end;
    std::reverse(sequence.begin(), sequence.end());
    for (int i = 0; i < size; ++i) {
        sequence[i] *= -1;
    }
    from_i_to_end = assendingSub(sequence,size);
    std::reverse(from_i_to_end.begin(), from_i_to_end.end());


//    std::cout << "from i to end index length of strictly increasing subsequence\n";
//    for (int i = 0; i < from_i_to_end.size(); ++i) {
//        std::cout << from_i_to_end[i] << " ";
//    }

    int max = 0;
    for (int i = size - 1; i >= 0; --i) {
        if (from_i_to_end[i] > max) {
            max = from_i_to_end[i];
        } else {
            from_i_to_end[i] = max;
        }
    }

    int max_sum = 0;
    int sum = 0;
    if (size == 1) {
        max_sum = 1;
    }
    for (int i = 0; i < size - 1; ++i) {
        sum = from_begin_to_i[i] + from_i_to_end[i + 1];
        if (sum > max_sum) {
            max_sum = sum;
        }
    }
//    std::cout <<  "\n max sum is: " << max_sum;
    out << max_sum;


    in.close();
    out.close();
    return 0;
}