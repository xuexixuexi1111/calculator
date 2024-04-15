/*
* 项目名称：简易计算器的实现
* 程序说明: 求解sin函数
* 小组成员：伏皓裕、龚双林、袁龙龙
* 作者：袁龙龙
*/


#include "basic.h"
#include<stdio.h>
#include <math.h>

char Zero = 1;

/*
* 输入参数: 空
* 返回参数：空
*    
*/

void basic(void)
{
    char op;
    float num1, num2, result;

    printf("请输入两个数字: ");
    scanf("%f %f", &num1, &num2);
    if (num1 >= 3.4e38 || num1 <= -3.4e38 || num2 >= 3.4e38 || num2 <= -3.4e38)     //对输入数字的大小进行限制，使其满足float变量的取值范围
    {
        printf("输入数字错误，请重新输入");
        scanf("%f %f", &num1, &num2);
    }
    while (getchar() != '\n');                      //清空缓冲区，避免scanf输入时enter的影响
    printf("请输入运算符(+, -, *, /): ");
    scanf("%c", &op);                               //等待用户输入规定的四则运算符号

    result = 0;
    switch (op)
    {                                               //判断用户输入的是哪个符号
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if ((fabs(num2) <= 1e-6)) {            //输入保留小数点后六位，设置被除数小于等于1e-6时，认为它为0         
                printf("错误：除数不能为0\n"); 
                Zero = 0;
            }
            else {
                result = num1 / num2;
            }
            break;
        default:
        {
            printf("错误：无效的运算符\n");
            Zero = 0;
        }
        
    }
    if(Zero)   printf("%.6f %c %.6f = %.6f\n", num1, op, num2, result);
    Zero = 1;
}
