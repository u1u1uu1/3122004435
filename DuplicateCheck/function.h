#pragma once
#include <string>
#include <map>
#include <list>
using namespace std;

//预处理
void pretreatment();

//分句
map<string, list<string>>& divideArticle(const string filepath);

//建立倒排索引
map<string, list<string>>& make7CharMap(const map<string, list<string>>& sentences);