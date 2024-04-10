/*
* 项目名称：简易计算器的实现
* 程序说明: 求解cos函数
* 小组成员：伏皓裕、龚双林、袁龙龙
*/


#include "cos.h"

/*
* 输入参数:
*    x :表示要计算的数
*	 n :泰勒展开的精度，保留了n项
* 返回参数：
*    double 类型的计算结果
*/

double cos_taylor(double x, int n) {
	double result = 1.0;
	double term = 1.0;
	int i;

	for (i = 1; i <= n; i++) {
		// 求解泰勒展开的每一项，然后相加
		term *= -x * x / ((2 * i) * (2 * i - 1));
		result += term;
	}

	return result;
}