#pragma once
#include "message.h"
#include <string>
#include <map>
#include <list>

using namespace std;

//获取相似度
float getSimilarity(const pair<map<string, list<string>>, map<string, message>>& origin, 
	const pair<map<string, list<string>>, map<string, message>>& check);

//定义是否抄袭
bool isCopied(const string& originText, const string& checkSen);
