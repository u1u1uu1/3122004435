#include "compare.h"
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

//��ȡ���ƶ�
float getSimilarity(const pair<map<string, list<string>>, map<string, message>>& originMsg, 
	const pair<map<string, list<string>>, map<string, message>>& checkMsg)
{
	//����õ��Ӿ�
	map<string, list<string>> checkSen = checkMsg.first;
	//map<string, list<string>> originSen = originMsg.first;

	//����õ�����
	map<string, message> check = checkMsg.second;
	map<string, message> origin = originMsg.second;

	float copyCount = 0; //��Ϯ���Ӽ�����
	//const int senSum = check.size(); //��������
	auto checkEnd = check.end();
	auto notFound = origin.end(); //�����ж϶̾���ԭ�����Ƿ����
	//set<pair<ԭ��, ���Ƴ�Ϯ��>>
	set<pair<string, string>> suspect; //���Ƴ�Ϯ�ľ�����

	//�����������£�������Ƴ�Ϯ�ľ�����
	for (auto it = check.begin(); it != checkEnd; it++) 
	{
		string checkShortSen = it->first; //Ҫ�ҵĶ̾�
		auto result = origin.find(checkShortSen); //���ҽ��
		if (result != notFound) //�鵽���������Ƴ�Ϯ
		{
			pair<string, string> doubt(result->second.text, it->second.text);
			suspect.insert(doubt);
		}
	}

	//���������У������Ƿ�Ϯ
	auto doubtEnd = suspect.end();
	for (auto it = suspect.begin(); it != doubtEnd; it++)
	{
		if (isCopied(it->first, it->second))
		{
			copyCount++;
		}
	}
	return copyCount / checkSen.begin()->second.size();
}

//�����Ƿ�Ϯ
bool isCopied(const string& originText, const string& checkSen)
{
	int copyCount = LCS(originText, checkSen);
	int chCharSize = 2;
	int checkSenCharCount = checkSen.size() / chCharSize;
	return 2 * copyCount > checkSenCharCount; //�ظ�����һ���㳭Ϯ
}

//���ҹ���������
int LCS(const string& originText, const string& checkSen)
{
	int chCharSize = 2;
	int checkSenCharCount = checkSen.size() / chCharSize;
	int originTextCharCount = originText.size() / chCharSize;
	//���嶯̬�滮�Ķ�ά��
	int** table = new int*[checkSenCharCount + 1];
	for (size_t i = 0; i < checkSenCharCount + 1; i++)
	{
		table[i] = new int[originTextCharCount + 1] {0};
	}
	//��̬�滮
	for (int i = 1; i <= checkSenCharCount; i++)
	{
		for (int j = 1; j <= originTextCharCount; j++)
		{
			if (checkSen[chCharSize * (i - 1)] == originText[chCharSize * (j - 1)] &&
				checkSen[chCharSize * (i - 1) + 1] == originText[chCharSize * (j - 1) + 1])
			{
				table[i][j] = table[i - 1][j - 1] + 1;
			}
			else
			{
				table[i][j] = max(table[i - 1][j], table[i][j - 1]);
			}
			//cout << table[i][j] << " ";
		}
		//cout << endl;
	}
	/*for (size_t i = 0; i < checkSenCharCount + 1; i++)
	{
		for (size_t j = 0; j < originTextCharCount + 1; j++)
		{
			cout << table[i][j] << " ";
		}
		cout << endl;
	}*/
	int sameCount = table[checkSenCharCount][originTextCharCount];
	//�ͷſռ�
	for (size_t i = 0; i < checkSenCharCount + 1; i++)
	{
		delete[] table[i];
	}
	delete[] table;
	return sameCount;
}