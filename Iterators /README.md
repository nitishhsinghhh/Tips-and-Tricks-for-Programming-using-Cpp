# Iterators 
Iterators are a key component of the C++ Standard Template Library (STL) and serve as a unified way to access elements within various types of containers, such as vectors, lists, and arrays. They simplify the complexity of working with containers and promote code reusability.

In C++, iterators are categorized into five main types:
- input iterators,
- output iterators,
- forward iterators,
- bidirectional iterators, and
- random access iterators.

Each type of iterator has its own specific functionality and capabilities, providing a range of options for working with different types of containers. This article will cover the concept of iterators in C++98, how to effectively use them, and their role in streamlining container traversal.

Ins traightforward terms, an iterator is an object that enables us to access and modify elements within a container. It functions as a generalized pointer that moves through the elements of a container, providing a consistent way to access and modify these elements without directly interacting with the underlying container implementation.

Iterators are a foundational component of the C++ STL. They are used to point to the memory address of STL container classes and can be likened to pointers to some extent. Serving as a link between algorithms and STL containers, iterators facilitate the modification of data within the container, allowing iteration, access, assignment of values, and the application of various operators to achieve desired outcomes.

C++98 introduces various iterator types, each designed for specific purposes. Some of the commonly used iterator types in C++98 include:

1. Input Iterator: Enables read-only traversal in a forward direction.
2. Output Iterator: Facilitates write-only traversal in a forward direction.
3. Forward Iterator: Supports both read and write traversal in a forward direction.
4. Bidirectional Iterator: Allows for read and write traversal in both forward and backward directions.
5. Random Access Iterator: Provides read and write traversal with direct element access using operators such as +, -, +=, and -=.

Syntax of Defining Iterators:

The syntax for defining iterators in C++ is as follows:
```
<Container_Type>::iterator;
<Container_Type>::const_iterator;
In the above syntax:
```

```Container_Type``` represents the type of container for which the iterator is being declared.
It’s important to note that not all STL containers support all five types of iterators. For example, the “vector” container supports random-access iterators, while the “list” container supports bidirectional iterators.

The table below summarizes the STL containers and the iterators supported by them in C++:

![image](https://github.com/nitishhsinghhh/Tips-and-Tricks-Programming-using-Cpp/assets/93253740/02099909-9175-4907-a97d-9b5b5dc6d0f5)



