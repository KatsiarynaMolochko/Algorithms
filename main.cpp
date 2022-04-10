#include <iostream>
#include <vector>


int lower_bound(const std::vector<int>& arr, int key) {
    int mid;
    int begin = 0;
    int end = arr.size();

    while (begin < end) {
        mid = (begin + end) / 2;
        if (key <= arr[mid]) {
            end = mid;
        } else {
            begin = mid + 1;
        }
    }

    if(begin < arr.size() && arr[begin] < key) {
        begin++;
    }

    return begin;
}

int upper_bound(const std::vector<int>& arr, int key) {
    int mid;
    int begin = 0;
    int end = arr.size();

    while (begin < end) {
        mid =(begin + end) / 2;
        if (key >= arr[mid]) {
            begin = mid + 1;
        } else {
            end = mid;
        }
    }

    if(begin < arr.size() && arr[begin] <= key) {
        begin++;
    }

    return begin;
}

int binary_search(const std::vector<int>& arr, int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x) return 1;
        if (arr[m] < x) l = m + 1;
        else r = m - 1;
    }

    return 0;
}

int main() {
    int size_arr = 0;
    std::cin >> size_arr;
    std::vector<int> arr(size_arr);
    for (int i = 0; i < size_arr; ++i) {
        std::cin >> arr[i];
    }
    int size_req = 0;
    std::cin >> size_req;
    for (int i = 0; i < size_req; ++i) {
        int val;
        std::cin >> val;
        std::cout << binary_search(arr, 0, arr.size() - 1, val) <<' ';
        std::cout << lower_bound(arr, val) << ' ';
        std::cout << upper_bound(arr, val) << "\n";
    }

    return 0;
}
