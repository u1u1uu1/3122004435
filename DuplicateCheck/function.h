#pragma once
#include <string>
#include <map>
#include <list>
#include <regex>
#include <set>
using namespace std;

//Ԥ����
void pretreatment();

//�־�
map<string, list<string>>& divideArticle(const string filepath);

//�����Ȼ��
list<string>& divideParagraph(const string& str, const string& seperator);

//���ұ���±�
void findPounIndex(const string& str, const string& seperator, set<int>& set);

//������������
map<string, list<string>>& make7CharMap(const map<string, list<string>>& sentences);