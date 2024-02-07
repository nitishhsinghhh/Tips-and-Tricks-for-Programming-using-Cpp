# Concurrent Programming: [Gotchas](https://www.linkedin.com/in/dennis-kennetz/)

Concurrent programming "gotchas" all revolve around shared resource contention, and fall into the following categories:

- Race conditions - A timing issue - multiple threads access shared resource "out of turn" resulting in inconsistent, unexpected, or corrupt data. Note, race conditions are not an incorrect result - each thread performed its instructions in a valid manner related to the shared variable.

- Resource starvation - Some threads are unable to make progress because other threads are hogging the resource, ultimately degrading the performance of the program.

- Deadlocks - Cyclic dependency where each thread holds resources that another thread needs to proceed, ultimately resulting in none of the threads making progress.

- Livelocks - Threads are trying to resolve conflict but are "too polite" and continually yielding resources to each other, often resulting in infinite loops or buffer overflows.

- Suboptimal resource utilization - too many threads with too little to do, or too few threads with too much to do, which ends up being expensive in both directions.

Now for my example - 4 roommates at Costco grocery shopping (because I love Costco).

In this example, Costco (the grocery store) is the shared resource, and each roommate is responsible for securing only a few items for the week to take home to eat. Each roommate arrives together, grabs a shopping cart, and sprints into the store.

**Race condition:** 
Roommates don't coordinate beforehand on what to buy for the week, and they all just grab whatever they want, leading to inconsistent meals and an imbalanced diet for the week. Resolution - make a shopping list beforehand.

**Resource starvation:**
One roommate took all the cash, so when the others go to check out, they don't have the resources to do so until the roommate comes and gives them the money.

**Deadlock:**
3 roommates accidentally left the 4th roommate at home, but the 4th roommate had the Costco card - but they only had one car.

**Livelock:**
After they checked out, two mates wanted some Costco pizza. When they went to buy some, the employee said there was only one slice left. They were both incredibly polite, and refused to take the last slice, repeating, "No, I insist - you take it."

**Suboptimal Resource utilization:**
They realized they really only needed 2 roommates to grocery shop instead of 4. The other 2 could've been home cleaning the house.

Just so we do look at some code, here's a simple example of a race condition and a safe(r) example in C++ via interleaved execution.

```cpp[]
#include<iostream>
#include<mutex>
#include<thread>
#include<vector>

std::mutex CountingMutex;

void unsafeIncrementCounter(int & counter) {
	for (int i = 0; i < 100000; ++i) {
		counter++;
	}
}

void safeIncremntCounter(int& counter) {
	std::lock_guard<std::mutex> lock(CountingMutex);
	for (int i = 0; i < 100000; ++i) {
		counter++;
	}
}

int main() { 
	int unsafeCounter = 0;
	int safeCounter = 0;
	std::vector<std::thread> threads;
	for (int i = 0; i < 5; i++) {
		threads.push_back(std::thread(unsafeIncrementCounter, std::ref(unsafeCounter)));
		threads.push_back(std::thread(safeIncremntCounter, std::ref(safeCounter)));
	}

	for (auto& thread : threads) {
		thread.join();
	}
	std::cout << "final unsfae counter value: " << unsafeCounter << std::endl;
	std::cout << "final safe counter value: " << safeCounter << std::endl;
	
	return 0;
}
```
