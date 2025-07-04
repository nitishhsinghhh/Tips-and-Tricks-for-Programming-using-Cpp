#include <iostream>
#include <sstream>
#include <vector>

class ArrayListManager {
public:
    std::vector<std::string> AddString(std::string inputString,
                                       char delimiter) {
        std::vector<std::string> list;
        if (inputString.empty()) {
            return list;
        }
        if (inputString.find(delimiter) != std::string::npos) {
            std::stringstream ss(inputString);
            std::string value;
            while (getline(ss, value, delimiter))
                list.push_back(value);
        } else
            list.push_back(inputString);
        return list;
    }
};

int main() {
    ArrayListManager manager;

    // Test Case 1: input = "apple,banana,cherry",  delimiter = ','
    std::vector<std::string> list1 =
        manager.AddString("apple,banana,cherry", ',');
    std::cout << "List 1:" << std::endl;
    for (int i = 0; i < list1.size(); i++)
        std::cout << list1[i] << std::endl;
    std::cout << std::endl;

    // Test Case 2: input = "red|green|blue",  delimiter = '|'
    std::vector<std::string> list2 = manager.AddString("red|green|blue", '|');
    std::cout << "List 2:" << std::endl;
    for (int i = 0; i < list2.size(); i++)
        std::cout << list2[i] << std::endl;
    std::cout << std::endl;

    // Test Case 3: input = "1;2;3;4",  delimiter = ';'
    std::vector<std::string> list3 = manager.AddString("1;2;3;4", ';');
    std::cout << "List 3:" << std::endl;
    for (int i = 0; i < list3.size(); i++)
        std::cout << list3[i] << std::endl;
    std::cout << std::endl;

    // Test Case 4: input = Hello, world!",  delimiter = ' '
    std::vector<std::string> list4 = manager.AddString("Hello, world!", ' ');
    std::cout << "List 4:" << std::endl;
    for (int i = 0; i < list4.size(); i++)
        std::cout << list4[i] << std::endl;
    std::cout << std::endl;

    // Test Case 5: input = "",  delimiter = ','
    std::vector<std::string> list5 = manager.AddString("", ',');
    std::cout << "List 5:" << std::endl;
    for (int i = 0; i < list5.size(); i++)
        std::cout << list5[i] << std::endl;
    std::cout << std::endl;

    // Test Case 6: input = "1-2-3-4-5",  delimiter = '-'
    std::vector<std::string> list6 = manager.AddString("1-2-3-4-5", '-');
    std::cout << "List 6:" << std::endl;
    for (int i = 0; i < list6.size(); i++)
        std::cout << list6[i] << std::endl;
    std::cout << std::endl;

    // Test Case 7: input = "car;bus;train;plane",  delimiter = ','
    std::vector<std::string> list7 =
        manager.AddString("car;bus;train;plane", ';');
    std::cout << "List 7:" << std::endl;
    for (int i = 0; i < list7.size(); i++)
        std::cout << list7[i] << std::endl;
    std::cout << std::endl;

    // Test Case 8: input = "1",  delimiter = ','
    std::vector<std::string> list8 = manager.AddString("1", ',');
    std::cout << "List 8:" << std::endl;
    for (int i = 0; i < list8.size(); i++)
        std::cout << list8[i] << std::endl;
    std::cout << std::endl;

    // Test Case 9: input = "1,2,3,4,5,6,7,8,9,10",  delimiter = ','
    std::vector<std::string> list9 =
        manager.AddString("1,2,3,4,5,6,7,8,9,10", ',');
    std::cout << "List 9:" << std::endl;
    for (int i = 0; i < list9.size(); i++)
        std::cout << list9[i] << std::endl;
    std::cout << std::endl;

    // Test Case 10: input = "cat,dog,bird",  delimiter = ' '
    std::vector<std::string> list10 = manager.AddString("cat,dog,bird", ' ');
    std::cout << "List 10:" << std::endl;
    for (int i = 0; i < list10.size(); i++)
        std::cout << list10[i] << std::endl;
    std::cout << std::endl;

    return 0;
}
