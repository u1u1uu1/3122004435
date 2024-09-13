#include "compare.h"
#include <iostream>

using namespace std;

//获取相似度
float getSimilarity(const pair<map<string, list<string>>, map<string, message>>& originMsg, 
	const pair<map<string, list<string>>, map<string, message>>& checkMsg)
{
	map<string, message> check = checkMsg.second;
	map<string, message> origin = originMsg.second;
	float copyScore = 0; //抄袭句子计分器
	const int senSum = check.size(); //索引总数
	auto checkEnd = check.end();
	auto notFound = origin.end(); //用于判断短句在原文中是否存在
	//遍历查重文章，列出疑似抄袭的句子列表
	for (auto it = check.begin(); it != checkEnd; it++) 
	{
		string checkShortSen = it->first; //要找的短句
		auto result = origin.find(checkShortSen); //查找结果
		if (result != notFound)
		{
			if (true)
			{

			}
		}
	}
	return 0;
}

//定义是否抄袭
bool isCopied(const string& originText, const string& checkSen)
{

	return true;
}
