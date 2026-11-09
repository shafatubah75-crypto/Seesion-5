
#include <iostream>
#include <string>
// 20! = 2,432,902,008,176,640,000 is the largest factorial that fits in long long.
const int MAX_N = 20;

long long factorial(int n, int depth = 0) {
    std::string pad(depth * 2, ' ');
    std::cout << pad << "factorial(" << n << ") called\n";
    long long result;
    if (n == 0 || n == 1) result = 1;                    // base cases
    else result = n * factorial(n - 1, depth + 1);
    std::cout << pad << "factorial(" << n << ") returns " << result << "\n";
    return result;
}
long long recursiveSum(int n) { return n <= 0 ? 0 : n + recursiveSum(n - 1); }
long long factorialIterative(int n) { long long r = 1; for (int i = 2; i <= n; ++i) r *= i; return r; }
long long sumIterative(int n) { long long s = 0; for (int i = 1; i <= n; ++i) s += i; return s; }

int main() {
    int n;
    std::cout << "Enter n (0-" << MAX_N << "): ";
    if (!(std::cin >> n) || n < 0 || n > MAX_N) { std::cout << "Invalid n.\n"; return 1; }
    std::cout << "factorial(" << n << ") = " << factorial(n) << "\n";
    std::cout << "iterative  = " << factorialIterative(n) << "\n";
    std::cout << "recursiveSum(" << n << ") = " << recursiveSum(n) << ", iterative = " << sumIterative(n) << "\n";
    return 0;
}
