# What Is Keyboard Input Mapping?
Keyboard Input Mapping is the technique of translating a key press (like pressing the "A" key) into a meaningful action or symbol (like displaying "a" or triggering a command).

##  Examples of Keyboard Input Mapping
 1. Character Mapping:
  Pressing A → outputs 'a' or 'A' depending on Shift/Caps Lock.
  Pressing 1 → outputs '1', or '!' with Shift.
 2. Game Controls:
  Pressing W → move forward.
  Pressing Space → jump.
 3. Custom Shortcuts:
   Pressing Ctrl + S → save file.
   Pressing Alt + F4 → close window.
 4. International Layouts:
  On a French AZERTY keyboard, pressing the same physical key as Q on a US QWERTY keyboard might produce A.

## Why Is It Important?
- Accessibility: Allows remapping for users with different needs.
- Localization: Supports different languages and keyboard layouts.
- Customization: Enables users to create shortcuts or macros.
- Gaming & Software Development: Essential for input handling and control schemes.

# Keyboard Input Mapping in C++
```cpp
/**
 * @file KeyboardInputMapper.cpp
 * @brief Maps keyboard input to actions using SOLID principles.
 * @date May 3, 2024
 * @author 
 * Nitish Singh
 */

#include <iostream>

/**
 * @interface IActionMapper
 * @brief Interface for mapping a key to an action.
 */
class IActionMapper {
public:
    virtual void mapKeyToAction(char key) const = 0;
    virtual ~IActionMapper() = default;
};

/**
 * @class ConsoleActionMapper
 * @brief Maps specific keys to actions and prints them to the console.
 */
class ConsoleActionMapper : public IActionMapper {
public:
    /**
     * @brief Maps a key to a predefined action and prints the result.
     * @param key The character input from the user.
     */
    void mapKeyToAction(char key) const override {
        switch (key) {
            case 'w':
            case 'W':
                std::cout << "Action: Move Up" << std::endl;
                break;
            case 'a':
            case 'A':
                std::cout << "Action: Move Left" << std::endl;
                break;
            case 's':
            case 'S':
                std::cout << "Action: Move Down" << std::endl;
                break;
            case 'd':
            case 'D':
                std::cout << "Action: Move Right" << std::endl;
                break;
            case 'q':
            case 'Q':
                std::cout << "Action: Quit Game" << std::endl;
                break;
            default:
                std::cout << "Unknown key. No action mapped." << std::endl;
        }
    }
};

/**
 * @class InputHandler
 * @brief Handles user input and delegates action mapping.
 */
class InputHandler {
private:
    const IActionMapper& mapper;

public:
    /**
     * @brief Constructor to inject an action mapper.
     * @param m Reference to an IActionMapper implementation.
     */
    InputHandler(const IActionMapper& m) : mapper(m) {}

    /**
     * @brief Prompts the user for input and maps it to an action.
     */
    void handleInput() const {
        char input;
        std::cout << "Control Keys: W/A/S/D to move, Q to quit." << std::endl;
        std::cout << "Enter a key: ";
        std::cin >> input;
        mapper.mapKeyToAction(input);
    }
};

/**
 * @brief Main function to run the input mapping program.
 * @return int Exit status.
 */
int main() {
    ConsoleActionMapper actionMapper;
    InputHandler handler(actionMapper);
    handler.handleInput();
    return 0;
}
```
