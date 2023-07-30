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
