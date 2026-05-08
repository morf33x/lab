#include "Book.h"
#include <sstream>

Book(const std::vector& authors, const std::string& title, const int year,
    const Publisher& publisher, const Person& editor);
    : Publication(authors, title, year), publisher(publisher), editor(editor) {
}

std::string Book::ToString() const
{
    std::ostringstream oss;
    for (size_t i = 0; i < authors.size(); ++i) {
        oss << authors[i];
        if (i != authors.size() - 1) oss << ", ";
    }

    oss << " " << title << " / ";

    for (size_t i = 0; i < authors.size(); ++i) {
        oss << authors[i];
        if (i != authors.size() - 1) oss << ", ";
    }

    oss << " ; под ред. " << editor << ". – " << publisher << ", " << year << ".";
    return oss.str();
}

Book Book::read(std::istream& is)
{
    Book b;
    is >> b;
    return b;
}

std::ostream& operator<<(std::ostream& os, const Book& book)
{
    os << book.ToString();
    return os;
}

std::istream& operator>>(std::istream& is, Book& book)
{
    Person author;
    is >> author;
    book.authors.clear();
    book.authors.push_back(author);
    is >> book.title;
    is >> book.year;
    is >> book.publisher;
    is >> book.editor;

    return is;
}
