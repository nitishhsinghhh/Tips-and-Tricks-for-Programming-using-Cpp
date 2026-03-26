# Refactored Design (SOLID)

| Principle | Fix |
| --- | --- |
| SRP (Single Responsibility Principle) | Separate conversion logic, factory creation, and client usage into different classes |
| OCP (Open/Closed Principle) | Add new conversion classes without modifying existing switch/conditional logic |
| DIP (Dependency Inversion Principle) | Depend on abstractions (interfaces/abstract classes) instead of concrete implementations |
| RAII (Resource Acquisition Is Initialization) | Use `std::unique_ptr` for automatic memory management and resource safety |

## File Structure

StringConversion/
│
├── IStringConversion.hpp
├── LowerCaseConversion.hpp
├── UpperCaseConversion.hpp
├── CapitalizeWordsConversion.hpp
├── SentenceCaseConversion.hpp
├── ToggleCaseConversion.hpp
├── StringConversionFactory.hpp
├── Client.hpp
├── main.cpp
├── StringConversionTests.cpp
├── CMakeLists.txt
