#include <iostream>
#include <vector>
#include "Book.h"

int main()
{
    setlocale(LC_ALL, "RU");

    std::vector<Publication*> publications;

    Person author("Иван", "Иванов", "Иванович");
    Person editor("Петр", "Петров", "Сергеевич", "Д-р", "Ph.D.");
    Publisher pub("Просвещение", "Москва");
    Book* book1 = new Book({ author }, "Книга", 2026, pub, editor);
    publications.push_back(book1);
    for (const auto& p : publications)
    {
        std::cout << p->ToString() << "\n" << std::endl;
    }

    for (auto p : publications)
    {
        delete p;
    }

    return 0;
}