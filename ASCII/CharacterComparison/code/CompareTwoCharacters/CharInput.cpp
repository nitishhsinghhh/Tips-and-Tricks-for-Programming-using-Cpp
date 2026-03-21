#include <string>

using std::string;
using std::cout;
using std::cin;

/**
 * @class CharInput
 * @brief Handles user input of characters.
 */
class CharInput {
public:
    /**
     * @brief Prompts user for a character.
     * @param label Label to display before input.
     * @return The character entered by the user.
     */
    char getChar(const string& label) {
        char ch;
        cout << "Enter " << label << " character: ";
        cin >> ch;
        return ch;
    }
};
