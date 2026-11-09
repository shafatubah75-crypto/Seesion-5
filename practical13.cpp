
#include <iostream>
#include <vector>
int main() {
    int score = 75;
    int* pointer = &score;
    std::cout << "score = " << score << "\n&score = " << &score << "\npointer = " << pointer
              << "\n*pointer = " << *pointer << "\n";
    *pointer = 90;
    std::cout << "After *pointer = 90 -> score = " << score << ", *pointer = " << *pointer << "\n";
    // Addresses differ between runs because the OS places the program at different
    // memory locations each time (address space layout randomisation).

    int n;
    std::cout << "\nArray size (1-1000): ";
    if (!(std::cin >> n) || n < 1 || n > 1000) { std::cout << "Invalid size.\n"; return 1; }
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) arr[i] = (i + 1) * 10;
    for (int i = 0; i < n; ++i) std::cout << arr[i] << ' ';
    std::cout << "\n";
    delete[] arr;      // exactly once
    arr = nullptr;     // no dangling pointer; a second delete[] of nullptr is harmless
    // A leak happens when new[] is not matched by delete[] (e.g. early return or lost pointer).

    std::vector<int> v(n);                 // extra challenge: vector frees itself automatically
    for (int i = 0; i < n; ++i) v[i] = (i + 1) * 10;
    std::cout << "Vector sum check, last element: " << v.back() << "\n";
    return 0;
}
