/*
* 项目名称：简易计算器的实现
* 程序说明: 求解arcsin函数
* 小组成员：伏皓裕、龚双林、袁龙龙
* 作者：龚双林
*/

#include "arcsin.h"
#include <math.h>
#define pi 3.14159265
/*
* 输入参数:
*    x :表示要计算的数(定义域[-1,1]，需要去做输入范围判断)
* 返回参数：
*    double 类型的计算结果
*    输出值精确到小数点后10位
*/

double arcsin(double x)

{ 
  double g = x;
  double t = x;
  int n = 1;
  if(x == 1)          //当输入值为1时返回计算值pi/2
  g = pi/2;
  else if(x == -1)   //当输入值为-1时返回计算值-pi/2
  g = -(pi/2);
  else              //当输入值属于(-1,1)时
  {
	  do
	  {
       t = t * (2 * n - 1) * (2 * n - 1) * x * x / ((2 * n) * (2 * n + 1));
       n += 1;
       g += t;
    } while (fabs(t) >= 1e-9);  // 采用泰勒级数展开进行计算逼近函数值
  } 
  return g;
}