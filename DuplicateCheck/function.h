#pragma once
#include "message.h"
#include <string>
#include <map>
#include <list>
#include <regex>
#include <set>
using namespace std;

//Ԥ����
map<string, message>& pretreatment(const string& filepath);

//�־�
map<string, list<string>>& divideArticle(const string filepath);

//�����Ȼ��
list<string>& divideParagraph(const string& str, const string& seperator);

//���ұ���±�
void findPounIndex(const string& str, const string& seperator, set<int>& set);

//������������
map<string, message>& make7CharMap(const map<string, list<string>>& sentences);

//�������ڽ�ȡ7������
list<string>& cut7CharIndex(const string& subSen);