#include "CppUnitTest.h"
#include <sstream>
#include <string>

// Замените "LabWork" на имя вашей папки с основным проектом, если нужно
#include "../Project13/Person.h"
#include "../Project13/Publisher.h"
#include "../Project13/Book.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PublicationUnitTests
{
    TEST_CLASS(PersonTest)
    {
    public:
        TEST_METHOD(BasicAuthor) // Обычный автор
        {
            Person author("Иван", "Иванов", "Иванович");
            std::ostringstream oss;
            oss << author;
            Assert::AreEqual("Иванов И.И.", oss.str().c_str());
        }

        TEST_METHOD(FullEditor) // Редактор с префиксом и постфиксом
        {
            Person editor("Петр", "Петров", "Сергеевич", "Д-р", "Ph.D.");
            std::ostringstream oss;
            oss << editor;
            Assert::AreEqual("Д-р Петров П.С. Ph.D.", oss.str().c_str());
        }

        TEST_METHOD(NoPatronymic) // Автор без отчества
        {
            Person foreignAuthor("Джон", "Смит");
            std::ostringstream oss;
            oss << foreignAuthor;
            Assert::AreEqual("Смит Д.", oss.str().c_str());
        }
    };

    TEST_CLASS(PublisherTest)
    {
    public:
        TEST_METHOD(Normal) // Обычное издательство
        {
            Publisher pub("Просвещение", "Санкт-Петербург");
            std::ostringstream oss;
            oss << pub;
            Assert::AreEqual("Санкт-Петербург : Просвещение", oss.str().c_str());
        }

        TEST_METHOD(EmptyCity) // Без города (должно быть "Б. м.")
        {
            Publisher pub("Иностранка", "");
            std::ostringstream oss;
            oss << pub;
            Assert::AreEqual("Б. м. : Иностранка", oss.str().c_str());
        }
    };

    TEST_CLASS(BookTest)
    {
    public:
        TEST_METHOD(OneAuthor) // Книга с одним автором
        {
            Person author("Александр", "Пушкин", "Сергеевич");
            Person editor("Михаил", "Лермонтов", "Юрьевич");
            Publisher pub("Эксмо", "Москва");

            Book book({ author }, "Стихотворения", 2026, pub, editor);

            std::string expected = "Пушкин А.С. Стихотворения / Пушкин А.С. ; под ред. Лермонтов М.Ю.. – Москва : Эксмо, 2026.";
            Assert::AreEqual(expected.c_str(), book.ToString().c_str());
        }

        TEST_METHOD(ManyAuthors) // Книга с несколькими авторами
        {
            Person author1("Илья", "Ильф", "Арнольдович");
            Person author2("Евгений", "Петров", "Петрович");
            Person editor("Иван", "Иванов", "Иванович");
            Publisher pub("АСТ", "Екатеринбург");

            std::vector<Person> authors = { author1, author2 };
            Book book(authors, "Двенадцать_стульев", 2005, pub, editor);

            std::string expected = "Ильф И.А., Петров Е.П. Двенадцать_стульев / Ильф И.А., Петров Е.П. ; под ред. Иванов И.И.. – Екатеринбург : АСТ, 2005.";
            Assert::AreEqual(expected.c_str(), book.ToString().c_str());
        }

        TEST_METHOD(OutputOperator) // Тест оператора <<
        {
            Person author("Стивен", "Кинг");
            Person editor("Джон", "Доу");
            Publisher pub("Иностранка", "");

            Book book({ author }, "Сияние", 2020, pub, editor);

            std::ostringstream oss;
            oss << book;

            std::string expected = "Кинг С. Сияние / Кинг С. ; под ред. Доу Д.. – Б. м. : Иностранка, 2020.";
            Assert::AreEqual(expected.c_str(), oss.str().c_str());
        }
    };
}