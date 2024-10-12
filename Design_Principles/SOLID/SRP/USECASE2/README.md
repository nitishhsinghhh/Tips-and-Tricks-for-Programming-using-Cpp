# ArrayListManager Example

This repository contains a simple C++ program that demonstrates the functionality of the `ArrayListManager` class, which splits strings based on a given delimiter. The program takes input strings, applies the delimiter, and stores the resulting substrings in a vector. Several test cases are provided to showcase how different input strings and delimiters are handled.

## Table of Contents

- [Introduction](#introduction)
- [How It Works](#how-it-works)
- [Class Definition](#class-definition)
- [Test Cases](#test-cases)
- [Compilation and Execution](#compilation-and-execution)
- [Output](#output)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The `ArrayListManager` class splits input strings into substrings based on a specified delimiter. If the string contains the delimiter, it will be divided into separate substrings and returned as a vector. Otherwise, the original string is stored as a single element in the vector.

This example program showcases the use of the class with different strings and delimiters, demonstrating how the class handles both valid and edge cases.

## How It Works

1. **Input**: The user provides a string and a delimiter (e.g., ',', '|', ';').
2. **Processing**: The `ArrayListManager::AddString` function splits the string based on the delimiter and returns a vector of substrings.
3. **Output**: The program prints each substring from the resulting vector.

## Class Definition

### `ArrayListManager`

```cpp
class ArrayListManager {
public:
    std::vector<std::string> AddString(std::string inputString, char delimiter) {
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
```
The AddString function does the following:

- If the input string is empty, it returns an empty vector.
- If the string contains the delimiter, it splits the string and stores each substring into the vector.
- If the delimiter is not present, the entire input string is added to the vector as a single element.

## Test Cases

The program includes 10 test cases to demonstrate the versatility of the ArrayListManager class with different input strings and delimiters.

Example Test Cases
1. Input: "apple,banana,cherry", Delimiter: ','
2. Input: "red|green|blue", Delimiter: '|'
3. Input: "1;2;3;4", Delimiter: ';'
4. Input: "Hello, world!", Delimiter: ' '
5. Input: "", Delimiter: ','
6. Input: "1-2-3-4-5", Delimiter: '-'
7. Input: "car;bus;train;plane", Delimiter: ';'
8. Input: "1", Delimiter: ','
9. Input: "1,2,3,4,5,6,7,8,9,10", Delimiter: ','
10. Input: "cat,dog,bird", Delimiter: ' '

Each test case will print the resulting list of substrings.

## Compilation and Execution

### Steps to compile and run the code:
1. Ensure you have a C++ compiler installed (e.g., g++).
2. Download or clone the repository.
3. Compile the code using the following command:

```
bash
g++ -o array_list_manager array_list_manager.cpp
```
4. Run the program:
```
bash
./array_list_manager
```

## Output

The program outputs the following for each test case:
```
List 1:
apple
banana
cherry

List 2:
red
green
blue

List 3:
1
2
3
4

List 4:
Hello,
world!

List 5:

List 6:
1
2
3
4
5

List 7:
car
bus
train
plane

List 8:
1

List 9:
1
2
3
4
5
6
7
8
9
10

List 10:
cat,dog,bird
```

## Contributing

Contributions are welcome! If you have any suggestions or improvements, feel free to open an issue or submit a pull request.

## License

This project is licensed under the MIT License - see the LICENSE file for details.
```
This `README.md` file provides a clear explanation of the program, including how to compile and run it, as well as examples of its output for various test cases.
```
