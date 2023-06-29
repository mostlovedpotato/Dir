#include "dynamic_array.hpp"
#include "student.hpp"
#include<iostream>
#include <string>

int main() {
    int strength;
    std::cout << "Enter number of Students : ";
    std::cin >> strength;
    dynamic_array<student> class1(strength);
    for (int i = 0; i < strength; i++) {
        std::cout << "Enter name and class of student : " << i + 1 << '\n';
        std::string name;
        int standard;
        std::cin >> name >> standard;
        // student st(name,standard);
        class1[i] = student{ name,standard };
    }
    std::cout << class1.to_string();
}