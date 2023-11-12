#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class ArrayListManager {
public:
	vector<string> AddString(string inputString, char delimiter) {
		vector<string> list;
		if (inputString.empty()) {
			return list;
		}
		if (inputString.find(delimiter) != string::npos) {
			stringstream ss(inputString);
			string value;
			while (getline(ss, value, delimiter)) 
				list.push_back(value);
		}
		else 
			list.push_back(inputString);
		
		return list;
	}
};

void main() {
	ArrayListManager manager;

	// Test Case 1: input = "apple,banana,cherry",  delimiter = ','
	vector<string> list1 = manager.AddString("apple,banana,cherry", ',');
	cout << "List 1:" << endl;
	for (int i = 0; i < list1.size(); i++) 
		cout << list1[i] << endl;
	cout << endl;

	// Test Case 2: input = "red|green|blue",  delimiter = '|'
	vector<string> list2 = manager.AddString("red|green|blue", '|');
	cout << "List 2:" << endl;
	for (int i = 0; i < list2.size(); i++) 
		cout << list2[i] << endl;
	cout << endl;

	// Test Case 3: input = "1;2;3;4",  delimiter = ';'
	vector<string> list3 = manager.AddString("1;2;3;4", ';');
	cout << "List 3:" << endl;
	for (int i = 0; i < list3.size(); i++) 
		cout << list3[i] << endl;
	cout << endl;

	// Test Case 4: input = Hello, world!",  delimiter = ' '
	vector<string> list4 = manager.AddString("Hello, world!", ' ');
	cout << "List 4:" << endl;
	for (int i = 0; i < list4.size(); i++) 
		cout << list4[i] << endl;
	cout << endl;

	// Test Case 5: input = "",  delimiter = ','
	vector<string> list5 = manager.AddString("", ',');
	cout << "List 5:" << endl;
	for (int i = 0; i < list5.size(); i++) 
		cout << list5[i] << endl;
	cout << endl;

	// Test Case 6: input = "1-2-3-4-5",  delimiter = '-'
	vector<string> list6 = manager.AddString("1-2-3-4-5", '-');
	cout << "List 6:" << endl;
	for (int i = 0; i < list6.size(); i++) 
		cout << list6[i] << endl;
	cout << endl;

	// Test Case 7: input = "car;bus;train;plane",  delimiter = ','
	vector<string> list7 = manager.AddString("car;bus;train;plane", ';');
	cout << "List 7:" << endl;
	for (int i = 0; i < list7.size(); i++) 
		cout << list7[i] << endl;
	cout << endl;

	// Test Case 8: input = "1",  delimiter = ','
	vector<string> list8 = manager.AddString("1", ',');
	cout << "List 8:" << endl;
	for (int i = 0; i < list8.size(); i++) 
		cout << list8[i] << endl;
	cout << endl;

	// Test Case 9: input = "1,2,3,4,5,6,7,8,9,10",  delimiter = ','
	vector<string> list9 = manager.AddString("1,2,3,4,5,6,7,8,9,10", ',');
	cout << "List 9:" << endl;
	for (int i = 0; i < list9.size(); i++) 
		cout << list9[i] << endl;
	cout << endl;

	// Test Case 10: input = "cat,dog,bird",  delimiter = ' '
	vector<string> list10 = manager.AddString("cat,dog,bird", ' ');
	cout << "List 10:" << endl;
	for (int i = 0; i < list10.size(); i++) 
		cout << list10[i] << endl;
	cout << endl;

	system("pause");
}

/*
Output:
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
*/
