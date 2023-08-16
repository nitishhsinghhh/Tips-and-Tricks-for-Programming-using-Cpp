#include <iostream>
#include <string>
#include <unordered_map>
#include <random>
using namespace std;

class LinkShortener {
private:
	unordered_map<string, string> links;
	string base_url;

	string generateRandomCode(int length) {
		const string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
		random_device rd;
		mt19937 generator(rd());
		uniform_int_distribution<int> distribution(0, characters.size() - 1);
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
	try {
		cout << "This program generates shortened links based on a given base URL." << endl;
		cout << "In the URL : https://github.com/nitishhsinghhh. The base URL is: https://github.com/" << endl;

		cout << "Please enter the base URL: ";
		string baseUrl = "";
		cin >> baseUrl;
		cout << "The base URL is: " << baseUrl << endl;

		LinkShortener shortener(baseUrl);

		cout << "Please enter the URL to be shortened: ";
		string originalLink;
		cin >> originalLink;

		string shortenedLink = shortener.shortenLink(originalLink);
		cout << "The shortened link is: " << shortenedLink << endl;

		string retrievedLink = shortener.getOriginalLink(shortenedLink);
		if (retrievedLink.empty())
			cout << "Invalid or non-existent shortened link." << endl;
		else
			cout << "The original link is: " << retrievedLink << endl;
	}
	catch (const exception& ex) {
		cout << "Error occurred: " << ex.what() << endl;
	}
	catch (...) {
		cout << "Unknown error occurred." << endl;
	}

	system("pause");

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
