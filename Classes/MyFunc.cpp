#include "MyFunc.h"

float MyFunc::GetRandomNumber(std::default_random_engine &e, int i1, int i2) {
	std::uniform_int_distribution<int> u(i1, i2); //����0��10�����������ȷֲ��������
	return float(u(e));
}
