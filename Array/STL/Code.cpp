#include <iostream>
#include<array>
#include<string>
using namespace std;

void main() {
	array<int, 5> array1 { 3, 4, 5, 1, 2 } ;
	array<int, 5> array2 = { 1, 2, 3, 4, 5 };
	array<string, 2> array3 = { string("a"), "b" } ;

	// size( ) or max_size( ) and sizeof( ) function: Both size( ) or max_size( ) are used to get the maximum number of indexes in the array while sizeof( ) 
	// size( ) or max_size( ) and sizeof( ) function: Both size( ) or max_size( ) are used to get the maximum number of indexes in the array while sizeof( ) is 
	// used to get the total size of array in bytes.is used to get the total size of array in bytes.
	cout << "Sizes of arrays are" << endl;
	cout << array1.size() << endl;
	cout << array2.size() << endl;
	cout << array3.size() << endl;

	cout << "\nInitial array1 : ";
	for (auto i : array1)
		cout << i << ' ';

	// container operations are supported
	// constant_iterator set_name.cbegin()
	sort(array1.begin(), array1.end());

	cout << "\nsorted  array1 : ";
	for (auto i : array1)
		cout << i << ' ';

	// fill( ) function: This is specially used to initialize or fill all the indexes of the array with a similar value.
	array2.fill(10);
	cout << "\nFilled array2 : ";
	for (auto i : array2)
		cout << i << ' ';

	// ranged for loop is supported
	cout << "\narray3 : ";
	for (auto &s : array3)
		cout << s << ' ' ;

	// [ ] Operator: This is similar to the normal array, we use it to access the element store at index ‘i’ .
	array<char, 4> array4 = { 'G','H','J','K' };
	cout << "\narray4 : ";
	cout << array4[0] << " " << array4[2];

	// front( ) and back( ) function: These methods are used to access the first and the last element of the array directly.
	array<int, 3> array5 = { 'S','D','F' };
	cout << "\narray5 : ";
	cout << array5.front() << " " << array5.back();	 // ASCII val

	// swap() function: This swap function is used to swap the content of the two arrays.
	array <int, 3> array6 = { 'S','D','F' };
	array <int, 3> array7 = { 'M','M','P' }; 
	array6.swap(array7);  
	cout << "\narray6 : ";
	cout << array6.front() << " " << array6.back();
	swap(array6,array7);
	cout << "\narray6 : ";
	cout << array6.front() << " " << array6.back();

	// empty( ) function: declared STL array is empty or not, if it is empty then it returns true else false.
	array <int, 3> array8 = { 'S','D','F' };
	array <int, 3> array9 = { 'M','M','P' };
	cout << "\narray8 : ";
	bool x = array8.empty(); // false ( not empty)
	cout << boolalpha << (x);

	// at( ) function: This function is used to access the element stored at a specific location, 
	// if we try to access the element which is out of bounds of the array size then it throws an exception.
	array <int, 3> array10 = { 'S','D','F' };
	array <int, 3> array11 = { 'M','M','P' };
	cout << "\narray10 : ";
	cout << array10.at(2) << " " << array11.at(2);

	// data( ): This function returns the pointer to the first element of the array object.
	// Because elements in the array are stored in contiguous memory locations. This data( ) 
	// function return us the base address of the string/char type object.

	const char* str = "HelloWorld";
	array<char, 13> array12;
	memcpy(array12.data(), str, 13);
	cout << "\narray12 : ";
	cout << array12.data() << '\n';

}

/*
Output:
Sizes of arrays are
5
5
2

Initial array1 : 3 4 5 1 2
sorted  array1 : 1 2 3 4 5
Filled array2 : 10 10 10 10 10
array3 : a b
array4 : G J
array5 : 83 70
array6 : 77 80
array6 : 83 70
array8 : false
array10 : 70 80
array12 : HelloWorld

*/
