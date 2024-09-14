#include "pch.h"
#include "CppUnitTest.h"
#include "D:\VS2017data\DuplicateCheck\DuplicateCheck\compare.h"
#include "D:\VS2017data\DuplicateCheck\DuplicateCheck\message.h"
#include "D:\VS2017data\DuplicateCheck\DuplicateCheck\function.h"
#include "D:\VS2017data\DuplicateCheck\DuplicateCheck\output.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace functionTest
{
	TEST_CLASS(cut7CharIndexTest)
	{
	public:

		TEST_METHOD(TestCut7CharIndex_EmptyString_ReturnEmptyList)
		{
			string emptyStr = "";
			list<string> *indexList = &cut7CharIndex(emptyStr);
			bool result = indexList->empty();
			delete indexList;
			Assert::AreEqual(true, result);
		}

		TEST_METHOD(TestCut7CharIndex_OneCharLowerFour_ReturnOneElement)
		{
			string str = "你";
			list<string> *indexList = &cut7CharIndex(str);
			bool result = (indexList->size() == 1);
			delete indexList;
			Assert::AreEqual(true, result);
		}

		TEST_METHOD(TestCut7CharIndex_TwoCharLowerFour_ReturnOneElement)
		{
			string str = "你好";
			list<string> *indexList = &cut7CharIndex(str);
			bool result = (indexList->size() == 1);
			delete indexList;
			Assert::AreEqual(true, result);
		}

		TEST_METHOD(TestCut7CharIndex_ThreeCharLowerFour_ReturnOneElement)
		{
			string str = "你还好";
			list<string> *indexList = &cut7CharIndex(str);
			bool result = (indexList->size() == 1);
			delete indexList;
			Assert::AreEqual(true, result);
		}

		TEST_METHOD(TestCut7CharIndex_FourChar_ReturnOneElement)
		{
			string str = "你还好吗";
			list<string> *indexList = &cut7CharIndex(str);
			bool result = (indexList->size() == 1);
			delete indexList;
			Assert::AreEqual(true, result);
		}

		TEST_METHOD(TestCut7CharIndex_FiveChar_ReturnTwo)
		{
			string str = "今天去广场";
			list<string> *indexList = &cut7CharIndex(str);
			bool result = (indexList->size() == 2);
			delete indexList;
			Assert::AreEqual(true, result);
		}

		TEST_METHOD(TestCut7CharIndex_SixChar_ReturnThree)
		{
			string str = "今天去广场吗";
			list<string> *indexList = &cut7CharIndex(str);
			bool result = (indexList->size() == 3);
			delete indexList;
			Assert::AreEqual(true, result);
		}

		TEST_METHOD(TestCut7CharIndex_SevenChar_ReturnFour)
		{
			string str = "今天还去广场吗";
			list<string> *indexList = &cut7CharIndex(str);
			bool result = (indexList->size() == 4);
			delete indexList;
			Assert::AreEqual(true, result);
		}
	};

	TEST_CLASS(make7CharMapTest)
	{
	public:
		
	};

	TEST_CLASS(findPounIndexTest)
	{
	public:

	};

	TEST_CLASS(divideParagraphTest)
	{
	public:

	};

	TEST_CLASS(divideArticleTest)
	{
	public:

	};
}
