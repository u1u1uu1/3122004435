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
		TEST_METHOD(make7CharMapTest_Normal_Return)
		{
			//准备参数
			string articleName = "No1";
			string sen1 = "春日的阳光洒满了大地";
			string sub1[] = {
				"春日的阳", "日的阳光", "的阳光洒", "阳光洒满",
			"光洒满了", "洒满了大", "满了大地" };

			string sen2 = "带来了温暖和生机";
			string sub2[] = { "带来了温" , "来了温暖" , "了温暖和" ,
			"温暖和生" , "暖和生机" };

			string sen3 = "我沿着一条蜿蜒的小径散步";
			string sub3[] = { "我沿着一", "沿着一条", "着一条蜿", "一条蜿蜒",
				"条蜿蜒的", "蜿蜒的小", "蜒的小径", "的小径散","小径散步" };

			list<string> senList;
			senList.push_back(sen1);
			senList.push_back(sen2);
			senList.push_back(sen3);

			pair<string, list<string>> pair(articleName, senList);
			map<string, list<string>> sentences;
			sentences.insert(pair);

			//短句检测列表
			list<string> examineList;
			for (int i = 0; i < 7; i++)
			{
				examineList.push_back(sub1[i]);
			}
			for (int i = 0; i < 5; i++)
			{
				examineList.push_back(sub3[i]);
			}
			for (int i = 0; i < 9; i++)
			{
				examineList.push_back(sub3[i]);
			}

			map<string, message> *index = &make7CharMap(sentences);
			auto mapEnd = index->end();
			auto listEnd = examineList.end();
			bool flag = true;
			for (auto it = examineList.begin(); it != listEnd; it++)
			{
				if (index->find(*it) == mapEnd)
				{
					flag = false;
					break;
				}
			}
			if (index->size() != 21)
			{
				flag = false;
			}
			delete index;
			Assert::AreEqual(true, flag);
		}

		TEST_METHOD(make7CharMapTest_Lower_Return)
		{
			string articleName = "No2";
			string sen4 = "悄悄地";
			string sen5 = "静静地";
			string sen6 = "春天来了";

			list<string> senList;
			senList.push_back(sen4);
			senList.push_back(sen5);
			senList.push_back(sen6);

			pair<string, list<string>> pair(articleName, senList);
			map<string, list<string>> sentences;
			sentences.insert(pair);

			list<string> examineList;
			examineList.push_back(sen4);
			examineList.push_back(sen5);
			examineList.push_back(sen6);

			map<string, message> *index = &make7CharMap(sentences);
			auto mapEnd = index->end();
			auto listEnd = examineList.end();
			bool flag = true;
			for (auto it = examineList.begin(); it != listEnd; it++)
			{
				if (index->find(*it) == mapEnd)
				{
					flag = false;
					break;
				}
			}
			if (index->size() != 3)
			{
				flag = false;
			}
			delete index;
			Assert::AreEqual(true, flag);
		}
	};

	TEST_CLASS(findPounIndexTest)
	{
	public:
		TEST_METHOD(findPounIndexTest_Normal_Return)
		{
			string punctuation = "，。“”——、";
			string sen = "春天悄然而至，带来了温暖的阳光和复苏的大地。花儿在公园里竞相开放，色彩斑斓，吸引着蜜蜂和蝴蝶。孩子们在草地上欢笑，追逐着飘扬的风筝。";
			list<int> pounOnder;
			pounOnder.push_back(6);
			pounOnder.push_back(21);
			pounOnder.push_back(32);
			pounOnder.push_back(37);
			pounOnder.push_back(46);
			pounOnder.push_back(56);
			pounOnder.push_back(65);

			set<int> result;
			findPounIndex(sen, punctuation, result);

			auto i = pounOnder.begin();
			auto j = result.begin();
			bool flag = true;
			for (; i != pounOnder.end() ; i++, j++)
			{
				if ((*i) * 2 != *j)
				{
					flag = false;
					break;
				}
			}
			Assert::AreEqual(true, flag);
		}
	};

	TEST_CLASS(divideParagraphTest)
	{
	public:
		TEST_METHOD(divideParagraphTest_Normal_Return)
		{
			string punctuation = "，。“”——、";
			string sen = "春天悄然而至，带来了温暖的阳光和复苏的大地。花儿在公园里竞相开放，色彩斑斓，吸引着蜜蜂和蝴蝶。孩子们在草地上欢笑，追逐着飘扬的风筝。";
			list<string> *subSentences = &divideParagraph(sen, punctuation);
			string sub[] = {"春天悄然而至",
				"带来了温暖的阳光和复苏的大地", 
				"花儿在公园里竞相开放", 
				"色彩斑斓", 
				"吸引着蜜蜂和蝴蝶", 
				"孩子们在草地上欢笑",
				"追逐着飘扬的风筝"
			};

			bool flag = true;
			int i = 0;
			for (auto it = subSentences->begin(); it != subSentences->end(); it++) 
			{
				if (sub[i] != *it)
				{
					flag = false;
					break;
				}
				i++;
			}
			delete subSentences;
			Assert::AreEqual(true, flag);
		}
	};
}
