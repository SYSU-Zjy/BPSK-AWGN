#include "createRandomCode.h"
#include "bpskModulation.h"
#include "channelAWGN.h"
#include "bpskDemodulation.h"
#include "print.h"
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <fstream>

using namespace std;

const int N = 1000000; //���س���
const int Ebn0_Num = 11; //ebn0����
int main() {
	fstream fclear("Result.txt", ios::out); // ÿ�δ�������ı�ԭ����
	for (int i = 0; i < Ebn0_Num; i++) { 
		int miss = 0;
		for (int j = 0; j < N; j++) { 
			int input = GetRandCode(); ////��ȡ����� 
			int n1 = AfterModulation(input);//���0��-1,1��1��ӳ��
			double uniform = Uniform();
			double *Gaussian_random = new double;
			Normal(Gaussian_random, 1); //�������Ӿ�ֵΪ0������Ϊ1����̬�ֲ��������
			double n2 = GetAwgnCode(&n1, i, Gaussian_random);// ��ȡ���ŵ��м����˹������������� 
			int output = AfterDemodulation(&n2);//��ɽ�������ܣ���ɵ�0��1�Ļ�ԭ
			if (output != input) // ��ԭ�źŽ��бȽϣ���������ͳ��
				miss++;
		}
		double ber = miss / (double)N;// ����ÿһ��ebn0�����ber
		print(i, ber); // ���
	}
	system("pause");
	return 0;
}
