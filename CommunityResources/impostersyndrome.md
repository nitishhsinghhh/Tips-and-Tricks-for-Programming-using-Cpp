# Demystifying Dynamic Programming
![image](https://github.com/nitishhsinghhh/Tips-and-Tricks-for-Programming-using-Cpp/assets/93253740/c205a954-54e2-4029-85f0-69a4a1cda8c7)

## Dynamic Programming Defined
Dynamic programming amounts to breaking down an optimization problem into simpler sub-problems, and storing the solution to each sub-problem so that each sub-problem is only solved once.

To be honest, this definition may not make total sense until you see an example of a sub-problem. That’s okay, it’s coming up in the next section.

What I hope to convey is that DP is a useful technique for optimization problems, those problems that seek the maximum or minimum solution given certain constraints, because it looks through all possible sub-problems and never recomputes the solution to any sub-problem. This guarantees correctness and efficiency, which we cannot say of most techniques used to solve or approximate algorithms. This alone makes DP special.

In the next two sections, I’ll explain what a sub-problem is, and then motivate why storing solutions — a technique known as memoization — matters in dynamic programming.

## Sub-problems on Sub-problems on Sub-problems
Sub-problems are smaller versions of the original problem. In fact, sub-problems often look like a reworded version of the original problem. If formulated correctly, sub-problems build on each other in order to obtain the solution to the original problem.

To give you a better idea of how this works, let’s find the sub-problem in an example dynamic programming problem.

Pretend you’re back in the 1950s working on an IBM-650 computer. You know what this means — punchcards! Your job is to man, or woman, the IBM-650 for a day. You’re given a natural number n punchcards to run. Each punchcard i must be run at some predetermined start time s_i and stop running at some predetermined finish time f_i. Only one punchcard can run on the IBM-650 at once. Each punchcard also has an associated value v_i based on how important it is to your company.


**Problem:** As the person in charge of the IBM-650, you must determine the optimal schedule of punchcards that maximizes the total value of all punchcards run.

Because I’ll go through this example in great detail throughout this article, I’ll only tease you with its sub-problem for now:

**Sub-problem:** The maximum value schedule for punchcards i through n such that the punchcards are sorted by start time.

Notice how the sub-problem breaks down the original problem into components that build up the solution. With the sub-problem, you can find the maximum value schedule for punchcards n-1 through n, and then for punchcards n-2 through n, and so on. By finding the solutions for every single sub-problem, you can then tackle the original problem itself: the maximum value schedule for punchcards 1 through n. Since the sub-problem looks like the original problem, sub-problems can be used to solve the original problem.

In dynamic programming, after you solve each sub-problem, you must memoize, or store it. Let’s find out why in the following section.


## Motivating Memoization with Fibonacci Numbers

When told to implement an algorithm that calculates the Fibonacci value for any given number, what would you do? Most people I know would opt for a recursive algorithm that looks something like this in C++:
```cpp
	int fibonacciVal(int n) {
		if (n == 0)
			return 0;
		else if (n == 1)
			return 1;
		else
			return fibonacciVal(n - 1) + fibonacciVal(n - 2);
	}
```

This algorithm accomplishes its purpose, but at a huge cost. For example, let’s look at what this algorithm must calculate in order to solve for n = 5 (abbreviated as F(5)):

```
F(5)                      /      \                                     /        \                  /          \               F(4)          F(3)            /       \        /   \          F(3)     F(2)     F(2)  F(1)         /   \     /  \     /   \       F(2) F(1) F(1) F(0) F(1) F(0)       /  \     F(1) F(0)
```


