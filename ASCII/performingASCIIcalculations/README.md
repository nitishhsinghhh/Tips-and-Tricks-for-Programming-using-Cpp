# CharAdder Application

## 👨‍💻 Author
**Nitish Singh**  
📅 **Date:** December 29, 2023  
📧 **Email:** me.singhnitish@yandex.com

---

## 📌 Overview

This project demonstrates a simple C++ application that performs addition of numeric character strings. It includes two versions:

1. **Basic Version (v1.0)**: Adds two hardcoded character digits.
2. **Extended Version (v1.1)**: Accepts user input, validates it, and performs addition.

---

## 🧩 Components

### 1. `InputValidator`  
Validates that the input string:
- Contains only numeric characters.
- Represents a number between **1 and 3998** (inclusive).

### 2. `CharAdder`  
Adds two numeric strings by:
- Converting each character to its integer value.
- Summing the resulting integers.

### 3. `UserInput`  
Handles user interaction by:
- Prompting the user for input.
- Returning the entered string.

---

### Valid Input Example
Enter first input between 0 to 3999, both excluded: 1234
Enter second input between 0 to 3999, both excluded: 4321
The sum of 1234 and 4321 is 5555

## Invalid Input Examples
### Non-numeric input:
Enter first input between 0 to 3999, both excluded: abc
Invalid input: abc

### Out-of-range input:
Enter first input between 0 to 3999, both excluded: 4000
Invalid input: 4000
