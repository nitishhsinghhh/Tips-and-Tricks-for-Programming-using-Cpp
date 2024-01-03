### Discriminant

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

### Mastering Namespace: Essential Tips and Tricks

# **Why is "using namespace std;" considered bad practice?**

When working with multiple libraries or namespaces in your code, it's important to be mindful of potential conflicts that may arise. One common issue is when two libraries import functions into the global namespace, which can lead to conflicts and make your code harder to maintain.

For example, if you have two libraries called Foo and Bar, and you use `using namespace foo;` and `using namespace bar;`, you may encounter issues if both libraries offer functions with the same name.

To avoid such conflicts, it's recommended to use the full namespace when calling functions from different libraries. For example, instead of using `Blah()` from Foo and `Quux()` from Bar directly, you can use `foo::Blah()` and `bar::Quux()`. This approach helps to prevent conflicts, especially when libraries introduce new functions with the same name.

By using the full namespace, you can mitigate potential conflicts and make your code more resilient to changes in library versions.
**Inputs from stackoverflow.**

# Why We  Should Avoid Including <bits/stdc++.h>

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

