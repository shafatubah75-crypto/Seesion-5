
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
struct Student { int id; std::string name; double average; };

void print(const std::vector<Student>& v) {
    for (const Student& s : v) std::cout << "  " << s.id << " " << s.name << " " << s.average << "\n";
}
int main() {
    std::vector<Student> students = {
        {1, "Amina", 72.5}, {2, "Brice", 48.0}, {3, "Chantal", 91.0}, {4, "Daniel", 50.0},
        {5, "Estelle", 72.5}, {6, "Frank", 35.5}, {7, "Grace", 66.0}};
    std::cout << "Original order:\n"; print(students);

    // Descending by average; ties broken by ascending ID so the order is predictable.
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        if (a.average != b.average) return a.average > b.average;
        return a.id < b.id;
    });
    std::cout << "\nSorted order:\n"; print(students);

    double threshold = 50.0;       // extra challenge: captured configurable threshold
    std::cout << "\nPass threshold (default 50, enter value): ";
    double t;
    if (std::cin >> t && t >= 0 && t <= 100) threshold = t;
    auto passCount = std::count_if(students.begin(), students.end(),
                                   [threshold](const Student& s) { return s.average >= threshold; });
    std::cout << "\nTop three:\n";
    for (std::size_t i = 0; i < students.size() && i < 3; ++i)
        std::cout << "  " << i + 1 << ". " << students[i].name << " (" << students[i].average << ")\n";
    std::cout << "Students with average >= " << threshold << ": " << passCount << "\n";
    return 0;
}
