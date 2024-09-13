#include "compare.h"
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

//获取相似度
float getSimilarity(const pair<map<string, list<string>>, map<string, message>>& originMsg, 
	const pair<map<string, list<string>>, map<string, message>>& checkMsg)
{
	//拆包拿到子句
	map<string, list<string>> checkSen = checkMsg.first;
	//map<string, list<string>> originSen = originMsg.first;

	//拆包拿到索引
	map<string, message> check = checkMsg.second;
	map<string, message> origin = originMsg.second;

	float copyCount = 0; //抄袭句子计数器
	//const int senSum = check.size(); //索引总数
	auto checkEnd = check.end();
	auto notFound = origin.end(); //用于判断短句在原文中是否存在
	//set<pair<原句, 疑似抄袭句>>
	set<pair<string, string>> suspect; //疑似抄袭的句子列

	//遍历查重文章，填充疑似抄袭的句子列
	for (auto it = check.begin(); it != checkEnd; it++) 
	{
		string checkShortSen = it->first; //要找的短句
		auto result = origin.find(checkShortSen); //查找结果
		if (result != notFound) //查到索引，疑似抄袭
		{
			pair<string, string> doubt(result->second.text, it->second.text);
			suspect.insert(doubt);
		}
	}

	//遍历怀疑列，决定是否抄袭
	auto doubtEnd = suspect.end();
	for (auto it = suspect.begin(); it != doubtEnd; it++)
	{
		if (isCopied(it->first, it->second))
		{
			copyCount++;
		}
	}
	return copyCount / checkSen.begin()->second.size();
}

//定义是否抄袭
bool isCopied(const string& originText, const string& checkSen)
{
	int copyCount = LCS(originText, checkSen);
	int chCharSize = 2;
	int checkSenCharCount = checkSen.size() / chCharSize;
	return 2 * copyCount > checkSenCharCount; //重复超过一半算抄袭
}

//查找公共字字数
int LCS(const string& originText, const string& checkSen)
{
	int chCharSize = 2;
	int checkSenCharCount = checkSen.size() / chCharSize;
	int originTextCharCount = originText.size() / chCharSize;
	//定义动态规划的二维表
	int** table = new int*[checkSenCharCount + 1];
	for (size_t i = 0; i < checkSenCharCount + 1; i++)
	{
		table[i] = new int[originTextCharCount + 1] {0};
	}
	//动态规划
	for (int i = 1; i <= checkSenCharCount; i++)
	{
		for (int j = 1; j <= originTextCharCount; j++)
		{
			if (checkSen[chCharSize * (i - 1)] == originText[chCharSize * (j - 1)] &&
				checkSen[chCharSize * (i - 1) + 1] == originText[chCharSize * (j - 1) + 1])
			{
				table[i][j] = table[i - 1][j - 1] + 1;
			}
			else
			{
				table[i][j] = max(table[i - 1][j], table[i][j - 1]);
			}
			//cout << table[i][j] << " ";
		}
		//cout << endl;
	}
	/*for (size_t i = 0; i < checkSenCharCount + 1; i++)
	{
		for (size_t j = 0; j < originTextCharCount + 1; j++)
		{
			cout << table[i][j] << " ";
		}
		cout << endl;
	}*/
	int sameCount = table[checkSenCharCount][originTextCharCount];
	//释放空间
	for (size_t i = 0; i < checkSenCharCount + 1; i++)
	{
		delete[] table[i];
	}
	delete[] table;
	return sameCount;
}