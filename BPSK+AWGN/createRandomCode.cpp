#include <ctime>
#include <cstdlib>
#include "createRandomCode.h"
//ʹ��srand()���������
int GetRandCode() {
	srand(time(NULL));
	int randNum = rand() % 2;
	return randNum;
}
