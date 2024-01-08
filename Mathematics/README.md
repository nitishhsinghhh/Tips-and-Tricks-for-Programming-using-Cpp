# Table of Content

| No. | Filename                                             | Description                                      | Version |
|-----|------------------------------------------------------|--------------------------------------------------|---------|
| 1.  | [Quadratic Equation Solver ](./Quadratic_Equation_Solver_V1.0.cpp) | Program to solve quadratic equations     | 1.0     |
| 2.  | [Quadratic Equation Solver](./Quadratic_Equation_Solver_V1.1.cpp) | Updated program for quadratic equation solving     | 1.1     |
| 3.  | [Prime Factorization](./Prime_Factorization_V1.0.cpp) | Program to perform prime factorization            | 1.0     |
| 4.  | [Prime Factorization](./Prime_Factorization_V1.1.cpp) | Updated logic to perform prime factorization            | 1.1    |
| 5.  | [LCM of two numbers](./LCM_two_numbers_V1.0.cpp)         | Program to calculate LCM of two numbers           | 1.0     |
| 6.  | [LCM and GCD of two numbers](./GCD_two_numbers_V1.0.cpp)         | Program to calculate GCD and LCM of two numbers           | 1.0     |
| 7.  | [LCM and GCD of two numbers](./GCD_LCM_two_numbers_V1.1.cpp) | Updated Program with using interface to calculate GCD and LCM of two numbers   | 1.1     |
| 8.  | [LCM and GCD of two numbers](./GCD_LCM_two_numbers_V1.2.cpp) | Updated Program with updtaed GCD function to calculate GCD and LCM of two numbers      | 1.2     |

# Discriminant

The discriminant is a term used in the context of quadratic equations and is part of the quadratic formula. For a quadratic equation in the form (ax^2 + bx + c = 0), the discriminant is given by the expression inside the square root of the quadratic formula:

[Discriminant = b^2 - 4ac]

The discriminant plays a crucial role in determining the nature of the roots (solutions) of the quadratic equation. Its value provides information about whether the roots are real or complex and whether they are distinct or repeated.

The discriminant can take on three different cases:

1. If Discriminant > 0:
   - Two distinct real roots exist.

2. If Discriminant = 0:
   - There is one real root (a repeated or double root).

3. If Discriminant < 0:
   - The roots are complex conjugates (they have both real and imaginary parts).

The discriminant helps in classifying the solutions and is a fundamental concept when dealing with quadratic equations and their graphical representation. In programming, it is often used to guide the branching logic in solving quadratic equations.

# Essential Tips and Tricks

## **Why is "using namespace std;" considered bad practice?**

When working with multiple libraries or namespaces in your code, it's important to be mindful of potential conflicts that may arise. One common issue is when two libraries import functions into the global namespace, which can lead to conflicts and make your code harder to maintain.

For example, if you have two libraries called Foo and Bar, and you use `using namespace foo;` and `using namespace bar;`, you may encounter issues if both libraries offer functions with the same name.

To avoid such conflicts, it's recommended to use the full namespace when calling functions from different libraries. For example, instead of using `Blah()` from Foo and `Quux()` from Bar directly, you can use `foo::Blah()` and `bar::Quux()`. This approach helps to prevent conflicts, especially when libraries introduce new functions with the same name.

By using the full namespace, you can mitigate potential conflicts and make your code more resilient to changes in library versions.
**Inputs from stackoverflow.**

## Why We  Should Avoid Including <bits/stdc++.h>

Including <bits/stdc++.h> appears to be an increasingly common thing to see, perhaps something newly added to a national curriculum in the current academic year.
I imagine the advantages are vaguely given thus:
- You only need write one #include line.
- You do not need to look up which standard header everything is in.
Unfortunately, this is a lazy hack, naming a GCC internal header directly instead of individual standard headers like <string>, <iostream>, and <vector>. It ruins portability and fosters terrible habits.

The disadvantages include:
- It will probably only work on that compiler.
- You have no idea what it'll do when you use it, because its contents are not set by a standard.
- Even just upgrading your compiler to its own next version may break your program.
- Every single standard header must be parsed and compiled along with your source code, which is slow and results in a bulky executable under certain compilation settings. **Inputs from stackoverflow.**
Don't do it!

[GCC 4.8.0 /bits/stdc++.h source](https://gcc.gnu.org/onlinedocs/gcc-4.8.0/libstdc++/api/a01541_source.html)
<br>
Including <bits/stdc++.h> results in unnecessary bloat and longer compilation times. While it serves as an implementation for precompiled headers, setting it up for precompilation may potentially speed up compilation time for certain projects. Nonetheless, It is recommended taking the time to understand and include each standard library header separately rather than relying on "super headers" unless for precompilation purposes.

# Euclidean algorithms 

The Euclidean algorithm is a method used to determine the greatest common divisor of two positive integers. The greatest common divisor (GCD) of two numbers is the largest number that can evenly divide both of them. One straightforward approach to finding the GCD is to factorize both numbers and then identify and multiply their common prime factors.

![image](https://github.com/nitishhsinghhh/Tips-and-Tricks-Programming-using-Cpp/assets/93253740/a91c9d63-3a4f-4175-97c9-abda1084f2ae)

The basic Euclidean Algorithm for finding the Greatest Common Divisor (GCD) is based on the following principles:

1. When we subtract a smaller number from a larger one, the GCD remains the same. Therefore, by repeatedly subtracting the larger number from the smaller one, we eventually arrive at the GCD.
2. Alternatively, instead of subtraction, if we divide the smaller number by the larger one, the algorithm stops when the remainder is 0.

```cpp
// Function to return gcd of a and b
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}
```

The product of the least common multiple (LCM) and greatest common divisor (GCD) of two natural numbers, a and b, is equal to the product of the two numbers. This equation is helpful for calculating the LCM, GCD, or the numbers themselves when three out of the four values are known.

```
LCM (a , b) × HCF (a , b) = a × b
```

# What are Prime Numbers?
A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself. In other words, a prime number is a whole number greater than 1 that cannot be formed by multiplying two smaller natural numbers. The initial prime numbers include 2, 3, 5, 7, 11, 13, 17, 19, 23, and so on.

OpenAI GPT3.5
Friday 11:03 AM

#### Here are some interesting facts about prime numbers:

1. With the exception of 2, which is the smallest and only even prime number, all other prime numbers are odd.
2. Every prime number, except for 2 and 3, can be expressed in the form of 6n + 1 or 6n - 1, where n is any natural number.
3. 2 and 3 are the only consecutive natural numbers that are prime.
4. The Goldbach Conjecture proposes that every even integer greater than 2 can be expressed as the sum of two prime numbers.
5. Wilson's Theorem states that a natural number p greater than 1 is a prime number if and only if (p-1)! + 1 is divisible by p.

#### How to check whether a number is Prime or not? 

##### Naive Approach: The naive approach is to
Iterate from 2 to  (n-1) and check if any number in this range divides n. If the number divides n, then it is not a prime number.
<br>
Recursion can also be used to check if a number between 2 to n – 1 divides n. If we find any number that divides, we return false.

##### Efficient Approach: An efficient solution is to:
Iterate through all numbers from 2 to ssquare root of n and for every number check if it divides n [because if a number is expressed as n = xy and any of the x or y is greater than the root of n, the other must be less than the root value]. If we find any number that divides, we return false.

##### Another Efficient approach: 
To check whether  the number is prime or not follow the below idea:
We will deal with a few numbers such as 1, 2, 3, and the numbers which are divisible by 2 and 3 in separate cases and for remaining numbers. Iterate from 5 to sqrt(n) and check for each iteration whether (that value) or (that value + 2) divides n or not and increment the value by 6 [because any prime can be expressed as 6n+1 or 6n-1]. If we find any number that divides, we return false.
