#include "function.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>

extern string originTextPath;
extern string copyTextPath;
extern string outputPath;

using namespace std;

//预处理
void pretreatment()
{
	map<string, list<string>> sentences;
	sentences = divideArticle(originTextPath);

}

//分句
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
		//去除头部空格
		string sen(buf);
		sen.erase(0, sen.find_first_not_of(" "));
		//按标点分为子句
		//regex regexPattern(R"([：,；“”！？、]+|——)");
		string punctuation = "，。“”——、";
		list<string> subSentences = divideParagraph(sen, punctuation);
		//字句插入list
		sentences->insert(sentences->end(), subSentences.begin(), subSentences.end());
		cout << buf << endl;
	}
	//
	ifs.close();
	map<string, list<string>> *senMap = new map<string, list<string>>();
	senMap->insert(pair<string, list<string>>(originTextPath, *sentences));
	return *senMap;
}

//拆分自然段
list<string>& divideParagraph(const string& str, const string& seperator)
{
	list<string> *subSentences = new list<string>;
	//找到所有标点的下标
	set<int> spiltIndex;
	findPounIndex(str, seperator, spiltIndex);
	//分割子句
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

//查找标点下标
void findPounIndex(const string& str, const string& seperator, set<int>& set)
{
	//逐字检查
	for (size_t i = 0; i < str.size(); i += 2)
	{
		//逐标点检查
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

//建立倒排索引
map<string, list<string>>& make7CharMap(const map<string, list<string>>& sentences)
{

	map<string, list<string>> *index = new map<string, list<string>>();
	return *index;
}