#include <iostream>
using namespace std;


int main(int argc, char* argv[]) 
{
	//输入参数错误，程序退出
	if (argc != 4)
	{
		cout << "There are not enough parameters" << endl;
		exit(0);
	}
	//接收路径参数
	string originTextPath = argv[1];
	string copyTextPath = argv[2];
	string outputPath = argv[3];
}