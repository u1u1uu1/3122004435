#pragma once
#include "message.h"
#include <string>
#include <map>
#include <list>

using namespace std;

//��ȡ���ƶ�
float getSimilarity(const pair<map<string, list<string>>, map<string, message>>& origin, 
	const pair<map<string, list<string>>, map<string, message>>& check);

//�����Ƿ�Ϯ
bool isCopied(const string& originText, const string& checkSen);
