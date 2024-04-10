/*
* 项目名称：简易计算器的实现
* 程序说明: 求解arccos函数
* 小组成员：伏皓裕、龚双林、袁龙龙
* 作者：龚双林
*/
#include "arccos.h"
#include "arcsin.h"
#define pi 3.14159265

/*
* 输入参数:
*    x :表示要计算的数(定义域[-1,1]，需要去做输入范围判断)
* 返回参数：
*    double 类型的计算结果
*/

double arccos(double x)
{
    double g = pi/2-arcsin(x);  
    return g;
}