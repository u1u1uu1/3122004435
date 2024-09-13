#include "output.h"
#include <fstream>
#include <iomanip>
#include <iostream>

//向文件写入相似度
void writeSimilarityToFile(const string& targetFilePath, const float similarity,
	const string origin, const string check)
{
	ofstream ofs;
	ofs.open(targetFilePath, ios::app);
	ofs << "目标文件【" << check << "】";
	ofs << "与原文件【" << origin << "】";
	ofs << "相似度:" << setprecision(2) <<similarity << endl;
	//控制台输出
	cout << "目标文件【" << check << "】";
	cout << "与原文件【" << origin << "】";
	cout << "相似度：" << setprecision(2) << similarity << endl;
	ofs.close();
}