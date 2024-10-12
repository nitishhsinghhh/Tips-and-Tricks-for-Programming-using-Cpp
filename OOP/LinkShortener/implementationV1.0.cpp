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
	string baseUrl = "https://www.linkedin.com/in/";
	LinkShortener shortener(baseUrl);

	string originalLink = "https://www.linkedin.com/in/nitishsingh47/";
	string shortenedLink = shortener.shortenLink(originalLink);
	cout << "Shortened link: " << shortenedLink << endl;

	string retrievedLink = shortener.getOriginalLink(shortenedLink);
	if (!retrievedLink.empty()) 
		cout << "Original link: " << retrievedLink << endl;
	else 
		cout << "Invalid or non-existent shortened link." << endl;

	return 0;
}
