/*
* ��Ŀ���ƣ����׼�������ʵ��
* ����˵��: ���sin����
* С���Ա�����ԣ����˫�֡�Ԭ����
*/

#include "sin.h"

/*
* �������:
*    x :��ʾҪ�������
*	 n :̩��չ���ľ��ȣ�������n��
* ���ز�����
*    double ���͵ļ�����
*/

double sin_taylor(double x, int n) {
	double result = 0.0;
	int i;
	for (i = 0; i < n; i++) {
		// ���̩��չ����ÿһ�sign ��ϵ��  term ��x��ÿһ��չ��
		int sign = (i % 2 == 0) ? 1 : -1;   
		double term = power(x, 2 * i + 1) / factorial(2 * i + 1);          
		result += sign * term;
	}
	return result;
}

/*
* ����   ��
*    ���� n�Ľ׳�
* �������:
*	 n :�������n
* ���ز�����
*    int ���͵ļ�����
*/

int factorial(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	else {
		return n * factorial(n - 1);
	}
}


/*
* ����   ��
*    ���� x�Ĵη�
* �������:
*	 x :��ʾҪ�������
*    y :��ʾx��y�η�
* ���ز�����
*    int ���͵ļ�����
*/

double power(double x, double y)
{
	double result = 1.0;
	int i;
	for (i = 0; i < y; i++)
		result *= x;
	return result;
}