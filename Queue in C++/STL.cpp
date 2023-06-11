// Standard Template Library (STL)

#include <iostream>
#include<queue>
using namespace std;

// Print the Queue
void showq(queue<int> quef) {
	queue<int> quel = quef;
	while (!quel.empty()) {
		cout << '\t' << quel.front();
		quel.pop();
	}
	cout << '\n';
}

void main() {
	queue<int> que;
	que.push(20);
	que.push(40);
	que.push(60);

	cout << "The queue que is : ";
	showq(que);

	cout << "\n que.size() : " << que.size();
	cout << "\n que.front() : " << que.front();
	cout << "\n que.back() : " << que.back();

	cout << "\ngquiz.pop() : ";
	que.pop();
	showq(que);

	queue<int> que1;
	que1.push(120);
	que1.push(140);
	que1.push(160);
  cout << "The queue que1 is : ";
	showq(que1);

	cout << "\n The first swap que elements are : " ;
	swap(que, que1);
	showq(que);
	cout << "\n The first swap que1 elements are  : ";
	showq(que1);

	cout << "\n The second swap que elements are  : ";
	que.swap(que1);
	showq(que);
	cout << "\n The second swap que1 elements are  : ";
	showq(que1);

}

/*
The queue que is :     20    40    60

que.size() : 3
que.front() : 20
que.back() : 60
que.pop() :     40    60
The queue que1 is :     120    140    160

 The first swap que elements are :      120     140     160

 The first swap que1 elements are  :    40      60

 The second swap que elements are  :    40      60

 The second swap que1 elements are  :   120     140     160
*/

/*
The time complexity and definition of the following functions are as follows:
O(1): Constant Time
queue::empty()	O(1)
queue::size()	O(1)
queue::emplace()	O(1)
queue::front()	O(1)
queue::back()	O(1)
queue::push(g) 	O(1)
queue::pop() 	O(1)
*/

/*
Method	                    Definition
queue::empty()              Returns whether the queue is empty. It return true if the queue is empty otherwise returns false.
queue::size()	              Returns the size of the queue.
queue::swap()	              Exchange the contents of two queues but the queues must be of the same data type, although sizes may differ.
queue::emplace()	          Insert a new element into the queue container, the new element is added to the end of the queue.
queue::front()	            Returns a reference to the first element of the queue.
queue::back()	              Returns a reference to the last element of the queue.
queue::push(g) 	            Adds the element ‘g’ at the end of the queue.
queue::pop() 	              Deletes the first element of the queue.
*/
