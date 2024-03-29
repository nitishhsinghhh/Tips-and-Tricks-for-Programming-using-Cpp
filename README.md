# Tips and Tricks for Programming using Cpp

Welcome to the GitHub repository! Here, you will find all the code and resources related to my [**Medium**](https://nitishhsinghhh.medium.com/) articles on practical tips for developers using **C++**. As a passionate advocate for empowering developers with up-to-date knowledge, I have created this repository to share my insights and expertise with the tech community.

With a focus on practical solutions and real-world examples, my articles cover a wide range of topics related to **C++ programming**. From mastering the basics to tackling more advanced concepts, I provide tips and guidance to help developers of all skill levels achieve their goals.

So, whether you're a seasoned developer or just starting out, this repository is the perfect place to find valuable resources and insights. Together, let's build a stronger, more empowered tech community!

## How to Use
To use these programs, you will need to have a C++ compiler installed on your computer. You can then download the program files from this repository and compile them using the compiler.

C++ is a compiled language. That means that to get a program to run, you must first translate it from the human-readable form to something a machine can “understand.” That translation is done by a program called a compiler.

Typically C++ source code files are given the suffix:
1. .cpp (ex: firstCode.cpp) or
2. .h (ex: std_lib_facilities.h).

![image](https://github.com/nitishhsinghhh/Tips-and-Tricks-for-Programming-using-Cpp/assets/93253740/900ac352-6779-48de-9644-a069b0f0fef9)

- Compile:
g++ firstCode.cpp -o firstCode <br>
A compiler translates the C++ program into machine language code which it stores on the disk as a file with the extension .o (e.g. firstCode.o). A linker then links the object code with standard library routines that the program may use and creates an executable image which is also saved on disk, usually as a file with the file name without any extension (e.g. firstCode).

- Execute:
./firstCode <br>
The executable is loaded from the disk to memory and the computer’s CPU (Central Processing Unit) executes the program one instruction at a time.
Alternatively, you can also use an online C++ compiler to run these programs without needing to install a compiler on your computer.

## Getting Started
To compile and run these programs on your local machine, you'll need to have the appropriate programming language and compiler installed. Here are the steps to get started:

1. Clone this repository to your local machine using git clone.
2. Navigate to the folder containing the program you want to run.
3. Follow the instructions in the program's README file to compile and run the program.

## Contributions
If you have any suggestions for improvements or would like to add additional C++ programs to this repository, please feel free to create a pull request. We welcome contributions from the community to make this repository more useful for everyone.

Contributions to this repository are welcome! If you'd like to contribute, please follow these guidelines:

1. Fork this repository to your own GitHub account.
2. Create a new branch for your changes using git checkout -b my-feature-branch
3. Make your changes and commit them with a descriptive commit message.
4. Push your changes to your forked repository with git push origin my-feature-branch
5. Submit a pull request to this repository with a detailed description of your changes.


## To fork this repository, follow these steps:

1. Navigate to the repository on GitHub.
2. Click on the "Fork" button in the top-right corner of the page.
3. Select the account or organization where you want to fork the repository.
4. Wait for the forking process to complete.

## Contents:
- Tips
- Computer Science Basics
- Learning Resources
- Problem Solving
- Projects Ideas

## Table of Contents: 

|#| Title with Medium Article Link   | Solution | Comment |
|---| ------------------------------------------------------------ | -------- | ------------------------------------------------------ |
|1|[**Converting Character to Integer**](https://nitishhsinghhh.medium.com/how-to-manipulate-ascii-value-of-letters-37cbffd2a832) | [**C++**](./ASCII/performingASCIIcalculations.cpp) | This program demonstrates how to convert characters to integers and calculate their sum.|
|2|[**Input Validation**](https://nitishhsinghhh.medium.com/how-to-manipulate-ascii-value-of-letters-37cbffd2a832) | [**C++**](./ASCII/InputValidation.cpp) | This program prompts the user to input a number between 1 and 10, converts the input character to an integer, and checks if it is within the valid range. It then outputs a message indicating whether the input is valid or not.|
|3|[**Sorting Comparison Operations**](https://nitishhsinghhh.medium.com/how-to-manipulate-ascii-value-of-letters-37cbffd2a832) | [**C++**](./ASCII/sortingComparisonOperations.cpp) | The code sorts and converts two given strings to integers, then determines and outputs the smallest and largest numbers. It follows the Single Responsibility Principle by separating responsibilities into two classes: StringConverter and InputHandler. |
|4| [**Simple Array**](https://nitishhsinghhh.medium.com/linked-lists-vs-arrays-whats-the-difference-f2a71b9fbd8) | [**C++**](./Array/SimpleArray.cpp) | This program demonstrates how to declare and initialize arrays in C++, and how to access their elements using the subscript operator. |'
|5| [**Singly Linked List**](https://nitishhsinghhh.medium.com/linked-lists-vs-arrays-whats-the-difference-f2a71b9fbd8) | [**C++**](./List/SinglyLinkedList/Code.cpp) | This program demonstrates how to create and traverse a singly linked list using the Node struct, which contains an integer data value and a pointer to the next node in the list. |
|6| [**Doubly Linked List**](https://nitishhsinghhh.medium.com/linked-lists-vs-arrays-whats-the-difference-f2a71b9fbd8) | [**C++**](./List/DoublyLinkedList/doubly-linked-list.cpp) | This program demonstrates how to create and traverse a doubly linked list using the Node struct, which contains an integer data value and a pointer to the previous & next node in the list. |
|7| [**Efficient Square Root**](https://nitishhsinghhh.medium.com/efficient-square-root-calculation-using-binary-search-in-c-106d30538aff) | [**C++**](./lgorithms/EfficientSquareRoot.cpp) | The program uses binary search to find the square root of a given number and returns the largest integer whose square is less than or equal to the given number. |
|8| [**1318. Minimum Flips to Make a OR b Equal to c**](https://nitishhsinghhh.medium.com/understanding-least-significant-bits-and-bit-flips-in-c-b6618f072b08) | [**C++**](./Leetcode/1318/Minimum%20Flips%20to%20Make%20a%20OR%20b%20Equal%20to%20c.cpp) |This is a C++ program that calculates the number of flips required to make all bits of three given integers either 0 or 1. |
|9| [**Passing by Reference and Value**](https://nitishhsinghhh.medium.com/passing-by-reference-and-value-in-c-ea54ceba3b24) | [**C++**](./PassBYValueReference/modifyValues.cpp) |This is a C++ program that demonstrates the difference between passing a variable by value and by reference. |
|10| [**Lexicographic Order**](https://nitishhsinghhh.medium.com/understanding-lexicographic-order-in-programming-with-c-6d283dce5233) | [**C++**](./Lexicographic%20Order/sortingsearchinggeneratingpermutations.cpp) | This C++ program demonstrates the usage of lexicographic order by comparing strings and sorting a vector of strings. It also shows how to generate permutations of a vector of integers using the next_permutation function. |
|11| [**Function Overloading**](https://nitishhsinghhh.medium.com/function-overloading-in-c-enhancing-code-readability-and-reusability-d3e32081ea25) | [**C++**](./Function%20Overloading%20/calculateArea.cpp) | This C++ program demonstrates function overloading by defining two functions with the same name calculateArea but different parameter lists to calculate the area of a square and a rectangle. |
|12| [**Virtual Functions**](https://nitishhsinghhh.medium.com/understanding-virtual-functions-in-c-differences-and-use-cases-768a8145a7d5) | [**C++**](./Virtual%20Functions/Shape.cpp) | This C++ program demonstrates the use of virtual functions to achieve polymorphism in a Shape hierarchy, allowing for different shapes to be drawn using the same function call. |
|13| [**Types of Inheritance**](https://nitishhsinghhh.medium.com/understanding-inheritance-in-c-concepts-and-example-317208721d37) | [**C++**](./OOP/typesofinheritance.cpp) | This **C++** program demonstrates the implementation of polymorphism using virtual functions to calculate the area of a Circle and a Rectangle. |
|14| [**Abstract Classes and Interfaces**](https://nitishhsinghhh.medium.com/understanding-the-difference-between-abstract-classes-and-interfaces-in-c-7cc8f2bba667) | [**C++**](./OOP/typesofinheritance.cpp) | This is a C++ program that demonstrates the use of abstract classes and interfaces with a Cat class that inherits from the Animal abstract class and implements the Drawable interface. |
|15| [**Stack and Heap Memory**](https://nitishhsinghhh.medium.com/understanding-the-differences-between-stack-and-heap-memory-in-c-9e01c0d3029e) | [**C++**](./Memory%20Allocation/Stack%20vs%20Heap%20Memory.cpp) | This is a C++ program that demonstrates the use of stack and heap memory with functions that allocate variables on the stack and an array on the heap, perform operations on them, and deallocate the heap memory. |
|16| [**Exception Handling**](https://nitishhsinghhh.medium.com/exception-handling-in-c-handling-errors-with-grace-2697e031d607) | [**C++**](./Misc/Exception%20handling.cpp) | This is a C++ program that demonstrates exception handling, throwing a runtime_error with a custom message when dividing by zero, and catching the exception in the main function using a try-catch block. |
|17| [**Private, Protected, and Public Inheritance**](https://medium.com/dev-genius/c-public-protected-and-private-inheritance-d3e2de457687) | [**C++**](./OOP/PPPInheritance.cpp) | This is a C++ program that demonstrates access control in inheritance, with a Base class that has public, protected, and private methods, and derived classes that inherit from it using private, protected, and public inheritance, respectively. The program tests the accessibility of the Base class methods from the derived classes and shows the output of the accessible methods. |
|18| [**Scope Resolution Operator**](https://nitishhsinghhh.medium.com/understanding-the-scope-resolution-operator-in-c-65e71784a5b8) | [**C++**](./Misc/Scope%20Resolution%20Operator.cpp) | The program demonstrates how to use global variables, namespaces, and classes with member and static variables and functions, and it uses the scope resolution operator to specify the scope of the variables and functions. |
|19| [**Sequence container: Array**](https://nitishhsinghhh.medium.com/exploring-container-classes-in-c-stl-a-comprehensive-overview-f7491bea84c0) | [**C++**](./Array/STL.cpp) | The program demonstrates the use of STL arrays and various array operations, such as sorting, filling, and swapping, as well as accessing array elements, using C++ STL array functions. |
|20| [**Sequence container: Vector**](https://nitishhsinghhh.medium.com/exploring-the-versatile-vector-container-in-c-81a3b2bb8d9b) | [**C++**](./Vector) | The program demonstrates the use of STL vector and various operations, such as sorting, filling, and swapping, as well as accessing array elements, using C++ STL functions. |
|21| [**Sequence container: List**](https://nitishhsinghhh.medium.com/exploring-the-list-container-in-c-stl-a-versatile-doubly-linked-list-65f50d4e97d6) | [**C++**](./List/KeyMembers.cpp) | This program demonstrates the use of the STL list container in C++, including basic operations such as inserting, deleting, and retrieving elements at the front and back of the list. |
|22| [**Sequence container: Forward List**](https://nitishhsinghhh.medium.com/introduction-to-forward-list-in-c-stl-and-important-functions-217fd4d0af59) | [**C++**](./Forward%20List) | This program highlights the features and benefits of the forward list container class in the C++ STL, including its efficient insertion, removal, and sorting operations, as well as its suitability for forward traversal scenarios such as hashing and graph representation. |
|23| [**Sequence container: Deque**](https://nitishhsinghhh.medium.com/exploring-double-ended-queues-deque-in-c-standard-template-library-stl-c2e97fae6b4b) | [**C++**]() | This article introduces the deque container class in the C++ STL, highlighting its features as a double-ended queue that combines the functionality of both stacks and queues, and discussing its advantages and common methods. |
|24| [**Determine if String Halves Are Alike**](https://nitishhsinghhh.medium.com/demystifying-the-bitwise-complement-operator-in-c-bde3f3f178cc) | [**C++**](./Leetcode/1704%20/Determine%20if%20String%20Halves%20Are%20Alike.cpp) | The program defines a function halvesAreAlike that takes a input and checks if the first half and second half of the input have the same number of vowels. |
|25| [**Comparing Version Numbers**](https://nitishhsinghhh.medium.com/comparing-version-numbers-in-c-using-string-parsing-bcfd292bcd87) | [**C++**](./Leetcode/165/Compare%20Version%20Numbers.cpp) | This program implements a solution to compare two version numbers represented as strings using the C++ language, by parsing the strings and comparing each component of the version number. |
|26|[**Insertion Sort Algorithm**](https://blog.devgenius.io/insertion-sort-algorithm-using-std-array-in-c-4fc66efb27af) | [**C++**](./sort/insertionSort/sortWithoutTem.cpp) |This program implements the insertion sort algorithm in C++ to sort an array of integers and outputs the sorted array. |
|27|[**Deleting the Middle Element of a Double Linked List**](https://nitishhsinghhh.medium.com/finding-the-middle-element-of-a-double-linked-list-in-c-57d74ece512) | [**C++**](./List/Middle%20Element%20of%20a%20Double%20Linked%20List/STL.cpp) |This program implements a solution to delete an element at a specified position in a list container using the **C++** language, and tests the function with different test cases. |
|28|[**Advance Function**](https://nitishhsinghhh.medium.com/implementing-the-advance-function-in-c-a-comprehensive-guide-bd97089e8a93) | [**C++**](./Iterators%20/advance%20Function/advance.cpp) |This program demonstrates the use of iterators in C++ to traverse and manipulate elements in a container such as a list, and provides an implementation of the advance function for different iterator categories. |
|29|[**Trichotomous comparison**](https://nitishhsinghhh.medium.com/exploring-three-way-comparison-in-computer-science-a32c69de33c5) | [**C++**](./Misc/trichotomous%20comparison/spaceship%20operator.cpp) |This article discusses the significance of trichotomous comparison, also known as three-way comparison, in computer science, including its applications in machine-level computation and its implementation in high-level programming languages. |
|30|[**Implementing a Stack**](https://blog.devgenius.io/implementing-a-stack-using-a-vector-in-c-b5f4be6a719a) | [**C++**](./stack/implementation/usingTemplate.cpp) |This program implements a generic stack data structure using templates in C++, and demonstrates its usage with different data types, including integers, strings, and doubles. |
|31|[**Implementing a Queue**](https://blog.devgenius.io/implementing-a-queue-using-vector-template-in-c-558c83633f93) | [**C++**](./Queue/Implementation/vectorTemplate.cpp) |This program implements a generic queue data structure using templates in C++, and demonstrates its usage with integers. |
|32|[**URL Shortener**](https://blog.devgenius.io/designing-a-link-shortener-in-c-9a626c172a85) | [**C++**](./LinkShortener/implementation.cpp) |This program implements a link shortener using a hash map to map original links to shortened links with randomly generated codes, and provides functionality to retrieve the original link from the shortened link. |
|33|[**Implementation of Vector Container**](https://blog.devgenius.io/implementing-a-vector-container-data-structure-in-c-using-templates-79b247784fc8) | [**C++**](./Array/implementation/template.cpp/) | This program implements a vector class template in C++ with dynamic resizing and indexing functionality, and demonstrates its usage with integers. |
|34|[**Stack-based Calculator**](https://blog.devgenius.io/building-a-simple-stack-based-calculator-in-c-cd5666ae6515) | [**C++**](./stack/implementation/Stack-based%20Calculator/Code.cpp) |This program implements a postfix expression calculator using a stack data structure in C++, which evaluates postfix expressions with operators +, -, *, and /, and outputs the result. |
|35|[**Stack Data Structure using Queue**](https://nitishhsinghhh.medium.com/efficiently-implementing-a-stack-data-structure-using-queue-in-c-fd3ede8cd949) | [**C++**](./stack/implementation/Usingqueue.cpp) | This C++ program implements a stack data structure using two queues and performs push, pop, top, empty, and size operations. It then tests the implementation by pushing three elements, printing the top element, popping the top element, printing the new top element, and printing the size of the stack. |
|36|[**Stack Data Structure using Linked List**](https://nitishhsinghhh.medium.com/efficiently-implementing-a-stack-data-structure-using-queue-in-c-fd3ede8cd949) | [**C++**](./stack/implementation/UsingSinglyLinkedList.cpp) | This code demonstrates the implementation of a stack data structure using linked lists in C++. It includes essential stack operations such as push, pop, top, isEmpty, and size. The code uses a singly linked list. |
|37| [**Implement a HashSet Data Structure**](https://nitishhsinghhh.medium.com/how-to-implement-a-hashset-data-structure-in-c-using-a-hash-table-approach-9581e51da8df) | [**C++**](./hashset/implementation.cpp) | This is a C++ code that implements a Hash Set using templates and a list. It includes functions for inserting, removing, and checking if the set contains a specific element. |
|38| [**Designing a HashMap without Built-in Libraries**](https://nitishhsinghhh.medium.com/designing-a-hashmap-without-built-in-libraries-00ee553106bf) | [**C++**](./Hashmap/Implementation/code.cpp) | This is a C++ code that implements a hash map using a linked list. It includes functions for putting a key-value pair, getting the value associated with a given key, and removing a key-value pair. |
|39| [**Sorting: STL; Standard**](https://nitishhsinghhh.medium.com/what-is-sorting-in-c-bubble-sort-insertion-sort-more-2660732c0809) | [**C++**](./sort) | This code implements a function to sort a given vector of integers in either ascending or descending order using the STL sort function in C++. |
|40| [**Sorting: STL; stable_sort**](https://nitishhsinghhh.medium.com/what-is-sorting-in-c-bubble-sort-insertion-sort-more-2660732c0809) | [**C++**](./sort) | This code implements a function to sort a given vector of integers in either ascending or descending order using the STL stable_sort function in C++. |
|41| [**Sorting: Bubble Sort**](https://nitishhsinghhh.medium.com/what-is-sorting-in-c-bubble-sort-insertion-sort-more-2660732c0809) | [**C++**](./sort) | This code implements a function to sort a given vector of integers in ascending order using the Bubble Sort algorithm. |
|42| [**Factory method for designing pattern — Search Algorithm**](https://medium.com/p/e2df5f6d1e92) | [**C++**](./DesignPattern/CreationalDesignPattern/FactoryMethod/SearchAlgorithm.cpp) | This code implements the factory design pattern for search algorithms, allowing for easy addition of new search methods in the future. |
|43| [**Factory method for designing pattern — Search Algorithm + Interpolation Search**](https://medium.com/p/e2df5f6d1e92) | [**C++**](./DesignPattern/CreationalDesignPattern/FactoryMethod/SearchAlgorithm1.cpp) | This code implements the factory design pattern for search algorithms, allowing for easy addition of new search methods in the future. Apart from linear and binary, it includes interpolation search, as well as a factory class to create the desired search algorithm. |
|44| [**Factory Design Pattern — String Conversion**](https://nitishhsinghhh.medium.com/factory-design-pattern-a-flexible-approach-to-object-creation-757f89da6def) | [**C++**](./DesignPattern/CreationalDesignPattern/FactoryMethod/StringConversion.cpp) | This code implements a factory design pattern for string conversions. It includes five derived classes for converting strings to lowercase, uppercase, sentence case, capitalized case, and toggle case. |
|45| [**Parse a string in C++**](https://medium.com/p/179688b061f4) | [**C++**](./OOP/SOLID/SRP/stringParsing.cpp) | The ArrayListManager class splits a string into substrings using a delimiter and returns a vector of strings, or an empty vector if the input string is empty. |

## Please help by giving a star

⭐ Please give this repository a star. It takes seconds and help thousands of developers! ⭐

Once you have forked the repository, you will have your own copy of the code and resources to work with. You can make changes to the code, add new resources, and submit pull requests to contribute your changes back to the original repository.

![image](https://github.com/nitishhsinghhh/Tips-and-Tricks-Programming-using-Cpp/assets/93253740/8ea8a38f-c347-4dcd-8d18-0246e4da2c31)

## Contact
Thank you for your suggestions! If you think there is anything to improve, please contact me at **me.singhnitish@yandex.com.**

