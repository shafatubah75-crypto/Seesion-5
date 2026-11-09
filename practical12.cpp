
#include <iostream>
void addBonusByValue(int mark)      { mark += 10; }   // modifies a COPY only
void addBonusByReference(int& mark) { mark += 10; }   // modifies the caller's variable
void addBonusCapped(int& mark, int bonus) {           // extra challenge
    mark += bonus;
    if (mark > 100) mark = 100;
}
void swapValues(int& a, int& b) { int t = a; a = b; b = t; }

int main() {
    int mark = 60;
    std::cout << "Before by value: " << mark << "\n";
    addBonusByValue(mark);
    std::cout << "After by value : " << mark << " (unchanged: function got a copy)\n";
    addBonusByReference(mark);
    std::cout << "After by ref   : " << mark << " (changed: reference is an alias of 'mark')\n";

    int m2 = 95;
    addBonusCapped(m2, 10);
    std::cout << "Capped 95+10   : " << m2 << "\n";

    int a = 10, b = 20;
    std::cout << "Before swap: " << a << " " << b << "\n";
    swapValues(a, b);
    std::cout << "After swap : " << a << " " << b << "\n";
    return 0;
}
