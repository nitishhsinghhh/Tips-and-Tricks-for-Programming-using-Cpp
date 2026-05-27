// C++ 26 Link Shortener Implementation
// This implementation uses C++20 features for improved performance and readability.
// It includes a LinkShortener class that generates unique shortened URLs and retrieves original URLs efficiently.
#include <iostream>
#include <string>
#include <string_view>
#include <unordered_map>
#include <random>
#include <vector>
#include <ranges>
#include <algorithm>

class LinkShortener {
private:
    std::unordered_map<std::string, std::string> m_links;
    std::string m_baseUrl;

    std::random_device m_rd;
    std::mt19937 m_generator;

    std::string generateRandomCode(size_t length) {
        constexpr std::string_view characters =
            "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

        std::uniform_int_distribution<size_t> distribution(0, characters.size() - 1);

        std::string code;
        code.reserve(length);

        auto random_char_view =
            std::views::iota(0, static_cast<int>(length))
            | std::views::transform([&](int) {
                return characters[distribution(m_generator)];
            });

        std::ranges::copy(random_char_view, std::back_inserter(code));

        return code;
    }

public:
    explicit LinkShortener(std::string_view baseUrl)
        : m_baseUrl(baseUrl), m_generator(m_rd()) {}

    std::string shortenLink(std::string_view originalLink) {
        std::string shortenedLink;

        do {
            shortenedLink = m_baseUrl + generateRandomCode(6);
        } while (m_links.find(shortenedLink) != m_links.end());

        m_links[shortenedLink] = std::string(originalLink);
        return shortenedLink;
    }

    std::string_view getOriginalLink(std::string_view shortenedLink) const {
        auto it = m_links.find(std::string(shortenedLink));
        if (it != m_links.end()) {
            return it->second;
        }
        return {};
    }
};

int main() {
    const std::string baseUrl = "https://github.com/";
    LinkShortener shortener(baseUrl);

    std::vector<std::string_view> testUrls = {
        "https://example.com/page1",  "https://example.com/page2",
        "https://example.com/page3",  "https://example.com/page4",
        "https://example.com/page5",  "https://example.com/page6",
        "https://example.com/page7",  "https://example.com/page8",
        "https://example.com/page9",  "https://example.com/page10",
        "https://example.com/page11", "https://example.com/page12",
        "https://example.com/page13", "https://example.com/page14",
        "https://example.com/page15", "https://example.com/page16",
        "https://example.com/page17", "https://example.com/page18",
        "https://example.com/page19", "https://example.com/page20"
    };

    std::cout << "Testing 20 URLs with base URL: " << baseUrl << "\n";
    std::cout << "---------------------------------------------\n";

    for (const auto& url : testUrls) {
        std::string shortened = shortener.shortenLink(url);
        std::string_view original = shortener.getOriginalLink(shortened);

        std::cout << "Original URL:  " << url << "\n"
                  << "Shortened URL: " << shortened << "\n"
                  << "Retrieved URL: " << original << "\n";

        if (original != url) {
            std::cout << "ERROR: Retrieved URL does not match original!\n";
        }

        std::cout << "---------------------------------------------\n";
    }

    return 0;
}