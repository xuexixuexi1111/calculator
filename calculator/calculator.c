/********************《现代软件工程》课程作业-----三角函数计算器************
*************************小组成员： 袁龙龙 龚双林 伏皓裕**********************
*
****************************三角函数计算器输出模块***************************
********************************作者：伏皓裕*********************************
********************************时间：2024.4.11*******************************
*/

//以下两行代码是为解决在VS2022编译器中scanf()函数无法正常使用而存在
//在其他编译器中或可删除
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

extern char  Error;		//	tanx计算错误标志

/*
*@输入参数：无
*@返回参数：无
*@功能：调用输入模块与计算模块的函数，将用户需要需要得到的结果打印在屏幕
*/
void calculator( )
{
	double data;//用户输入待计算数据
	double tanCalculate;
	char judge, tppe;//judge:待处理数据的类型（角度/弧度）；tppe：用户选择的三角函数类型
	
		tppe = type_choice();
		if (tppe == 'd' || tppe == 'e' || tppe == 'f')//用户选择反三角函数时，不用在选择角度/弧度制表示
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