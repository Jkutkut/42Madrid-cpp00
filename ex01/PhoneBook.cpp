#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {}

PhoneBook::~PhoneBook() {}

PhoneBook::PhoneBook(const PhoneBook & obj) { *this = obj; }

PhoneBook& PhoneBook::operator=(const PhoneBook& obj) {
  (void)obj;
  return *this;
}
