#include <iostream>
#include <array>

class NumbersArray {
private:
	std::array<int, 5> arr;
public:
	NumbersArray() : arr({ 1, 2, 3, 4, 5 }) {}

	int getNumberAtIndex(int index) const {
		if (index < 0 || index >= arr.size()) {
			throw std::out_of_range("Index out of range");
		}
		return arr[index];
	}
};

int main() {
	NumbersArray numbersArray;

	std::cout << "Accessing array elements:" << std::endl;
	std::cout << "numbersArray.getNumberAtIndex(2): " << numbersArray.getNumberAtIndex(2) << std::endl;
	system("pause");
	return 0;
}

/*
Accessing array elements:
numbersArray.getNumberAtIndex(2): 3
*/
