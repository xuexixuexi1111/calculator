/*
* 项目名称：简易计算器的实现
* 程序说明: 求解sin函数
* 小组成员：伏皓裕、龚双林、袁龙龙
*/

#include "sin.h"

/*
* 输入参数:
*    x :表示要计算的数
*	 n :泰勒展开的精度，保留了n项
* 返回参数：
*    double 类型的计算结果
*/

double sin_taylor(double x, int n) {
	double result = 0.0;
	int i;
	for (i = 0; i < n; i++) {
		// 求解泰勒展开的每一项，sign 是系数  term 是x的每一项展开
		int sign = (i % 2 == 0) ? 1 : -1;   
		double term = power(x, 2 * i + 1) / factorial(2 * i + 1);          
		result += sign * term;
	}
	return result;
}

/*
* 功能   ：
*    计算 n的阶乘
* 输入参数:
*	 n :输入参数n
* 返回参数：
*    int 类型的计算结果
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
* 功能   ：
*    计算 x的次方
* 输入参数:
*	 x :表示要计算的数
*    y :表示x的y次方
* 返回参数：
*    int 类型的计算结果
*/

double power(double x, double y)
{
	double result = 1.0;
	int i;
	for (i = 0; i < y; i++)
		result *= x;
	return result;
}