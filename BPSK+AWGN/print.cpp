#include"print.h"
#include<iostream>
#include<fstream>

using namespace std;
//��Eb/N0��BER���뵽�ı��ļ��У����㵽ʱ����MATLAB���л�ͼ
void print(int ebn0, double ber) {
	cout << ebn0 << " " << ber << endl;
	fstream fout("Result.txt", ios::out | ios::app);
	if (!fout.is_open()) {
		cout << "error" << endl;
		exit(1);
	}
	fout<< ebn0 << " " << ber << endl;
	fout.close();
}
