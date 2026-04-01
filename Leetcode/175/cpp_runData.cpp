#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

// Structs for Person and Address
struct Person {
    int personId;
    std::string firstName;
    std::string lastName;
};

struct Address {
    int addressId;
    int personId;
    std::string city;
    std::string state;
};

// Struct for Result
struct Result {
    std::string firstName;
    std::string lastName;
    std::string city;
    std::string state;
};

int main() {
    // Sample Data
    std::vector<Person> persons = {
        {1, "Wang", "Allen"},
        {2, "Alice", "Bob"}
    };

    std::vector<Address> addresses = {
        {1, 2, "New York City", "New York"},
        {2, 3, "Leetcode", "California"}
    };

    // Build a map from personId -> Address for fast lookup
    std::unordered_map<int, Address> addressMap;
    for (const auto& addr : addresses) {
        addressMap[addr.personId] = addr;
    }

    // Perform left join
    std::vector<Result> results;
    for (const auto& person : persons) {
        Result res;
        res.firstName = person.firstName;
        res.lastName = person.lastName;

        if (addressMap.find(person.personId) != addressMap.end()) {
            res.city = addressMap[person.personId].city;
            res.state = addressMap[person.personId].state;
        } else {
            res.city = "NULL";   // or empty string ""
            res.state = "NULL";
        }

        results.push_back(res);
    }

    // Optional: sort by firstName
    std::sort(results.begin(), results.end(), [](const Result& a, const Result& b) {
        return a.firstName < b.firstName;
    });

    // Print results
    std::cout << "firstName\tlastName\tcity\tstate\n";
    for (const auto& r : results) {
        std::cout << r.firstName << "\t" << r.lastName << "\t"
                  << r.city << "\t" << r.state << "\n";
    }

    return 0;
}