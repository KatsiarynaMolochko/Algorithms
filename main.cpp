#include <iostream>
#include <vector>
#include <fstream>

#define fast std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);


int h(int x, int invar, int m, int attempt) {
    int tmp = x % m;
    int shift = ((invar % m) * (attempt % m)) % m;
    int res = ((tmp % m) + shift) % m;
//    int res = ((x % m) + invar * attempt) % m;
    return res;
}

int main() {
    fast;
    std::ifstream in ("input.txt");
    std::ofstream out ("output.txt");

    int size = 0;
    int invar = 0;
    int keys = 0;
    in >> size >> invar >> keys;

    std::vector<int> data(keys);
    for (int i = 0; i < keys; ++i) {
        in >> data[i];
    }

    std::vector<int> hash_table(size, -1);

    for (int i : data) {
        int attempt = 0;
        int index = h(i, invar, size, attempt);
        if (hash_table[index] == i){
            continue;
        }
        while (hash_table[index] != -1 && hash_table[index] != i) {
            attempt++;
            index = h(i, invar, size, attempt);
            // тут надо переписать так, чтобы была проверка на закидывание в следующую ячейку break не отработает :) нормально
        }
        if (hash_table[index] == i) {
            continue;

        }
        hash_table[index] = i;
    }

    for (int i : hash_table) {
        out << i << ' ';
    }

    in.close();
    out.close();
    return 0;
}
