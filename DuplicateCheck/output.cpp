#include "output.h"
#include <fstream>
#include <iomanip>
#include <iostream>

//���ļ�д�����ƶ�
void writeSimilarityToFile(const string& targetFilePath, const float similarity,
	const string origin, const string check)
{
	ofstream ofs;
	ofs.open(targetFilePath, ios::app);
	ofs << "Ŀ���ļ���" << check << "��";
	ofs << "��ԭ�ļ���" << origin << "��";
	ofs << "���ƶ�:" << setprecision(2) <<similarity << endl;
	//����̨���
	cout << "Ŀ���ļ���" << check << "��";
	cout << "��ԭ�ļ���" << origin << "��";
	cout << "���ƶȣ�" << setprecision(2) << similarity << endl;
	ofs.close();
}