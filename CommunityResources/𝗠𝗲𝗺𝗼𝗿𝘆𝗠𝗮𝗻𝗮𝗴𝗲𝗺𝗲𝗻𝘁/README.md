# Engineering Standards: Memory Management in C++

- Domain: Memory Safety & Object Lifecycle

- Principle: Ownership is Absolute. Use type-aware allocation to guarantee system stability.

## 1. Avoid malloc() and free() in C++ Code

When it comes to dynamic memory allocation in C++, the use of malloc() and free() might seem like a convenient option. However, there are crucial reasons to steer clear of these functions, especially when working with C++ objects.

### No Support for Construction and Destruction

One significant drawback of malloc() and free() is their lack of support for the proper construction and destruction of C++ objects. Using malloc() can lead to uninitialized objects, which can cause unexpected behavior because the constructor is never invoked.

### Mixing Allocation Methods

Mixing malloc() and free() with new and delete results in errors and is strictly considered bad practice. Deleting an object allocated by malloc() or freeing an object allocated by new leads to undefined behavior (UB).

## 2. Enforcement and Code Safety

It is crucial to flag the explicit use of malloc() and free() in your codebase. These instances should be easily noticeable during code review or static analysis. While some legacy implementations might appear to allow mixing these methods, it is not guaranteed and frequently causes runtime corruption.

### Exception Handling in Hard Real-Time Code

In life-critical hard real-time code, standard exceptions may not be acceptable due to non-deterministic timing. In such cases, utilize the nothrow versions of new to handle allocation failures via null-checks rather than exception overhead.

```C++
// SDE-6 Standard: Handling allocation in real-time constraints
MyObject* obj = new (std::nothrow) MyObject();
if (!obj) {
    // Handle allocation failure deterministically
}
```

## 3. Legacy Constraints vs. Modern Requirements

While there are legitimate reasons to avoid exceptions (like hard real-time requirements), it is essential to distinguish between genuine technical constraints and outdated beliefs. Evaluate the specific needs of the application rather than following a blanket ban based on older, less efficient codebases.

## 4. Summary Matrix: Allocation Types

| Feature            | malloc / free       | new / delete            | Smart Pointers (RAII)  |
|--------------------|---------------------|------------------------ |------------------------|
| Constructor Call   | No                  | Yes                     | Yes                    |
| Destructor Call    | No                  | Yes                     | Yes                    |
| Type Safety        | void* (None)        | Type-safe               | Type-safe              |
| Memory Cleanup     | Manual              | Manual                  | Automatic              |
| Best Use Case      | Legacy C Interop    | Low-level internal libs | Production Standard    |

[Credit](https://www.linkedin.com/in/rafael-rodriguez-calvente/)
