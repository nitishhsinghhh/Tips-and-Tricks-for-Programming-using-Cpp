#include <iostream>
#include <deque>

using namespace std;

int main() {
 // Creating a deque of integers
 deque<int> dq;

 // Adding elements to the front and back of the deque
 dq.push_front(1);
 dq.push_back(2);
 dq.push_front(3);
 dq.push_back(4);

 // Displaying the deque
 cout << "Deque: ";
 for (auto it = dq.begin(); it != dq.end(); ++it) {
  cout << *it << " ";
 }
 cout << endl;

 // Removing elements from the front and back of the deque
 dq.pop_front();
 dq.pop_back();

 // Displaying the updated deque
 cout << "Updated Deque: ";
 for (auto it = dq.begin(); it != dq.end(); ++it) {
  cout << *it << " ";
 }
 cout << endl;

 return 0;
}

/*
Output:
Deque: 3 1 2 4
Updated Deque: 1 2
*/
