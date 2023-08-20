#include "TUI.hpp"

TUI::TUI() {
	std::clog << "TUI: creating instance" << std::endl;
}

TUI::~TUI() {
	std::clog << "TUI: instance destroyed" << std::endl;
}

TUI::TUI(const TUI & obj) { *this = obj; }

TUI& TUI::operator=(const TUI& obj) {
	(void)obj;
	return *this;
}

TUI* TUI::instance = NULL;

TUI& TUI::getInstance() {
	if (TUI::instance == NULL) {
		TUI::instance = new TUI();
	}
	std::clog << "TUI: returning instance" << std::endl;
	return *TUI::instance;
}

// static bool hasAny(const std::string& set, char c) {
// 	for (unsigned int i = 0; i < set.length(); i++) {
// 		if (set[i] == c) {
// 			return true;
// 		}
// 	}
// 	return false;
// }

static std::string trim(std::string& str) {
	unsigned int start = 0;
	unsigned int end = str.length() - 1;
	while (start < end && iswspace(str[start])) {
		start++;
	}
	while (end > start && iswspace(str[end])) {
		end--;
	}
	return str.substr(start, end - start + 1);
}

/*

		std::string getString(std::string question);
		std::string getString(std::string question, std::string defaultValue);
		std::string getString(std::string question, unsigned int minLength, unsigned int maxLength);
 */

std::string TUI::getString(std::string question) {
	std::string input;
	std::cout << question;
	std::cin >> input;
	return trim(input);
}

std::string TUI::getString(std::string question, unsigned int minLength, unsigned int maxLength) {
	std::string input;
	while (true) {
		input = getString(question);
		if (input.length() < minLength) {
			std::cerr << "The response must be at least " << minLength << " characters long." << std::endl;
		}
		else if (input.length() > maxLength) {
			std::cerr << "The response must be at most " << maxLength << " characters long." << std::endl;
		}
		else {
			break;
		}
	}
	return input;
}
