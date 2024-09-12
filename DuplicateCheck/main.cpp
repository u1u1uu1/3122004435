
#include <iostream>
#include "function.h"
using namespace std;

string originTextPath;
string copyTextPath;
string outputPath;

int main(int argc, char* argv[]) 
{;
	//输入参数错误，程序退出
	if (argc != 4)
	{
		cout << "There are not enough parameters" << endl;
		exit(0);
	}
	//接收路径参数
	originTextPath = argv[1];
	copyTextPath = argv[2];
	outputPath = argv[3];
	pretreatment();
	
}