#include "Publication.h"

Publication::Publication() : year(0)
{
}

Publication::Publication(const std::vector<Person>& authors, const std::string& title, int year)
    : authors(authors), title(title), year(year)
{
}