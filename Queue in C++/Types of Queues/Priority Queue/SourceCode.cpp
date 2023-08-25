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

/*
Methods	Description
empty()	This method checks whether the priority_queue container is empty or not. If it is empty, return true, else false. It does not take any parameters.
syntax  :   p1.empty()                       // p1 is priority_queue object
size()	This method gives the number of elements in the priority queue container. It returns the size in an integer. It does not take any parameter.
syntax :   p2.size()                        // p2 is priority_queue object
push()	This method inserts the element into the queue. Firstly, the element is added to the end of the queue, and simultaneously elements reorder themselves with priority. It takes value in the parameter.
syntax :  p3.push(value)            //value to be inserted
pop()	This method  delete the top element (highest priority) from the priority_queue. It does not take any parameter.
syntax :  p3.pop()           // p3 is priority_queue object
top()	This method gives the top element from the priority queue container. It does not take any parameter.
syntax :  p3.top()  
swap()	This method swaps the elements of a priority_queue with another priority_queue of the same size and type. It takes the priority queue in a parameter whose values need to be swapped.
syntax :  p3.swap(p1)   
emplace()	This method adds a new element in a container at the top of the priority queue. It takes value in a parameter.
syntax :  p3.emplace(value)   
*/

/*
Priority Queue is a container that stores elements with priority. Unlike queues, which insert or delete the element based on the FIFO rule, 
in Priority Queue, elements are removed based on priority. The element with the highest priority is the first one to be removed from the queue.

Priority queue supports three operations: is_empty to check if there is no element in the queue,insert_with_priority, to add an element with 
priority, and Pull_highest_priority_element, to fetch element of highest priority in the queue and show 
*/
