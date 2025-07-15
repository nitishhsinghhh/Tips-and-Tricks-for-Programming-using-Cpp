# Adapter Pattern | C++ Design Patterns
Adapter Pattern is a structural design pattern used to make two incompatible interfaces work together. It acts as a bridge between two incompatible interfaces, allowing them to collaborate without modifying their source code. This pattern is particularly useful when integrating legacy code or third-party libraries into your application.

## Adapter Pattern example in C++ Design Patterns
### Problem Statement
```
Suppose you have a legacy printer class that only understands commands in uppercase, and a modern computer class that sends commands in lowercase. 
You need to make the modern computer work with the legacy printer without modifying the existing printer class.
```

### Implementation of the Adapter Pattern in C++ Design Patterns:
It defines three classes:
- LegacyPrinter is the legacy component (Adaptee). It has a method printInUppercase that can print text in uppercase.
- ModernComputer is the modern client class. It has a method sendCommand to send commands, but it sends them in lowercase.
- PrinterAdapter is the adapter class. It encapsulates the LegacyPrinter and adapts it to work with the ModernComputer.

```cpp
#include <iostream>
#include <string>
#include <algorithm> // For std::toupper

// Legacy Printer (Adaptee)
class LegacyPrinter {
public:
    void printInUppercase(const std::string& text) {
        std::cout << "Printing: " << text << std::endl;
    }
};

// Modern Computer (Client)
class ModernComputer {
public:
    void sendCommand(const std::string& command) {
        std::cout << "Sending command: " << command << std::endl;
    }
};

// Adapter class to make the LegacyPrinter compatible with ModernComputer
class PrinterAdapter {
private:
    LegacyPrinter legacyPrinter;

public:
    void sendCommand(const std::string& command) {
        // Convert the command to uppercase and pass it to the LegacyPrinter
        std::string uppercaseCommand = command;
        std::transform(uppercaseCommand.begin(), uppercaseCommand.end(), uppercaseCommand.begin(), ::toupper);
        legacyPrinter.printInUppercase(uppercaseCommand);
    }
};

int main() {
    ModernComputer computer;
    PrinterAdapter adapter;

    computer.sendCommand("Print this in lowercase");
    adapter.sendCommand("Print this in lowercase (adapted)");

    return 0;
}

```

## Key components of the Adapter pattern in C++ Design Patterns
- Target Interface: This is the interface that your client code expects. It defines the operations or methods that the client code should use.
- Adaptee: This is the existing class or component with an interface that’s incompatible with the target interface. The Adaptee is the class you want to adapt to make it compatible with the client’s expectations.
- Adapter: The Adapter class is responsible for adapting the Adaptee’s interface to the Target interface. It acts as a wrapper around the Adaptee, forwarding calls to the Adaptee’s methods but in a way that is compatible with the client’s expectations.

## Diagrammatic Representation of the Adapter Pattern in C++ Design Patterns
Here is the UML class diagram for the Adapter Pattern:

![image](https://github.com/nitishhsinghhh/Tips-and-Tricks-for-Programming-using-Cpp/assets/93253740/cb00a676-43d1-4752-9823-bc5af7391bf5)

### In this diagram:

- ModernComputer is the client that sends lowercase commands.
- PrinterAdapter is the adapter class that bridges the gap between the client and the legacy printer.
- LegacyPrinter is the legacy class that can only print in uppercase.
- The ModernComputer communicates with the PrinterAdapter, which, in turn, interacts with the LegacyPrinter by adapting the lowercase commands to uppercase before printing.

### Uses of the Adapter Method in C++ Design Patterns:
- Legacy Code Integration: When you need to integrate new code with existing legacy code that has an incompatible interface.
- Library Compatibility: When you want to use a third-party library with a different interface in your project.
- Interface Standardization: To ensure that multiple classes with different interfaces conform to a common interface, making it easier to work with them.
- Testing: In unit testing, you can create adapter classes to mock or stub external dependencies with different interfaces, making testing easier.

### Advantages of the Adapter Pattern in C++ Design Patterns
- Compatibility: Allows integration of new and old systems or components with different interfaces.
- Reusability: Existing classes can be reused without modification, reducing the risk of introducing bugs.
- Flexibility: New adapters can be easily added to adapt various classes to a common interface.
- Maintainability: Isolates changes to the adapter, making it easier to maintain and update systems.

### Disadvantages of the Adapter Pattern in C++ Design Patterns
- Complexity: Introducing adapters can add complexity to the codebase, especially when multiple adapters are used.
- Performance Overhead: Adapters may introduce some performance overhead due to the additional method calls and indirection.
- Potential for Design Confusion: Overuse of the Adapter Pattern can make the codebase less intuitive and harder to understand.\
- Not Always Suitable: Some classes may be too different to adapt easily, making the Adapter Pattern impractical in certain situations.
The Adapter Pattern is a valuable tool for integrating and reusing code with different interfaces, but it should be used judiciously to avoid unnecessary complexity and confusion in the design.


