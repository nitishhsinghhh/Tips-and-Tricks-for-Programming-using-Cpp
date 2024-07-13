#include <iostream>
#include <vector>

using namespace std;

class Sorter {
public:
	void bubbleSort(vector<int>& numbers) {
		int endIndex, currentIndex, size = numbers.size();
		if (size <= 1) return;
		for (endIndex = size - 1; endIndex; endIndex--)
			for (currentIndex = 0; currentIndex < endIndex; currentIndex++)
				if (numbers[currentIndex] > numbers[currentIndex + 1])
					swap(numbers[currentIndex], numbers[currentIndex + 1]);
	}

	void print(vector<int> numbers) {
		for (int i = 0; i < numbers.size(); i++) 
			cout << numbers[i] << " ";
		cout << endl;
	}
};

int main() {
	Sorter sorter;
	vector<int> numbers = { 5, 2, 9, 3, 1, 6 };
	cout << "Unsorted array: ";
	sorter.print(numbers);
	sorter.bubbleSort(numbers);
	cout << "Sorted array: ";
	sorter.print(numbers);
	return 0;
}

/*
Output:
Unsorted array: 5 2 9 3 1 6
Sorted array: 1 2 3 5 6 9
*/
