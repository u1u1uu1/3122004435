#include "compare.h"
#include <iostream>

using namespace std;

//��ȡ���ƶ�
float getSimilarity(const pair<map<string, list<string>>, map<string, message>>& originMsg, 
	const pair<map<string, list<string>>, map<string, message>>& checkMsg)
{
	map<string, message> check = checkMsg.second;
	map<string, message> origin = originMsg.second;
	float copyScore = 0; //��Ϯ���ӼƷ���
	const int senSum = check.size(); //��������
	auto checkEnd = check.end();
	auto notFound = origin.end(); //�����ж϶̾���ԭ�����Ƿ����
	//�����������£��г����Ƴ�Ϯ�ľ����б�
	for (auto it = check.begin(); it != checkEnd; it++) 
	{
		string checkShortSen = it->first; //Ҫ�ҵĶ̾�
		auto result = origin.find(checkShortSen); //���ҽ��
		if (result != notFound)
		{
			if (true)
			{

			}
		}
	}
	return 0;
}

//�����Ƿ�Ϯ
bool isCopied(const string& originText, const string& checkSen)
{

	return true;
}
