
#include <iostream>
#include "function.h"
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
	pretreatment();
	
}