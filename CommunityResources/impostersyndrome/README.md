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
The tree above represents each computation that must be made in order to find the Fibonacci value for n = 5. Notice how the sub-problem for n = 2 is solved thrice. For a relatively small example (n = 5), that’s a lot of repeated , and wasted, computation!

What if, instead of calculating the Fibonacci value for n = 2 three times, we created an algorithm that calculates it once, stores its value, and accesses the stored Fibonacci value for every subsequent occurrence of n = 2? That’s exactly what memoization does.

With this in mind, I’ve written a dynamic programming solution to the Fibonacci value problem:

```cpp
int fibonacciVal(int n) {
	vector<int> memo(n + 1, 0);
	memo[0] = 0;
	memo[1] = 1;
	for (int i = 2; i <= n; i++) 
		memo[i] = memo[i - 1] + memo[i - 2];
	return memo[n];
}
```

Notice how the solution of the return value comes from the memoization array memo[ ], which is iteratively filled in by the for loop. By “iteratively,” I mean that memo[2] is calculated and stored before memo[3], memo[4], …, and memo[n]. Because memo[ ] is filled in this order, the solution for each sub-problem (n = 3) can be solved by the solutions to its preceding sub-problems (n = 2 and n = 1) because these values were already stored in memo[ ] at an earlier time.

Memoization means no re-computation, which makes for a more efficient algorithm. Thus, memoization ensures that dynamic programming is efficient, but it is choosing the right sub-problem that guarantees that a dynamic program goes through all possibilities in order to find the best one.

Now that we’ve addressed memoization and sub-problems, it’s time to learn the dynamic programming process. Buckle in.

## My Dynamic Programming Process

### Step 1: Identify the sub-problem in words.
Too often, programmers will turn to writing code before thinking critically about the problem at hand. Not good. One strategy for firing up your brain before you touch the keyboard is using words, English or otherwise, to describe the sub-problem that you have identified within the original problem.

If you’re solving a problem that requires dynamic programming, grab a piece of paper and think about the information that you need to solve this problem. Write out the sub-problem with this in mind.

For example, in the punchcard problem, I stated that the sub-problem can be written as “the maximum value schedule for punchcards i through n such that the punchcards are sorted by start time.” I found this sub-problem by realizing that, in order to determine the maximum value schedule for punchcards 1 through n such that the punchcards are sorted by start time, I would need to find the answer to the following sub-problems:

- The maximum value schedule for punchcards n-1 through n such that the punchcards are sorted by start time
- The maximum value schedule for punchcards n-2 through n such that the punchcards are sorted by start time
- The maximum value schedule for punchcards n-3 through n such that the punchcards are sorted by start time (Et cetera)
- The maximum value schedule for punchcards 2 through n such that the punchcards are sorted by start time
If you can identify a sub-problem that builds upon previous sub-problems to solve the problem at hand, then you’re on the right track.

### Step 2: Write out the sub-problem as a recurring mathematical decision.

Once you’ve identified a sub-problem in words, it’s time to write it out mathematically. Why? Well, the mathematical recurrence, or repeated decision, that you find will eventually be what you put into your code. Besides, writing out the sub-problem mathematically vets your sub-problem in words from Step 1. If it is difficult to encode your sub-problem from Step 1 in math, then it may be the wrong sub-problem!

There are two questions that I ask myself every time I try to find a recurrence:

- What decision do I make at every step?
- If my algorithm is at step i, what information would it need to decide what to do in step i+1? (And sometimes: If my algorithm is at step i, what information did it need to decide what to do in step i-1?)
Let’s return to the punchcard problem and ask these questions.

**What decision do I make at every step?**<br> Assume that the punchcards are sorted by start time, as mentioned previously. For each punchcard that is compatible with the schedule so far (its start time is after the finish time of the punchcard that is currently running), the algorithm must choose between two options: to run, or not to run the punchcard.

![image](https://github.com/nitishhsinghhh/Tips-and-Tricks-for-Programming-using-Cpp/assets/93253740/884fff4d-6478-4b32-bd71-a9eefe98e0a9)

If my algorithm is at step i, what information would it need to decide what to do in step i+1? To decide between the two options, the algorithm needs to know the next compatible punchcard in the order. The next compatible punchcard for a given punchcard p is the punchcard q such that s_q (the predetermined start time for punchcard q) happens after f_p (the predetermined finish time for punchcard p) and the difference between s_q and f_p is minimized. Abandoning mathematician-speak, the next compatible punchcard is the one with the earliest start time after the current punchcard finishes running.

If my algorithm is at step i, what information did it need to decide what to do in step i-1? The algorithm needs to know about future decisions: the ones made for punchcards i through n in order to decide to run or not to run punchcard i-1.

Now that we’ve answered these questions, perhaps you’ve started to form a recurring mathematical decision in your mind. If not, that’s also okay, it becomes easier to write recurrences as you get exposed to more dynamic programming problems.

Without further ado, here’s our recurrence:

```
OPT(i) = max(v_i + OPT(next[i]), OPT(i+1))
```
In this equation, OPT(i) is defined as the maximum of two choices:

Choose the value at position i (v_i) and add it to the optimal value at the next position (OPT(next[i])).
Skip the value at position i and move to the next position, considering the optimal value at that position (OPT(i+1)).
This type of recursive formula is commonly used in dynamic programming to find the optimal solution by considering all possible choices at each step and selecting the one that leads to the best overall outcome.

This mathematical recurrence requires some explaining, especially for those who haven’t written one before. I use OPT(i) to represent the maximum value schedule for punchcards i through n such that the punchcards are sorted by start time. Sounds familiar, right? OPT(•) is our sub-problem from Step 1.

In order to determine the value of OPT(i), we consider two options, and we want to take the maximum of these options in order to meet our goal: the maximum value schedule for all punchcards. Once we choose the option that gives the maximum result at step i, we memoize its value as OPT(i).

The two options — to run or not to run punchcard i — are represented mathematically as follows:

```
v_i + OPT(next[i])
```
This clause represents the decision to run punchcard i. It adds the value gained from running punchcard i to OPT(next[i]), where next[i] represents the next compatible punchcard following punchcard i. OPT(next[i]) gives the maximum value schedule for punchcards next[i] through n such that the punchcards are sorted by start time. Adding these two values together produces maximum value schedule for punchcards i through n such that the punchcards are sorted by start time if punchcard i is run.

```
OPT(i+1)
```
Conversely, this clause represents the decision to not run punchcard i. If punchcard i is not run, its value is not gained. OPT(i+1) gives the maximum value schedule for punchcards i+1 through n such that the punchcards are sorted by start time. So, OPT(i+1) gives the maximum value schedule for punchcards i through n such that the punchcards are sorted by start time if punchcard i is not run.

In this way, the decision made at each step of the punchcard problems is encoded mathematically to reflect the sub-problem in Step 1.

### Step 3: Solve the original problem using Steps 1 and 2.
In Step 1, we wrote down the sub-problem for the punchcard problem in words. In Step 2, we wrote down a recurring mathematical decision that corresponds to these sub-problems. How can we solve the original problem with this information?

```
OPT(1)
```
It’s that simple. Since the sub-problem we found in Step 1 is the maximum value schedule for punchcards i through n such that the punchcards are sorted by start time, we can write out the solution to the original problem as the maximum value schedule for punchcards 1 through n such that the punchcards are sorted by start time. Since Steps 1 and 2 go hand in hand, the original problem can also be written as OPT(1).

### Step 4: Determine the dimensions of the memoization array and the direction in which it should be filled.
Did you find Step 3 deceptively simple? It sure seems that way. You may be thinking, how can OPT(1) be the solution to our dynamic program if it relies on OPT(2), OPT(next[1]), and so on?

You’re correct to notice that OPT(1) relies on the solution to OPT(2). This follows directly from Step 2:

```
OPT(1) = max(v_1 + OPT(next[1]), OPT(2))
```
But this is not a crushing issue. Think back to Fibonacci memoization example. To find the Fibonacci value for n = 5, the algorithm relies on the fact that the Fibonacci values for n = 4, n = 3, n = 2, n = 1, and n = 0 were already memoized. If we fill in our memoization table in the correct order, the reliance of OPT(1) on other sub-problems is no big deal.

How can we identify the correct direction to fill the memoization table? In the punchcard problem, since we know OPT(1) relies on the solutions to OPT(2) and OPT(next[1]), and that punchcards 2 and next[1] have start times after punchcard 1 due to sorting, we can infer that we need to fill our memoization table from OPT(n) to OPT(1).

How do we determine the dimensions of this memoization array? Here’s a trick: the dimensions of the array are equal to the number and size of the variables on which OPT(•) relies. In the punchcard problem, we have OPT(i), which means that OPT(•) only relies on variable i, which represents the punchcard number. This suggest that our memoization array will be one-dimensional and that its size will be n since there are n total punchcards.

If we know that n = 5, then our memoization array might look like this:

```
memo = [OPT(1), OPT(2), OPT(3), OPT(4), OPT(5)]
```
However, because many programming languages start indexing arrays at 0, it may be more convenient to create this memoization array so that its indices align with punchcard numbers:

```
memo = [0, OPT(1), OPT(2), OPT(3), OPT(4), OPT(5)]
```

### Step 5: Code it!
To code our dynamic program, we put together Steps 2–4. The only new piece of information that you’ll need to write a dynamic program is a base case, which you can find as you tinker with your algorithm.

A dynamic program for the punchcard problem will look something like this:

```
def punchcardSchedule(n, values, next): # Initialize memoization array - Step 4  memo = [0] * (n+1)   # Set base case  memo[n] = values[n]   # Build memoization table from n to 1 - Step 2  for i in range(n-1, 0, -1):    memo[i] = max(v_i + memo[next[i]], memo[i+1])  # Return solution to original problem OPT(1) - Step 3  return memo[1]
```
Congrats on writing your first dynamic program! Now that you’ve wet your feet, I’ll walk you through a different type of dynamic program.

## Paradox of Choice: Multiple Options DP Example

![image](https://github.com/nitishhsinghhh/Tips-and-Tricks-for-Programming-using-Cpp/assets/93253740/980dad59-bd0b-4190-b8a1-051d276703d6)


Although the previous dynamic programming example had a two-option decision — to run or not to run a punchcard — some problems require that multiple options be considered before a decision can be made at each step.

Time for a new example.

Pretend you’re selling the friendship bracelets to n customers, and the value of that product increases monotonically. This means that the product has prices {p_1, …, p_n} such that p_i ≤ p_j if customer j comes after customer i. These n customers have values {v_1, …, v_n}. A given customer i will buy a friendship bracelet at price p_i if and only if p_i ≤ v_i; otherwise the revenue obtained from that customer is 0. Assume prices are natural numbers.

**Problem:** You must find the set of prices that ensure you the maximum possible revenue from selling your friendship bracelets.

Take a second to think about how you might address this problem before looking at my solutions to Steps 1 and 2.

### Step 1: Identify the sub-problem in words.
Sub-problem: The maximum revenue obtained from customers i through n such that the price for customer i-1 was set at q.

I found this sub-problem by realizing that to determine the maximum revenue for customers 1 through n, I would need to find the answer to the following sub-problems:

The maximum revenue obtained from customers n-1 through n such that the price for customer n-2 was set at q.
The maximum revenue obtained from customers n-2 through n such that the price for customer n-3 was set at q.
(Et cetera)
Notice that I introduced a second variable q into the sub-problem. I did this because, in order to solve each sub-problem, I need to know the price I set for the customer before that sub-problem. Variable q ensures the monotonic nature of the set of prices, and variable i keeps track of the current customer.

### Step 2: Write out the sub-problem as a recurring mathematical decision.
There are two questions that I ask myself every time I try to find a recurrence:

- What decision do I make at every step?
- If my algorithm is at step i, what information would it need to decide what to do in step i+1? (And sometimes: If my algorithm is at step i, what information would it need to decide what to do in step i-1?)
Let’s return to the friendship bracelet problem and ask these questions.

What decision do I make at every step? I decide at which price to sell my friendship bracelet to the current customer. Since prices must be natural numbers, I know that I should set my price for customer i in the range from q — the price set for customer i-1 — to v_i — the maximum price at which customer i will buy a friendship bracelet.

**If my algorithm is at step i, what information would it need to decide what to do in step i+1? My algorithm needs to know the price set for customer i and the value of customer i+1 in order to decide at what natural number to set the price for customer i+1.**
With this knowledge, I can mathematically write out the recurrence:

```
OPT(i,q) = max~([Revenue(v_i, a) + OPT(i+1, a)])
```

```
such that max~ finds the maximum over all a in the range q ≤ a ≤ v_i
```
Once again, this mathematical recurrence requires some explaining. Since the price for customer i-1 is q, for customer i, the price a either stays at integer q or it changes to be some integer between q+1 and v_i. To find the total revenue, we add the revenue from customer i to the maximum revenue obtained from customers i+1 through n such that the price for customer i was set at a.

In other words, to maximize the total revenue, the algorithm must find the optimal price for customer i by checking all possible prices between q and v_i. If v_i ≤ q, then the price a must remain at q.

## What about the other steps?
Working through Steps 1 and 2 is the most difficult part of dynamic programming. As an exercise, I suggest you work through Steps 3, 4, and 5 on your own to check your understanding.

## Runtime Analysis of Dynamic Programs
Now for the fun part of writing algorithms: runtime analysis. I’ll be using big-O notation throughout this discussion . If you’re not yet familiar with big-O, I suggest you read up on it here.

Generally, a dynamic program’s runtime is composed of the following features:

- Pre-processing
- How many times the for loop runs\
- How much time it takes the recurrence to run in one for loop iteration
- Post-processing
Overall, runtime takes the following form:

```
Pre-processing + Loop * Recurrence + Post-processing
```
Let’s perform a runtime analysis of the punchcard problem to get familiar with big-O for dynamic programs. Here is the punchcard problem dynamic program:

```
def punchcardSchedule(n, values, next): # Initialize memoization array - Step 4  memo = [0] * (n+1)   # Set base case  memo[n] = values[n]   # Build memoization table from n to 1 - Step 2  for i in range(n-1, 0, -1):    memo[i] = max(v_i + memo[next[i]], memo[i+1])  # Return solution to original problem OPT(1) - Step 3  return memo[1]
```
Let’s break down its runtime:

- Pre-processing: Here, this means building the the memoization array. O(n).
- How many times the for loop runs: O(n).
- How much time it takes the recurrence to run in one for loop iteration: The recurrence takes constant time to run because it makes a decision between two options in each iteration. O(1).
- Post-processing: None here! O(1).
The overall runtime of the punchcard problem dynamic program is O(n) O(n) * O(1) + O(1), or, in simplified form, O(n).
