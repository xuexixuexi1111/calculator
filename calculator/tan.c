/*
* ��Ŀ���ƣ����׼�������ʵ��
* ����˵��: ���tan����
* С���Ա�����ԣ����˫�֡�Ԭ����
*/

#include "tan.h"
#include "cos.h"
#include "sin.h"
#include <stdio.h>
#include <math.h>

char  Error = 0;

/*
* �������:
*    x :��ʾҪ�������
* ���ز�����
*    double ���͵ļ�����
*/

double tan_taylor(double x) {
	double result = 0.0;
	// tanx = sinx /cosx ,����һ��ֵ�����cosxС��,˵�������������
	if (fabs(cos_taylor(x, 10)) <= 1e-6)
	{
		Error = 1;
		printf("�������tanxΪ�����!\n");
	}
	else
		result = sin_taylor(x, 10) / cos_taylor(x, 10);
	return result;

}

