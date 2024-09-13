#include <iostream>
#include "function.h"
#include "compare.h"
using namespace std;

string originTextPath;
string copyTextPath;
string outputPath;

int main(int argc, char* argv[]) 
{;
	//����������󣬳����˳�
	if (argc != 4)
	{
		cout << "There are not enough parameters" << endl;
		exit(0);
	}
	//����·������
	originTextPath = argv[1];
	copyTextPath = argv[2];
	outputPath = argv[3];
	//Ԥ����
	pair<map<string, list<string>>, map<string, message>> *originIndex 
		= &pretreatment(originTextPath);
	pair<map<string, list<string>>, map<string, message>> *checkIndex 
		= &pretreatment(copyTextPath);
	//�Ƚ�
	float similarity = getSimilarity(*originIndex, *checkIndex);

	//�����ڴ�
	delete &originIndex;
	delete &checkIndex;
}