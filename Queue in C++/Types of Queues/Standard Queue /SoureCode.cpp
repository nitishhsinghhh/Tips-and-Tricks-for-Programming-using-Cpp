#include <iostream>
#include <queue>
#include<string>

using namespace std;

void main() {
 // Creating an empty queue of string
 queue<string> q;

 // Adding elements to the queue
 q.push("hello");
 q.push("world");
 q.push("!");

 // Displaying the queue
 cout << "Queue: ";
 while (!q.empty()) {
  cout << q.front() << " ";
  q.pop();
 }
 cout << endl;
}

// Output: Queue: hello world !
