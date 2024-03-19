#include <iostream>
#include <string>
#include <unordered_map>
#include <random>

class LinkShortener {
private:
	std::unordered_map<std::string, std::string> links;
	std::string base_url;

	std::string generateRandomCode(int length) {
		const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
		std::random_device rd;
		std::mt19937 generator(rd());
		std::uniform_int_distribution<int> distribution(0, characters.size() - 1);
		std::string code;
		for (int i = 0; i < length; ++i)
			code += characters[distribution(generator)];
		return code;
	}

public:
	LinkShortener(const std::string& baseUrl) : base_url(baseUrl) {}

	std::string shortenLink(const std::string& originalLink) {
		std::string shortCode;

		do {
			shortCode = generateRandomCode(6);
		} while (links.find(base_url + shortCode) != links.end());

		std::string shortenedLink = base_url + shortCode;
		links[shortenedLink] = originalLink;

		return shortenedLink;
	}

	std::string getOriginalLink(const std::string& shortenedLink) {
		if (links.find(shortenedLink) != links.end())
			return links[shortenedLink];

		return ""; // Return empty std::string if the shortened link doesn't exist
	}
};

int main() {
	std::string baseUrl = "https://www.linkedin.com/in/";
	LinkShortener shortener(baseUrl);

	std::string originalLink = "https://www.linkedin.com/in/nitishsingh47/";
	std::string shortenedLink = shortener.shortenLink(originalLink);
	std::cout << "Shortened link: " << shortenedLink << std::endl;

	std::string retrievedLink = shortener.getOriginalLink(shortenedLink);
	if (!retrievedLink.empty())
		std::cout << "Original link: " << retrievedLink << std::endl;
	else
		std::cout << "Invalid or non-existent shortened link." << std::endl;

	return 0;
}
