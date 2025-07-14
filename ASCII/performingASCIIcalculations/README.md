# CharAdder

## Author
**Nitish Singh**  
📅 **Date:** February 12, 2024  
📧 **Email:** me.singhnitish@yandex.com

---

## 📘 Problem Statement

The `CharAdder` class is designed to add two characters that represent numeric digits. It converts the characters to their integer equivalents and returns their sum.

---

## 🛠️ Solution Overview

- The `CharAdder` class accepts two characters as input.
- It converts these characters to integers using ASCII arithmetic.
- The `add()` method returns the sum of the two numeric values.
- The `main` function demonstrates the usage by adding `'3'` and `'7'`.

---

## 🧱 Class Structure

### `CharAdder`

| Member        | Type   | Description                                      |
|---------------|--------|--------------------------------------------------|
| `char1`       | `char` | First character input                            |
| `char2`       | `char` | Second character input                           |
| `CharAdder()` | ctor   | Parameterized constructor to initialize members  |
| `add()`       | `int`  | Returns the sum of `char1` and `char2` as ints   |

**Constructor Explanation:**
```cpp
CharAdder(char c1, char c2) : char1(c1), char2(c2) {}
