// To create a stack in C++, it is necessary to include the <stack> header file in the code.

#include <iostream>
#include<stack>

int main() {
	std::stack<int> stack;
	stack.push(1);
	stack.push(2);
	stack.push(4);
	stack.push(7);

	int num = 0;
	stack.push(num);

	int size = stack.size();
	std::cout << "Size of stack is: " << size << std::endl;

	stack.pop();
	stack.pop();
	stack.pop();

	while (!stack.empty()) {
		std::cout << stack.top() << " ";
		stack.pop();
	}

	return 0;
}
