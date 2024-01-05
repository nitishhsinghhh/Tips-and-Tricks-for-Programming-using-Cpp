#include <iostream>
#include <string>
#include <sstream>
#include<cctype>

// Enum to represent different types of string conversions
enum ConversionType {
	CT_LowerCase,
	CT_UpperCase,
	CT_Capitalize,
	CT_SentenceCase,
	CT_ToggleCase
};

// Abstract base class for string conversions
class StringConversion {
public:
	virtual std::string convertString(std::string s) = 0;	// pure virtual class
	virtual ~StringConversion() {}
};

// Library Classes

// Converts the string to lowercase
class ClasstoLowerCase : public StringConversion {
public:
	std::string convertString(std::string s) {
		for (auto& c : s)
			if ('A' <= c && c <= 'Z')
				c = c - 'A' + 'a';
		return s;
	}
};

// Converts the std::string to uppercase
class ClasstoUpperCase : public StringConversion {
public:
	std::string convertString(std::string s) {
		for (auto& c : s)
			if ('a' <= c && c <= 'z')
				c = c - 'a' + 'A';
		return s;
	}
};

// Capitalizes each word in the std::string
class ClasscapitalizeEachWord : public StringConversion {
public:
	std::string convertString(std::string s) {
		std::istringstream iss(s);
		std::string result, word;
		while (iss >> word) {
			if (!result.empty())
				result += ' ';
			word[0] = toupper(word[0]);
			for (size_t i = 1; i < word.length(); ++i)
				word[i] = tolower(word[i]);
			result += word;
		}
		return result;
	}
};

// Converts the std::string to sentence case (first letter uppercase, rest lowercase)
class ClasstoSentenceCase : public StringConversion {
public:
	std::string convertString(std::string s) {
		if (!s.empty()) {
			s[0] = toupper(s[0]);
			for (size_t i = 1; i < s.length(); ++i)
				s[i] = tolower(s[i]);
		}
		return s;
	}
};

// Toggles the case of each character in the std::string
class ClasstoggleCase : public StringConversion {
public:
	std::string convertString(std::string s) {
		for (auto& c : s) {
			if (islower(c))
				c = toupper(c);
			else if (isupper(c))
				c = tolower(c);
		}
		return s;
	}
};

// Factory class for creating StringConversion objects based on ConversionType
class StringConversionFactory {
public:
	static StringConversion* createStringConversion(ConversionType conversionType) {
		switch (conversionType) {
		case CT_LowerCase:
			return new ClasstoLowerCase();
		case CT_UpperCase:
			return new ClasstoUpperCase();
		case CT_Capitalize:
			return new ClasscapitalizeEachWord();
		case CT_SentenceCase:
			return new ClasstoSentenceCase();
		case CT_ToggleCase:
			return new ClasstoggleCase();
		default:
			return nullptr;
		}
	}
};

// Client class to use the StringConversion objects
class Client {
public:
	Client() : pstringConversion(nullptr) {}

	void BuildStringConversion(ConversionType conversionType) {
		StringConversionFactory* scf = new StringConversionFactory();
		pstringConversion = scf->createStringConversion(conversionType);

		delete scf;
	}

	~Client() {
		if (pstringConversion) {
			delete pstringConversion;
			pstringConversion = nullptr;
		}
	}

	StringConversion* getConversionType() { return pstringConversion; }

private:
	StringConversion* pstringConversion;
};
int main() {

	// Create a Client object
	Client* pClient = new Client();

	// Input strings
	std::string input = "";
	std::cout << "Please provide the input std::string for conversion" << std::endl;
	std::getline(std::cin, input);

	std::cout << "Please slelect the conversion type. The default is lower case. " << std::endl;
	std::cout << "1 for Lower Case, 2 for Upper Case, 3 for Sentence Case, 4 for Capitalize, 5 for toggle case" << std::endl;
	int ConversionType = 0;
	std::cin >> ConversionType;

	if (ConversionType > 0 && ConversionType < 6) {
		switch (ConversionType) {
		case 1:
			pClient->BuildStringConversion(CT_LowerCase);
			std::cout << "Lower Case : " << pClient->getConversionType()->convertString(input) << std::endl;
			break;
		case 2:
			pClient->BuildStringConversion(CT_UpperCase);
			std::cout << "Upper Case : " << pClient->getConversionType()->convertString(input) << std::endl;
			break;
		case 3:
			pClient->BuildStringConversion(CT_SentenceCase);
			std::cout << "Sentence Case : " << pClient->getConversionType()->convertString(input) << std::endl;
			break;
		case 4:
			pClient->BuildStringConversion(CT_Capitalize);
			std::cout << "Capitalize : " << pClient->getConversionType()->convertString(input) << std::endl;
			break;
		case 5:
			pClient->BuildStringConversion(CT_ToggleCase);
			std::cout << "Toggle Case : " << pClient->getConversionType()->convertString(input) << std::endl;
			break;
		default:
			break;
		}

	}
	delete pClient;
	system("pause");
	return 0;
}
