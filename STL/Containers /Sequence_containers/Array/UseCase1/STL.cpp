#include <iostream>
#include<array>
#include<string>

void main() {
	std::array<int, 5> array1{ 3, 4, 5, 1, 2 };
	std::array<int, 5> array2 = { 1, 2, 3, 4, 5 };
	std::array<std::string, 2> array3 = { std::string("a"), "b" };

	// size( ) or max_size( ) and sizeof( ) function: Both size( ) or max_size( ) are used to get the maximum number of indexes in the std::array while sizeof( ) 
	// size( ) or max_size( ) and sizeof( ) function: Both size( ) or max_size( ) are used to get the maximum number of indexes in the std::array while sizeof( ) is 
	// used to get the total size of std::array in bytes.is used to get the total size of std::array in bytes.
	std::cout << "Sizes of std::arrays are" << std::endl;
	std::cout << array1.size() << std::endl;
	std::cout << array2.size() << std::endl;
	std::cout << array3.size() << std::endl;

	std::cout << "\nInitial array1 : ";
	for (auto i : array1)
		std::cout << i << ' ';

	// container operations are supported
	// constant_iterator set_name.cbegin()
	sort(array1.begin(), array1.end());

	std::cout << "\nsorted  array1 : ";
	for (auto i : array1)
		std::cout << i << ' ';

	// fill( ) function: This is specially used to initialize or fill all the indexes of the std::array with a similar value.
	array2.fill(10);
	std::cout << "\nFilled array2 : ";
	for (auto i : array2)
		std::cout << i << ' ';

	// ranged for loop is supported
	std::cout << "\narray3 : ";
	for (auto &s : array3)
		std::cout << s << ' ';

	// [ ] Operator: This is similar to the normal std::array, we use it to access the element store at index ‘i’ .
	std::array<char, 4> array4 = { 'G','H','J','K' };
	std::cout << "\narray4 : ";
	std::cout << array4[0] << " " << array4[2];

	// front( ) and back( ) function: These methods are used to access the first and the last element of the std::array directly.
	std::array<int, 3> array5 = { 'S','D','F' };
	std::cout << "\narray5 : ";
	std::cout << array5.front() << " " << array5.back();	 // ASCII val

	// swap() function: This swap function is used to swap the content of the two std::arrays.
	std::array <int, 3> array6 = { 'S','D','F' };
	std::array <int, 3> array7 = { 'M','M','P' };
	array6.swap(array7);
	std::cout << "\narray6 : ";
	std::cout << array6.front() << " " << array6.back();
	swap(array6, array7);
	std::cout << "\narray6 : ";
	std::cout << array6.front() << " " << array6.back();

	// empty( ) function: declared STL std::array is empty or not, if it is empty then it returns true else false.
	std::array <int, 3> array8 = { 'S','D','F' };
	std::array <int, 3> array9 = { 'M','M','P' };
	std::cout << "\narray8 : ";
	bool x = array8.empty(); // false ( not empty)
	std::cout << "array8 : " << (x);

	// at( ) function: This function is used to access the element stored at a specific location, 
	// if we try to access the element which is out of bounds of the std::array size then it throws an exception.
	std::array <int, 3> array10 = { 'S','D','F' };
	std::array <int, 3> array11 = { 'M','M','P' };
	std::cout << "\narray10 : ";
	std::cout << array10.at(2) << " " << array11.at(2);

	// data( ): This function returns the pointer to the first element of the std::array object.
	// Because elements in the std::array are stored in contiguous memory locations. This data( ) 
	// function return us the base address of the std::string/char type object.

	const char* str = "HelloWorld";
	std::array<char, 13> array12;
	memcpy(array12.data(), str, 13);
	std::cout << "\narray12 : ";
	std::cout << array12.data() << '\n';

}

/*
Output:
Sizes of std::arrays are
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
