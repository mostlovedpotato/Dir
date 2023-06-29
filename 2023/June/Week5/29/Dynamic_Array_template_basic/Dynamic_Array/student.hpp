#include <sstream>
#include <iostream>
#include <string>

// class student{
//     private:
//         std::string name;
//         int standard;
//     public:
//     student(std::string name1, int standard1){
//         name = name1;
//         standard = standard1;
//     }
//     friend std::ostream& operator<< (std::ostream& os, const student& s){
//         os << "[Name : " << s.name << ", Standard : " << s.standard << "]";
//     }
// };

struct student {
    std::string name;
    int standard;
};

std::ostream& operator<< (std::ostream& os, const student& s) {
    os << "[Name : " << s.name << ", Standard : " << s.standard << "]";
    return os;
}