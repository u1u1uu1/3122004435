#include <iostream>
#include "function.h"
#include "compare.h"
#include "output.h"
using namespace std;

string originTextPath;
string copyTextPath;
string outputPath;

int main(int argc, char* argv[]) 
{
	//输入参数错误，程序退出
	if (argc != 4)
	{
		cout << "parameters error, lack or excess" << endl;
		exit(0);
	}

	//接收路径参数
	originTextPath = argv[1];
	copyTextPath = argv[2];
	outputPath = argv[3];

	//预处理
	pair<map<string, list<string>>, map<string, message>> *originIndex 
		= &pretreatment(originTextPath);
	pair<map<string, list<string>>, map<string, message>> *checkIndex 
		= &pretreatment(copyTextPath);

	//比较
	float similarity = getSimilarity(*originIndex, *checkIndex);

	//输出到目标文件
	writeSimilarityToFile(outputPath, similarity, 
		originIndex->first.begin()->first, checkIndex->first.begin()->first);

	//回收内存
	delete originIndex;
	delete checkIndex;
}