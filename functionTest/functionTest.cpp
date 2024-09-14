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
			string str = "��";
			list<string> *indexList = &cut7CharIndex(str);
			bool result = (indexList->size() == 1);
			delete indexList;
			Assert::AreEqual(true, result);
		}

		TEST_METHOD(TestCut7CharIndex_TwoCharLowerFour_ReturnOneElement)
		{
			string str = "���";
			list<string> *indexList = &cut7CharIndex(str);
			bool result = (indexList->size() == 1);
			delete indexList;
			Assert::AreEqual(true, result);
		}

		TEST_METHOD(TestCut7CharIndex_ThreeCharLowerFour_ReturnOneElement)
		{
			string str = "�㻹��";
			list<string> *indexList = &cut7CharIndex(str);
			bool result = (indexList->size() == 1);
			delete indexList;
			Assert::AreEqual(true, result);
		}

		TEST_METHOD(TestCut7CharIndex_FourChar_ReturnOneElement)
		{
			string str = "�㻹����";
			list<string> *indexList = &cut7CharIndex(str);
			bool result = (indexList->size() == 1);
			delete indexList;
			Assert::AreEqual(true, result);
		}

		TEST_METHOD(TestCut7CharIndex_FiveChar_ReturnTwo)
		{
			string str = "����ȥ�㳡";
			list<string> *indexList = &cut7CharIndex(str);
			bool result = (indexList->size() == 2);
			delete indexList;
			Assert::AreEqual(true, result);
		}

		TEST_METHOD(TestCut7CharIndex_SixChar_ReturnThree)
		{
			string str = "����ȥ�㳡��";
			list<string> *indexList = &cut7CharIndex(str);
			bool result = (indexList->size() == 3);
			delete indexList;
			Assert::AreEqual(true, result);
		}

		TEST_METHOD(TestCut7CharIndex_SevenChar_ReturnFour)
		{
			string str = "���컹ȥ�㳡��";
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
			//׼������
			string articleName = "No1";
			string sen1 = "���յ����������˴��";
			string sub1[] = {
				"���յ���", "�յ�����", "��������", "��������",
			"��������", "�����˴�", "���˴��" };

			string sen2 = "��������ů������";
			string sub2[] = { "��������" , "������ů" , "����ů��" ,
			"��ů����" , "ů������" };

			string sen3 = "������һ�����ѵ�С��ɢ��";
			string sub3[] = { "������һ", "����һ��", "��һ����", "һ������",
				"�����ѵ�", "���ѵ�С", "�ѵ�С��", "��С��ɢ","С��ɢ��" };

			list<string> senList;
			senList.push_back(sen1);
			senList.push_back(sen2);
			senList.push_back(sen3);

			pair<string, list<string>> pair(articleName, senList);
			map<string, list<string>> sentences;
			sentences.insert(pair);

			//�̾����б�
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
			string sen4 = "���ĵ�";
			string sen5 = "������";
			string sen6 = "��������";

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
			string punctuation = "��������������";
			string sen = "������Ȼ��������������ů������͸��յĴ�ء������ڹ�԰�ﾺ�࿪�ţ�ɫ�ʰ�쵣��������۷�ͺ������������ڲݵ��ϻ�Ц��׷����Ʈ��ķ��ݡ�";
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
			string punctuation = "��������������";
			string sen = "������Ȼ��������������ů������͸��յĴ�ء������ڹ�԰�ﾺ�࿪�ţ�ɫ�ʰ�쵣��������۷�ͺ������������ڲݵ��ϻ�Ц��׷����Ʈ��ķ��ݡ�";
			list<string> *subSentences = &divideParagraph(sen, punctuation);
			string sub[] = {"������Ȼ����",
				"��������ů������͸��յĴ��", 
				"�����ڹ�԰�ﾺ�࿪��", 
				"ɫ�ʰ��", 
				"�������۷�ͺ���", 
				"�������ڲݵ��ϻ�Ц",
				"׷����Ʈ��ķ���"
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
