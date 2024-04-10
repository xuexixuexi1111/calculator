/*
* 项目名称：简易计算器的实现
* 程序说明: 求解arctan函数
* 小组成员：伏皓裕、龚双林、袁龙龙
* 作者：龚双林
*/
#include <math.h>
#include "arctan.h"
#define pi 3.14159265
/*
* 输入参数:
*    x :表示要计算的数
* 返回参数：
*    double 类型的计算结果
*    输出值精确到小数点后10位
*/

double arctan(double x)
{
    double g;
    double sum=1;
    double t;
    int n;
    int i;
    if(fabs(x) < 1)      // 输入值绝对值小于1时，采用泰勒级数展开
    {
		g = x;
		n = 1;
		while (n < 9999)
		{
			for(i = 1;i <= n;i++)  //for循环实现x的n次方
			{
				sum = sum*(-1);
			}
			t = sum;
			sum = 1;
			for(i = 1;i <= (2 * n + 1);i++)
			{
				sum = sum*x;
			}
			t = t * sum / (2 * n + 1);
            g += t;
            n += 1;
		}
	}              
    else               //输入值绝对值大于等于1，用 pi/2 - atan(x)
    {
		x = 1/x;
		g = x;
		n = 1;
        while(n < 9999)
		{
			for(i = 1;i <= n;i++)   //for循环实现x的n次方
			{
				sum = sum*(-1);
			}
			t = sum;
			sum = 1;
			for(i = 1;i <= (2 * n + 1);i++)
			{
				sum = sum*x;
			}
			t = t * sum / (2 * n + 1);
            g += t;
            n += 1;
		}     
        g = pi/2 - g;
	}         
  
  if(x < 0 && g >= 0)
  {
	g = g - pi;    
  }  
  return g;
}