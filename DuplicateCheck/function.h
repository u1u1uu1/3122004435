#pragma once
#include "message.h"
#include <string>
#include <map>
#include <list>
#include <regex>
#include <set>
using namespace std;

//预处理
map<string, message>& pretreatment(const string& filepath);

//分句
map<string, list<string>>& divideArticle(const string filepath);

//拆分自然段
list<string>& divideParagraph(const string& str, const string& seperator);

//查找标点下标
void findPounIndex(const string& str, const string& seperator, set<int>& set);

//建立倒排索引
map<string, message>& make7CharMap(const map<string, list<string>>& sentences);

//滑动窗口截取7字索引
list<string>& cut7CharIndex(const string& subSen);