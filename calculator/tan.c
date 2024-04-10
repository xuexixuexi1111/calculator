/*
* 项目名称：简易计算器的实现
* 程序说明: 求解tan函数
* 小组成员：伏皓裕、龚双林、袁龙龙
*/

#include "tan.h"
#include "cos.h"
#include "sin.h"
#include <stdio.h>
#include <math.h>

char  Error = 0;

/*
* 输入参数:
*    x :表示要计算的数
* 返回参数：
*    double 类型的计算结果
*/

double tan_taylor(double x) {
	double result = 0.0;
	// tanx = sinx /cosx ,设置一个值，如果cosx小它,说明这个结果无穷大
	if (fabs(cos_taylor(x, 10)) <= 1e-6)
	{
		Error = 1;
		printf("计算错误，tanx为无穷大！!\n");
	}
	else
		result = sin_taylor(x, 10) / cos_taylor(x, 10);
	return result;

}

