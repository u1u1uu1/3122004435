#pragma once
#include "message.h"
#include <string>
#include <map>

using namespace std;

//��ȡ���ƶ�
float getSimilarity(const map<string, message>& origin, const map<string, message>& check);

//�����Ƿ�Ϯ
bool isCopied(const string& originText, const string& checkSen);
