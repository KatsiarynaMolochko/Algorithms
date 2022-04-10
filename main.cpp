#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define fast std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);


std::pair<std::string, int> palindrome(std::string str) {
    int size = str.size();
    std::vector<std::vector<int>> F(size, std::vector<int>(size,0));
    
    // filling first diagonals
    
    for (int i = 0; i < size; ++i) {
        F[i][i] = 1;
        if(i + 1 < size) {
            F[i][i + 1] = (str[i] == str[i + 1]) ? 2 : 1;
        }

    }
    
    //filling

    for (int j = 2; j < size; ++j) {
        for (int i = j; i >= 0; --i) {
            if (i < j) {
                if (str[i] == str[j]) {
                    F[i][j] = F[i + 1][j - 1] + 2;
                } else {
                    F[i][j] = std::max(F[i][j - 1],F[i + 1][j]);
                }
            }
        }
    }

    std::pair<std::string, int> res;
    res.second = F[0][size - 1];

    std::string pal;

//
    int i = 0;
    int j = size - 1;
    while (i <= j) {
        if (str[i] == str[j]) {
//            std::cout << "str[i]" << str[i] << " i = " << i << '\n';
            pal += str[i];
            ++i, --j;
        } else {
            int max = std::max(F[i + 1][j],F[i][j - 1]);
            (max == F[i + 1][j]) ? ++i : --j;
        }
    }

//    std::cout << "ATTTENTION " << pal << '\n';

//    if (pal.size() == 1) {
//        res.first = pal;
//        return res;
//    }

    for (int k = (res.second >> 1) - 1; k >= 0 ; --k) {
        pal += pal[k];
    }

//    std::cout << " " << pal << "\n";

    res.first = pal;

//    for (int k = 0; k < size; ++k) {
//        for (int l = 0; l < size; ++l) {
//            std::cout << F[k][l] << "\t";
//        }
//        std::cout << "\n";
//    }


    return res;

}


int main() {
    fast
    std::fstream input;
    input.open("input.txt");



    std::string word;
    input >> word;
    std::pair<std::string, int> res = palindrome(word);
    std::cout << res.first << "\n" << res.second;


    std::ofstream output;
    output.open("output.txt");
    output << res.second << '\n';
    output << res.first << "\n";



    input.close();
    output.close();
    return 0;
}
