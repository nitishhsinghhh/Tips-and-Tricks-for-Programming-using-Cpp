# C++ Design Patterns

Software design patterns provide a structured approach to solving common design problems in software development. They encapsulate solutions to recurring design challenges and provide a common vocabulary for developers to communicate and share best practices. By utilizing design patterns, developers can benefit from proven solutions that promote maintainability, scalability, and reusability in their software systems.

The Gang of Four (GoF) book "Design Patterns: Elements of Reusable Object-Oriented Software" introduced 23 classic software design patterns, which are categorized into three main groups: creational, structural, and behavioral patterns. Each pattern addresses a specific design problem and provides a blueprint for implementing an effective solution.

Here's a brief overview of the three main categories of design patterns:

1. **Creational Patterns:** <br>
These patterns focus on object creation mechanisms, providing flexibility in creating objects while hiding the creation logic. Examples include Factory Method, Abstract Factory, Singleton, Builder, and Prototype patterns.
2. **Structural Patterns:** <br>
Structural patterns deal with the composition of classes and objects to form larger structures. They help in building relationships between objects and classes to form a cohesive system. Examples include Adapter, Bridge, Composite, Decorator, Facade, Flyweight, and Proxy patterns.
3. **Behavioral Patterns:** <br>
Behavioral patterns are concerned with communication between objects and the assignment of responsibilities between them. They facilitate the interaction and collaboration between objects, improving the flexibility of the system. Examples include Chain of Responsibility, Command, Iterator, Mediator, Memento, Observer, State, Strategy, Template Method, Visitor, and Interpreter patterns.

By understanding and applying these design patterns, software developers can improve the quality, maintainability, and extensibility of their software systems. Design patterns serve as a valuable resource for software developers to address common design challenges and create robust, scalable, and maintainable software solutions.

# Design Patterns in Software Engineering

Choosing the correct design pattern in software engineering is critical to practical problem-solving. This guide simplifies the process, helping you decide between patterns based on specific needs. It offers concise descriptions and valuable use cases for each pattern, making understanding and applying them in real-world scenarios easier.

## To select a pattern, we must first go through the problem identification. If the problem is related to:

 🔸 Object Creation? → Creational Patterns<br>
 🔸 Object Assembly? → Structural Patterns<br>
 🔸 Object Interactions? → Behavioral Patterns<br>

## Creational Patterns
- **Singleton:** Use when a single instance of a class is needed. Some examples are logging and database connections.
- **Factory Method:** Decouple object creation from usage. For example, you create different types of database connections based on configuration.
- **Abstract Factory:** Create families of related objects. For example, building parsers for different file formats (e.g., JSON, XML, CSV).
- **Builder:** Constructing complex objects step by step. For example, creating a complex domain object.
- **Prototype:** Creating duplicate objects and reusing cached objects to reduce database calls.

## Structural Patterns
- **Adapter:** Make incompatible interfaces compatible. For example, integrating a new logging library into an existing system that expects a different interface.
- **Composite:** Represent part-whole hierarchies. For example, grouping graphic objects in a drawing application and treating them uniformly.
- **Proxy:** Control access to objects. For example, lazy loading of a high-resolution image in a web application.
- **Decorator:** Dynamically add/remove behavior. For example, implementing compression or encryption on top of file streams.
- **Bridge:** Decouple abstraction from implementation. For example, separating platform-specific code from core logic.

## Behavioral Patterns
- **Strategy:** Define a family of algorithms. For example, allowing users to choose different sorting or compression algorithms.
- **Observer:** Maintain a consistent state by being notified of changes and notifying subscribers of events in a messaging system.
- **Command:** Encapsulate a request as an object. For example, implementing undo/redo functionality in a text or image editor.
- **State:** Encapsulate state-specific behavior. For example, handling different states of a user interface element (e.g., enabled, disabled, selected).
- **Template Method:** Define the skeleton of an algorithm in operation, deferring some steps to subclasses and implementing a base class for unit testing with customizable setup and teardown steps.

Credits: [Dr Milan Milanović](https://www.linkedin.com/in/milanmilanovic/)
