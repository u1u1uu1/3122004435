#include "function.h"
#include "message.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>

using namespace std;

//Ԥ����
//pair<�־�map, ����map>;
pair<map<string, list<string>>, map<string, message>>& pretreatment(const string& filepath)
{
	//���·ֳ��Ӿ�
	map<string, list<string>> *sentences = &divideArticle(filepath);
	//�־䴴������
	map<string, message> *index = &make7CharMap(*sentences);
	//�־�������������
	pair<map<string, list<string>>, map<string, message>> *msg =
		new pair<map<string, list<string>>, map<string, message>>(*sentences, *index);
	//�ͷŸ���
	delete sentences;
	delete index;
	return *msg;
}

//�־�
map<string, list<string>>& divideArticle(const string filepath)
{
	ifstream ifs;
	ifs.open(filepath, ios::in);

	list<string> *sentences = new list<string>();
	char buf[1024] = { 0 };
	while (ifs.getline(buf, sizeof(buf))) {
		if(buf[0] == '\0') 
		{
			continue;
		}
		//ȥ��ͷ���ո�
		string sen(buf);
		sen.erase(0, sen.find_first_not_of(" "));
		//������Ϊ�Ӿ�
		//regex regexPattern(R"([��,������������]+|����)");
		string punctuation = "��������������";
		list<string> *subSentences = &divideParagraph(sen, punctuation);
		//�־����list
		sentences->insert(sentences->end(), subSentences->begin(), subSentences->end());
		delete subSentences;
		//cout << buf << endl;
	}
	//
	ifs.close();
	map<string, list<string>> *senMap = new map<string, list<string>>();
	//��·����ȡ���ļ���
	string articleName(filepath);
	articleName.erase(0, filepath.find_last_of("\\") + 1);
	senMap->insert(pair<string, list<string>>(articleName, *sentences));
	return *senMap;
}

//�����Ȼ��
list<string>& divideParagraph(const string& str, const string& seperator)
{
	list<string> *subSentences = new list<string>;
	//�ҵ����б����±�
	set<int> spiltIndex;
	findPounIndex(str, seperator, spiltIndex);
	//�ָ��Ӿ�
	if (spiltIndex.empty() == true)
	{
		subSentences->push_back(str);
		return *subSentences;
	}
	auto indexEnd = spiltIndex.end();
	int lastIndex = 0;
	for (auto it = spiltIndex.begin(); it != indexEnd; it++)
	{
		string subSen = str.substr(lastIndex, *it - lastIndex);
		if (subSen == "")
		{
			lastIndex += 2;
			continue;
		}
		subSentences->push_back(str.substr(lastIndex, *it - lastIndex));
		lastIndex = *it + 2;
	}
	return *subSentences;
}

//���ұ���±�
void findPounIndex(const string& str, const string& seperator, set<int>& set)
{
	//���ּ��
	for (size_t i = 0; i < str.size(); i += 2)
	{
		//������
		for (size_t j = 0; j < seperator.size(); j += 2)
		{
			if (str[i] == seperator[j] && str[i + 1] == seperator[j + 1])
			{
				set.insert(i);
				break;
			}
		}
	}
}

//������������
map<string, message>& make7CharMap(const map<string, list<string>>& sentences)
{
	string articleName(sentences.begin()->first);//ȡ��������
	list<string> subSen(sentences.begin()->second);//ȡ�������Ӿ�
	//�����Ӿ䣬��������
	auto end = subSen.end();
	map<string, message> *index = new map<string, message>();
	for(auto it = subSen.begin(); it != end; it++)
	{
		list<string> *senList = &cut7CharIndex(*it);
		message msg(articleName, *it);
		auto slEnd = senList->end();
		for (auto slIt = senList->begin(); slIt != slEnd; slIt++)
		{
			pair<string, message> p(*slIt, msg);
			index->insert(p);
		}
		delete senList;
	}
	return *index;
}

//�������ڽ�ȡ4������
list<string>& cut7CharIndex(const string& subSen) 
{
	list<string> *sevenIndex = new list<string>;
	int indexCharCount = 4;
	int ansiChCharSize = 2;
	//���ַ���ֱ�ӷ���
	if (subSen.size() == 0)
	{
		return *sevenIndex;
	}
	//С�ڵ���7����ֱ�ӷ���
	if (subSen.size() <= indexCharCount * ansiChCharSize)
	{
		sevenIndex->push_back(subSen);
		return *sevenIndex;
	}
	//�������ڽ�ȡ�Ӵ�
	for (int i = 0; i <= subSen.size() - indexCharCount * ansiChCharSize; i += ansiChCharSize)
	{
		sevenIndex->push_back(string(subSen).substr(i, indexCharCount * ansiChCharSize));
	}
	return *sevenIndex;
}