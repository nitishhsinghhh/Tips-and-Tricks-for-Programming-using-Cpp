#include <iostream>
#include <string>
#include <unordered_map>
#include <random>
#include <vector>

using std::string;
using std::unordered_map;
using std::cout;
using std::endl;
using std::vector;
class LinkShortener {
private:
	unordered_map<string, string> links;
	string base_url;

	string generateRandomCode(int length) {
		const string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
		std::random_device rd;
		std::mt19937 generator(rd());
		std::uniform_int_distribution<int> distribution(0, characters.size() - 1);
		string code;
		for (int i = 0; i < length; ++i)
			code += characters[distribution(generator)];
		return code;
	}

public:
	LinkShortener(const string& baseUrl) : base_url(baseUrl) {}

	string shortenLink(const string& originalLink) {
		string shortCode;

		do {
			shortCode = generateRandomCode(6);
		} while (links.find(base_url + shortCode) != links.end());

		string shortenedLink = base_url + shortCode;
		links[shortenedLink] = originalLink;

		return shortenedLink;
	}

	string getOriginalLink(const string& shortenedLink) {
		if (links.find(shortenedLink) != links.end())
			return links[shortenedLink];

		return ""; // Return empty string if the shortened link doesn't exist
	}
};

int main() {
    string baseUrl = "https://github.com/";
    LinkShortener shortener(baseUrl);

    // 20 test URLs
    vector<string> testUrls = {
        "https://example.com/page1",
        "https://example.com/page2",
        "https://example.com/page3",
        "https://example.com/page4",
        "https://example.com/page5",
        "https://example.com/page6",
        "https://example.com/page7",
        "https://example.com/page8",
        "https://example.com/page9",
        "https://example.com/page10",
        "https://example.com/page11",
        "https://example.com/page12",
        "https://example.com/page13",
        "https://example.com/page14",
        "https://example.com/page15",
        "https://example.com/page16",
        "https://example.com/page17",
        "https://example.com/page18",
        "https://example.com/page19",
        "https://example.com/page20"
    };

    cout << "Testing 20 URLs with base URL: " << baseUrl << endl;
    cout << "---------------------------------------------" << endl;

    for (auto &url : testUrls) {
        string shortened = shortener.shortenLink(url);
        string original = shortener.getOriginalLink(shortened);

        cout << "Original URL: " << url << endl;
        cout << "Shortened URL: " << shortened << endl;
        cout << "Retrieved URL: " << original << endl;

        if (original != url) {
            cout << "ERROR: Retrieved URL does not match original!" << endl;
        }

        cout << "---------------------------------------------" << endl;
    }

    return 0;
}

/*
In C++, "catch (...)" is a special exception handler that catches any exception thrown by the try block that it immediately follows. 
The ellipsis "..." is a placeholder that matches any type of exception. This is known as a catch-all exception handler, as it allows 
the programmer to handle any unexpected exceptions that may occur during program execution. It is generally recommended to use more 
specific exception handlers wherever possible, as catch-all handlers can make it difficult to diagnose and fix errors in the code.

The "const" keyword is used to indicate that the exception object being caught is read-only and cannot be modified.
When an exception is caught, it is passed as a reference to the catch block. By making the reference const, we ensure 
that the exception object cannot be modified within the catch block. This is important because modifying the exception 
object could potentially change its state and make it more difficult to diagnose the cause of the exception.
In addition, using a const reference is more efficient than passing the exception object by value, as it avoids the 
unnecessary overhead of creating a copy of the object.
*/
