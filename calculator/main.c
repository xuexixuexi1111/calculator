/********************《现代软件工程》课程作业-----三角函数计算器************
*************************小组成员： 袁龙龙 龚双林 伏皓裕**********************
*
****************************三角函数计算器——主函数***************************
**************主体功能：三角函数计算器********扩展功能：加减乘除计算器********
********************************时间：2024.4.11*******************************
*/
#include <stdio.h>
#include "calculator.h"
#include "input.h"
#include "basic.h"


int main()
{
	char choice;
	char stop, ch;
	do
	{
		printf("请选择您需要的计算器类型：\n");
		printf("A.三角函数计算器；B.基础功能计算器\n");
		printf("请选择（输入完后按回车）：");
		choice = get_first(); //用户键入字母选择计算器类型
		while (choice < 'A' || choice>'B')//输入合法性判断
		{
			printf("请重新输入（A或B）：");
			choice = get_first();
		}
		switch (choice)
		{
		case 'A':calculator(); break;//三角函数计算器
		case 'B':basic(); break;//加减乘除计算器
		}
		printf("\n计算完成！输入q结束计算，输入其他字母重新开始计算。\n");
		while ((ch = getchar()) != '\n');
		stop = get_first();
	} while (stop != 'q');//循环计算，用户键入q停止，输入其他开始新一轮计算
	return 0;
}