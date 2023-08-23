#include <iostream>
#include <queue>

using namespace std;

int main() {
 // Creating a priority queue of integers
 priority_queue<int> pq;

 // Adding elements to the priority queue
 pq.push(5);
 pq.push(2);
 pq.push(10);
 pq.push(1);

 // Displaying the priority queue
 cout << "Priority Queue: ";
 while (!pq.empty()) {
  cout << pq.top() << " ";
  pq.pop();
 }
 cout << endl;

 return 0;
}

// Output: Priority Queue: 10 5 2 1
