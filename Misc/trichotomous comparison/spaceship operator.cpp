// GCC 12.1 (C++ 20)
#include <compare>
#include <iostream>
using namespace std;

struct Person {
    string name;
    int age;
    auto operator<=>(const Person&) const = default;
};

int main() {
    Person john {"John", 30};
    Person jane {"Jane", 25};

    auto result = john <=> jane;
    if (result > 0) 
        cout << john.name << " is older than " << jane.name << endl;
    else if (result < 0) 
        cout << john.name << " is younger than " << jane.name << endl;
    else 
        cout << john.name << " and " << jane.name << " are of the same age" << endl;

    return 0;
}
