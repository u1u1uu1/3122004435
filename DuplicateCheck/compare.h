#pragma once
#include "message.h"
#include <string>
#include <map>

using namespace std;

//获取相似度
float getSimilarity(const map<string, message>& origin, const map<string, message>& check);

//定义是否抄袭
bool isCopied(const string& originText, const string& checkSen);
