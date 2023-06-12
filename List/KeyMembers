#include <iostream>
#include <list>
using namespace std;

void main() {
    list<int> myList {1, 2, 3, 4, 5};
    cout << "Front: " << myList.front() << endl;
    cout << "Back: " << myList.back() << endl;
    myList.push_front(0);
    myList.push_back(6);
    cout << "Size: " << myList.size() << endl;
    cout << "Elements: ";
    for (auto it = myList.begin(); it != myList.end(); ++it) 
        cout << *it << " ";
    
    cout << endl;
    myList.pop_front();
    myList.pop_back();
    cout << "After pop operations: ";
    for (auto element : myList) {
        cout << element << " ";
    }
    cout << endl;
}

/*
Output:
Front: 1
Back: 5
Size: 7
Elements: 0 1 2 3 4 5 6
After pop operations: 1 2 3 4 5
*/

/*
front(): Returns the value of the first element in the list.
back(): Returns the value of the last element in the list.
push_front(): Adds a new element at the beginning of the list.
push_back(): Adds a new element at the end of the list.
pop_front(): Removes the first element from the list.
pop_back(): Removes the last element from the list.
insert(): Inserts new elements before the element at a specified position.
size(): Returns the number of elements in the list.
begin(): Returns an iterator pointing to the first element of the list.
end(): Returns an iterator pointing to the position after the last element of the list.
*/
