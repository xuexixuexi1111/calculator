/********************���ִ�������̡��γ���ҵ-----���Ǻ���������************
*************************С���Ա�� Ԭ���� ��˫�� ���ԣ**********************
*
****************************���Ǻ������������ģ��***************************
********************************���ߣ����ԣ*********************************
********************************ʱ�䣺2024.4.11*******************************
*/

//�������д�����Ϊ�����VS2022��������scanf()�����޷�����ʹ�ö�����
//�������������л��ɾ��
#define _CRT_SECURE_NO_WARININGS 
#pragma warning(disable:4996)


#include <stdio.h>
#include "input.h"
#include "sin.h"
#include "cos.h"
#include "tan.h"
#include "arcsin.h"
#include "arccos.h"
#include "arctan.h"
#include "calculator.h"


#define PI 3.14159265

extern char  Error;		//	tanx��������־

/*
*@�����������
*@���ز�������
*@���ܣ���������ģ�������ģ��ĺ��������û���Ҫ��Ҫ�õ��Ľ����ӡ����Ļ
*/
void calculator( )
{
	double data;//�û��������������
	double tanCalculate;
	char judge, tppe;//judge:���������ݵ����ͣ��Ƕ�/���ȣ���tppe���û�ѡ������Ǻ�������
	
		tppe = type_choice();
		if (tppe == 'd' || tppe == 'e' || tppe == 'f')//�û�ѡ�����Ǻ���ʱ��������ѡ��Ƕ�/�����Ʊ�ʾ
		{
			data = data_input(tppe);
			judge = 'b';
		}
		else
		{
			judge = ang_or_rad();
			data = data_input(tppe);
		}

		if (judge == 'a')
			data = data * PI / 180;

		switch (tppe)
		{
		case 'a':printf("sin(%lf)(rad)=%lf", data, sin_taylor(data, 10)); break;
		case 'b':printf("cos(%lf)(rad)=%lf", data, cos_taylor(data, 10)); break;
		case 'c':
		{
			tanCalculate = tan_taylor(data);
			if (!Error)
			{
				printf("tan(%lf)(rad)=%lf", data, tanCalculate);
			}
			Error = 0;
			break;
		}
		case 'd':printf("arcsin(%lf)=%lf(rad)", data, arcsin(data)); break;
		case 'e':printf("arccos(%lf)=%lf(rad)", data, arccos(data)); break;
		case 'f':printf("arctan(%lf)=%lf(rad))", data, arctan(data)); break;
		}
}