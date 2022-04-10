#include <iostream>
#include <algorithm>
#define fast std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);



long long factorial_mod(int number, long long P) {
    long long f = 1;
    for (int i = 1; i < number + 1; ++i) {
        f = (f * i) % P;
    }
    return f;
}

long long binpow_mod (long long a,  long long b, long long power) {
    if (b == 1) {
        return a;
    }
    if (b % 2 == 1) {
        return binpow_mod(a, b - 1, power) * a % power;
    } else {
        long long tmp = binpow_mod(a, b / 2, power);
        return tmp * tmp % power;
    }
}

int main() {
    fast;
    long long P = 1e9 + 7;
    int places;
    std::cin >> places;
    int ones;
    std::cin >> ones;
    long long result = (factorial_mod(places, P) * binpow_mod((factorial_mod(ones, P) * factorial_mod(places-ones, P) % P), P - 2, P)) % P;
//    long long result = binpow_mod(2, P-2, P);
    std::cout << result << "\n";

    return 0;

}