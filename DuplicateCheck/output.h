#pragma once
#include <string>

using namespace std;

//向文件写入相似度
void writeSimilarityToFile(const string& targetFilePath, const float similarity, 
	const string origin, const string check);