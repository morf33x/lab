#include "Person.h"

int Person::counter = 1;

Person::Person() : id(counter++), firstName(""), lastName(""), patronymic(""), prefix(""), postfix("") {}

Person::Person(const std::string& firstName, const std::string& lastName,
    const std::string& patronymic, const std::string& prefix, const std::string& postfix)
    : id(counter++)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->patronymic = patronymic;
    this->prefix = prefix;
    this->postfix = postfix;
}

int Person::getId() const
{
    return id;
}

std::ostream& operator<<(std::ostream& os, const Person& person)
{
    if (!person.prefix.empty()) os << person.prefix << " ";
    os << person.lastName << " " << (!person.firstName.empty() ? person.firstName.substr(0, 1) + "." : "");
    if (!person.patronymic.empty()) os << person.patronymic.substr(0, 1) << ".";
    if (!person.postfix.empty()) os << " " << person.postfix;

    return os;
}

std::istream& operator>>(std::istream& is, Person& person)
{
    is >> person.lastName >> person.firstName >> person.patronymic;
    return is;
}
