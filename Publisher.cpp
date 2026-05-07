#include "Publisher.h"

Publisher::Publisher() : name(""), city("") {}

Publisher::Publisher(const std::string& name, const std::string& city) : name(name), city(city) {}

std::ostream& operator<<(std::ostream& os, const Publisher& pub)
{
    // Если город не указан, пишем "Б. м." (Без места)
    std::string displayCity = pub.city.empty() ? "Б. м." : pub.city;
    os << displayCity << " : " << pub.name;
    return os;
}

std::istream& operator>>(std::istream& is, Publisher& pub)
{
    std::cout << "Введите город издания: ";
    is >> pub.city;
    std::cout << "Введите название издательства: ";
    is >> pub.name;
    return is;
}