# C++ Standard Library headers
The interface of C++ standard library is defined by the following collection of headers.

| Category                | Header(s)                                                                                   | Description                                           |
|-------------------------|---------------------------------------------------------------------------------------------|-------------------------------------------------------|
| Concepts library        | `<concepts>` (C++20)                                                                        |  Fundamental library concepts                         |
| Coroutines library      | `<coroutine>` (C++20)                                                                       |   Coroutine support library                           |
|   Utilities library     | `<any>` (C++17)                                                                             |      std::any class                                   |
|                         | `<bitset>`                                                                                 | std::bitset class template                             |
|                          | `<chrono>`  (C++11)                                                                               |  C++ time utilities                              |
|                          | `<compare>` (C++20)                                                                              | Three-way comparison operator support           |
|                          | `<csetjmp>`                                                                                | Macro (and function) that saves (and jumps) to an execution context |
|                          | `<csignal>`                                                                                | Functions and macro constants for signal management    |
|                          | `<cstdarg>`                                                                                | Handling of variable length argument lists             |
|                          | `<cstddef>`                                                                                | Standard macros and typedefs                           |
|                          | `<cstdlib>`                                                                                | General purpose utilities: program control, dynamic memory allocation, random numbers, sort and search |
|                          | `<ctime>`                                                                                  | C-style time/date utilities                            |
|                          | `<debugging>` (C++26)                                                                      | Debugging library                               |
|                          | `<expected>`  (C++23)                                                                      | std::expected class template                    |
|                          | `<functional>`                                                                             | Function objects, Function invocations, Bind operations and Reference wrappers |
|                          | `<initializer_list>` (C++11) | std::initializer_list class template             |
|                          | `<optional>` (C++17) | std::optional class template                    |
|                          | `<source_location>` (C++20) | Supplies means to obtain source code location   |
|                          | `<tuple>`  (C++11) | std::tuple class template                        |
|                          | `<type_traits>`  (C++11)                                                                          |  Compile-time type information                   |
|                          | `<typeindex>`    (C++11)                                                                          |  std::type_index                                 |
|                          | `<typeinfo>`                                                                               | Runtime type information utilities                     |
|                          | `<utility>`                                                                                | Various utility components                             |
|                          | `<variant>` (C++17)                                                                               |  std::variant class template                     |
|                          | `<version>`   (C++20)                                                                             | Supplies implementation-dependent library information |
| Dynamic memory management | `<memory>`                                                                                 | High-level memory management utilities                 |
|                          | `<memory_resource>`  (C++17)                                                                      |  Polymorphic allocators and memory resources     |
|                          | `<new>`                                                                                    | Low-level memory management utilities                   |
|                          | `<scoped_allocator>` (C++11)                                                                       |  Nested allocator class                          |
| Numeric limits           | `<cfloat>`                                                                                 | Limits of floating-point types                         |
|                          | `<cinttypes>`   (C++11)                                                                             | Formatting macros, intmax_t and uintmax_t math and conversions |
|                          | `<climits>`                                                                                | Limits of integral types                               |
|                          | `<cstdint>`      (C++11)                                                                            | Fixed-width integer types and limits of other types |
|                          | `<limits>`                                                                                 | Uniform way to query properties of arithmetic types     |
|                          | `<stdfloat>`     _(C++23)_                                                                            | Optional extended floating-point types          |
| Error handling           | `<cassert>`                                                                                | Conditionally compiled macro that compares its argument to zero |
|                          | `<cerrno>`                                                                                 | Macro containing the last error number                 |
|                          | `<exception>`                                                                              | Exception handling utilities                            |
|                          | `<stacktrace>`   _(C++23) _                                                                           | Stacktrace library                               |
|                          | `<stdexcept>`                                                                              | Standard exception objects                             |
|                          | `<system_error>`        _(C++11)    _                                                                | Defines std::error_code, a platform-dependent error
