#pragma once
#include <string>
#include <map>
#include <list>
using namespace std;

//Ԥ����
void pretreatment();

//�־�
map<string, list<string>>& divideArticle(const string filepath);

//������������
map<string, list<string>>& make7CharMap(const map<string, list<string>>& sentences);