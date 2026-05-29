#include "CppUnitTest.h"
#include <string>

#include "../Project42/CircularList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CircularListUnitTests
{
    TEST_CLASS(CircularListTest)
    {
    public:
        TEST_METHOD(CreationAndOutput)
        {
            CircularList lst{ 5, 10, 15 };

            Assert::IsFalse(lst.empty());
            Assert::AreEqual((size_t)3, lst.length());
            Assert::AreEqual("[5, 10, 15]", lst.asString().c_str());
        }

        TEST_METHOD(AppendAndPrepend)
        {
            CircularList lst;

            lst.prepend(100);
            lst.append(200);
            lst.prepend(50);

            Assert::AreEqual((size_t)3, lst.length());
            Assert::AreEqual("[50, 100, 200]", lst.asString().c_str());
        }

        TEST_METHOD(InsertionAndDeletion)
        {
            CircularList lst{ 7, 14, 21 };

            lst.insert(1, 10);
            Assert::AreEqual("[7, 10, 14, 21]", lst.asString().c_str());

            lst.eraseAt(2);
            Assert::AreEqual("[7, 10, 21]", lst.asString().c_str());

            Assert::IsTrue(lst.eraseValue(7));
            Assert::AreEqual("[10, 21]", lst.asString().c_str());
        }

        TEST_METHOD(SearchAndReplace)
        {
            CircularList lst{ 11, 22, 33 };

            Assert::AreEqual(1, lst.indexOf(22));
            Assert::AreEqual(-1, lst.indexOf(99));

            Assert::IsTrue(lst.replace(33, 44));
            Assert::IsFalse(lst.replace(100, 200));

            Assert::AreEqual("[11, 22, 44]", lst.asString().c_str());
        }

        TEST_METHOD(CyclicShifts)
        {
            CircularList lst{ 1, 2, 3, 4 };

            lst <<= 2;
            Assert::AreEqual("[3, 4, 1, 2]", lst.asString().c_str());

            lst >>= 1;
            Assert::AreEqual("[2, 3, 4, 1]", lst.asString().c_str());
        }

        TEST_METHOD(CopyAndMove)
        {
            CircularList original{ 9, 8, 7 };
            CircularList copied(original);

            copied.set(0, 99);

            Assert::AreEqual("[9, 8, 7]", original.asString().c_str());
            Assert::AreEqual("[99, 8, 7]", copied.asString().c_str());

            CircularList moved(std::move(copied));

            Assert::AreEqual("[99, 8, 7]", moved.asString().c_str());

        }
    };
TEST_CLASS(NodeTest)
{
public:
    TEST_METHOD(DefaultConstructor)
    {
        Node node;

        Assert::AreEqual(0, node.getValue());
        Assert::IsNull(node.getNext());
    }

    TEST_METHOD(ParameterizedConstructor)
    {
        Node nextNode(55);
        Node node(42, &nextNode);

        Assert::AreEqual(42, node.getValue());
        Assert::IsTrue(&nextNode == node.getNext());
    }
    TEST_METHOD(SettersAndGetters)
    {
        Node node;
        Node dummyNode;

        node.setValue(99);
        node.setNext(&dummyNode);

        Assert::AreEqual(99, node.getValue());
        Assert::IsTrue(&dummyNode == node.getNext());
    }
    TEST_METHOD(LinkingNodes)
    {
        Node first(10);
        Node second(20);
        Node third(30);

        first.setNext(&second);
        second.setNext(&third);

        Assert::AreEqual(20, first.getNext()->getValue());
        Assert::AreEqual(30, first.getNext()->getNext()->getValue());
    }
};
}
