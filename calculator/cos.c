/*
* ��Ŀ���ƣ����׼�������ʵ��
* ����˵��: ���cos����
* С���Ա�����ԣ����˫�֡�Ԭ����
*/


#include "cos.h"

/*
* �������:
*    x :��ʾҪ�������
*	 n :̩��չ���ľ��ȣ�������n��
* ���ز�����
*    double ���͵ļ�����
*/

double cos_taylor(double x, int n) {
	double result = 1.0;
	double term = 1.0;
	int i;

	for (i = 1; i <= n; i++) {
		// ���̩��չ����ÿһ�Ȼ�����
		term *= -x * x / ((2 * i) * (2 * i - 1));
		result += term;
	}

	return result;
}