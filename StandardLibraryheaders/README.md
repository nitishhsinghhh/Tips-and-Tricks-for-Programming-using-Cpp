# C++ Standard Library headers
The interface of C++ standard library is defined by the following collection of headers.

| Category                | Header(s)                                                                                   | Description                                           |
|-------------------------|---------------------------------------------------------------------------------------------|-------------------------------------------------------|
| Concepts library        | `<concepts>` _(C++20)_                                                                       |  Fundamental library concepts                         |
| Coroutines library      | `<coroutine>` _(C++20)_                                                                       |   Coroutine support library                           |
|   Utilities library     | `<any>` _(C++17)_                                                                           |      std::any class                                   |
|                         | `<bitset>`                                                                                 | std::bitset class template                             |
|                          | `<chrono>`  _(C++11)_                                                                               |  C++ time utilities                              |
|                          | `<compare>` _(C++20)_                                                                              | Three-way comparison operator support           |
|                          | `<csetjmp>`                                                                                | Macro (and function) that saves (and jumps) to an execution context |
|                          | `<csignal>`                                                                                | Functions and macro constants for signal management    |
|                          | `<cstdarg>`                                                                                | Handling of variable length argument lists             |
|                          | `<cstddef>`                                                                                | Standard macros and typedefs                           |
|                          | `<cstdlib>`                                                                                | General purpose utilities: program control, dynamic memory allocation, random numbers, sort and search |
|                          | `<ctime>`                                                                                  | C-style time/date utilities                            |
|                          | `<debugging>` _(C++26)_                                                                      | Debugging library                               |
|                          | `<expected>`  _(C++23)_                                                                      | std::expected class template                    |
|                          | `<functional>`                                                                             | Function objects, Function invocations, Bind operations and Reference wrappers |
|                          | `<initializer_list>` _(C++11)_ | std::initializer_list class template             |
|                          | `<optional>` _(C++17)_ | std::optional class template                    |
|                          | `<source_location>` _(C++20)_ | Supplies means to obtain source code location   |
|                          | `<tuple>`  _(C++11)_ | std::tuple class template                        |
|                          | `<type_traits>`  _(C++11)_                                                                          |  Compile-time type information                   |
|                          | `<typeindex>`    _(C++11) _                                                                         |  std::type_index                                 |
|                          | `<typeinfo>`                                                                               | Runtime type information utilities                     |
|                          | `<utility>`                                                                                | Various utility components                             |
|                          | `<variant>` _(C++17)_                                                                               |  std::variant class template                     |
|                          | `<version>`   _(C++20)_                                                                             | Supplies implementation-dependent library information |
| Dynamic memory management | `<memory>`                                                                                 | High-level memory management utilities                 |
|                          | `<memory_resource>`  _(C++17)_                                                                     |  Polymorphic allocators and memory resources     |
|                          | `<new>`                                                                                    | Low-level memory management utilities                   |
|                          | `<scoped_allocator>` _(C++11)_                                                                       |  Nested allocator class                          |
| Numeric limits           | `<cfloat>`                                                                                 | Limits of floating-point types                         |
|                          | `<cinttypes>`   _(C++11)_                                                                             | Formatting macros, intmax_t and uintmax_t math and conversions |
|                          | `<climits>`                                                                                | Limits of integral types                               |
|                          | `<cstdint>`      _(C++11)_                                                                            | Fixed-width integer types and limits of other types |
|                          | `<limits>`                                                                                 | Uniform way to query properties of arithmetic types     |
|                          | `<stdfloat>`     _(C++23)_                                                                            | Optional extended floating-point types          |
| Error handling           | `<cassert>`                                                                                | Conditionally compiled macro that compares its argument to zero |
|                          | `<cerrno>`                                                                                 | Macro containing the last error number                 |
|                          | `<exception>`                                                                              | Exception handling utilities                            |
|                          | `<stacktrace>`   _(C++23)_                                                                           | Stacktrace library                               |
|                          | `<stdexcept>`                                                                              | Standard exception objects                             |
|                          | `<system_error>`        _(C++11)_                                                                | Defines std::error_code, a platform-dependent error
