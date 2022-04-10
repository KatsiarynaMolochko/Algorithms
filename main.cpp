#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#define fast std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

long long minOutOfThree(long long a, long long b, long long c) {
    if (b >= a && a <= c) {
        return a;
    } else if (a >= b && b <= c) {
        return b;
    } else {
        return c;
    }
}

long long levenshteinDistance(const std::string& first_word, const std::string& second_word, int ins, int del, int rep ) {
    std::vector<std::vector<long long>> F(first_word.size() + 1, std::vector<long long>(second_word.size() + 1,0));
    for (int i = 0; i < first_word.size() + 1; ++i) {
        for (int j = 0; j < second_word.size() + 1; ++j) {
            F[i][0] = i * del;
            F[0][j] = j * ins;
        }
    }


    for (int i = 1; i < first_word.size() + 1; ++i) {
        for (int j = 1; j < second_word.size() + 1; ++j) {
            int delta = 0;
            if (first_word[i-1] != second_word[j-1]) {
                delta = 1;
            }
            int minimum = std::min(rep, del + ins);
            F[i][j] = minOutOfThree(F[i - 1][j] + del, F[i][j - 1] + ins, F[i - 1][j - 1] + delta * minimum);
        }
    }

    for (int i = 0; i < first_word.size() + 1; ++i) {
        for (int j = 0; j < second_word.size() + 1; ++j) {
            std::cout << F[i][j] << "\t";
        }
        std::cout << "\n";
    }

    long long res = F[first_word.size()][second_word.size()];
    return res;
}




int main() {
    fast
    std::fstream input;
    input.open("in.txt");
    std::ofstream output("out.txt");


    int del = 0;
    int ins = 0;
    int rep = 0;

    input >> del >> ins >> rep;

    std::string fst_word;
    input >> fst_word;

    std::string snd_word;
    input >> snd_word;


    output << levenshteinDistance(fst_word, snd_word, ins, del, rep);
    input.close();
    output.close();

    return 0;

}
