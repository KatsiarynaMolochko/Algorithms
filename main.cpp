#include <iostream>
#include <vector>
#include <string>
#include <fstream>


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

//    if(begin < arr.size() && arr[begin] <= key) {
//        begin++;
//    }

    return begin;
}

std::vector<int> assendingSub (std::vector<int> array, int size) {
    std::vector <int> res;
    res.push_back(array[0]);
    int little = -1;
    for (int i = 1; i < size; ++i) {
        little = upper_bound(res,array[i]);
        if (little == res.size() && res[res.size() - 1] != array[i]) {
            res.push_back(array[i]);
        } else if (res[little] > array[i]) {
           res[little] = array[i];
        }

    }

    return res;
}

int main()
{
    std::ifstream input ("input.txt");


    int size = 0;
    input >> size;
    std::vector<int> arr(size);

    for (int i = 0; i < size; ++i) {
        input >> arr[i];
    }

    std::vector<int> result = assendingSub(arr,size);


    std::ofstream output ("output.txt");
    output << result.size();

    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << "\t";
    }


    output.close();
    input.close();

    return 0;
}