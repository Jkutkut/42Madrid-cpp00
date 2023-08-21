#include "TUI.hpp"

TUI::TUI() {
	#ifdef DEBUG
	std::clog << "TUI: creating instance" << std::endl;
	#endif
}

TUI::~TUI() {
	#ifdef DEBUG
	std::clog << "TUI: instance destroyed" << std::endl;
	#endif
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
	#ifdef DEBUG
	std::clog << "TUI: returning instance" << std::endl;
	#endif
	return *TUI::instance;
}

// -------------- STRING --------------

static std::string trim(std::string& str) {
	unsigned int start;
	unsigned int end;

	if (str.length() == 0) {
		return str;
	}
	start = 0;
	end = str.length() - 1;
	while (start < end && iswspace(str[start])) {
		start++;
	}
	while (end > start && iswspace(str[end])) {
		end--;
	}
	return str.substr(start, end - start + 1);
}

std::string TUI::getString(std::string question) {
	std::string input;
	std::cout << question;
	std::getline(std::cin, input);
	return trim(input);
}

std::string TUI::getString(std::string question, std::string defaultValue) {
	std::string input = getString(question);
	if (input.length() == 0) {
		return defaultValue;
	}
	return input;
}

std::string TUI::getString(std::string question, unsigned int minLength) {
	return getString(question, minLength, __INT_MAX__);
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

static bool isSpanishPhone(std::string str) {
	unsigned int	i = 0;
	unsigned int	j = 0;

	#ifdef DEBUG
	std::clog << "TUI: isSpanishPhone(" << str << ")" << std::endl;
	#endif
	if (str.length() < 9)
		return false;
	if (str.compare(0, 3, "+34") == 0)
		i += 3;
	while (j < 9 && i < str.length()) {
		if (str.compare(i, 1, " ") == 0)
			i++;
		while (i < str.length() && isdigit(str[i++]))
			j++;
	}
	return (j == 9 && i == str.length());
}

std::string TUI::getSpanishPhone(std::string question) {
	std::string input;
	while (true) {
		input = getString(question);
		if (!isSpanishPhone(input)) {
			std::cerr << "The response must be a valid Spanish phone number.";
			std::cerr << " Regex: (\\+34)? ?\\d{3} ?\\d{3} ?\\d{3}" << std::endl;
		}
		else {
			break;
		}
	}
	return input;
}

// -------------- INT --------------

int TUI::getInt(std::string question) {
	int input = 0;
	std::cout << question;
	while (!(std::cin >> input)) {
		std::cin.clear(); // clear the error flags
		std::cin.ignore(__INT_MAX__, '\n'); // discard the row
		std::cerr << "The response must be an integer." << std::endl;
		std::cout << question;
	}
	return input;
}

int TUI::getInt(std::string question, int minValue) {
	return getInt(question, minValue, __INT_MAX__);
}

int TUI::getInt(std::string question, int minValue, int maxValue) {
	int input;
	while (true) {
		input = getInt(question);
		if (input < minValue) {
			std::cerr << "The response must be at least " << minValue << "." << std::endl;
		}
		else if (input > maxValue) {
			std::cerr << "The response must be at most " << maxValue << "." << std::endl;
		}
		else {
			break;
		}
	}
	return input;
}
