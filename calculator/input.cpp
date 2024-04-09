/***********************《现代软件工程》课程作业-----三角函数计算器**********
*************************小组成员：伏皓裕 袁龙龙 龚双林**********************
*
******************************用户输入处理模块********************************
********************************作者：伏皓裕*********************************
********************************时间：2024.4.9*******************************
*/
#include <stdio.h>

//以下两行代码是为解决在VS2022编译器中scanf()函数无法正常使用而存在
//在其他编译器中或可删除
#define _CRT_SECURE_NO_WARININGS 
#pragma warning(disable:4996)

/*
*@输入参数：无
*@返回参数：char ch
*@功能：获取用户键盘输入的第一个非换行符的字符类值，将其返回
*/
char get_first(void)
{
	int ch;
	ch = getchar();
	while (getchar() != '\n')
		continue;
	return ch;
}

/*
*@输入参数：无
*@返回参数：char ch
*@功能：屏幕显示菜单令用户选择下一步输入数据的类型，并将用户输入的字母返回，
        返回值ch为a代表用户选择角度制，ch为b代表用户选择弧度制
*/
char ang_or_rad()
{
	char ch;
	printf("请选择角度制表示还是弧度制\n");
	printf("a.角度制(ang)；b.弧度制(rad)\n");
	printf("请选择（输入完后按回车）：");
	ch = get_first();  //输入角度、弧度 
	while (ch < 'a' || ch>'b')//输入合法性判断
	{
		printf("请重新输入（a或b）：");
		ch = get_first();
	}
	return ch;
}

/*
*@输入参数：无
*@返回参数：char ch
*@功能：屏幕显示菜单令用户选择需要进行运算的三角函数类型，并将用户输入的字母返回，
		返回值ch为a代表用户选择sin运算，ch为b代表用户选择cos运算，ch为c代表用户选择tan运算，
		ch为d代表用户选择arcsin运算，ch为e代表用户选择arccos运算，ch为f代表用户选择arctan运算，
*/
char type_choice()
{
	char ch;
	printf("请选择运算类型：\n");
	printf("a.正弦运算sin		b.余弦运算cos		c.正切运算tan\n");
	printf("d.反正弦运算arcsin	e.反余弦运算arccos	f.反正切运算arctan\n");
	printf("请输入（输入完后按回车）：");
	ch = get_first();   //选择三角函数的类型
	while (ch < 'a' || ch>'f')//输入合法性判断
	{
		printf("请重新输入（a~f）：");
		ch = get_first();
	}
	return ch;
}

/*
*@输入参数：无
*@返回参数：double data
*@功能：提示用户输入需要进行运算的数值，根据上一步选择的三角函数类型进行合法性判断，
*       通过判断后，将待处理数值返回
*/
double data_input(char type)
{
	double data;
	char ch;
	printf("请输入需要运算的数值（输入完后按回车）：");

	if (type == 'd' || type == 'e')
	{
		while (scanf("%lf", &data) != 1 || (data < -1 || data>1))//进行arcsin与arccos运算时，待处理数据的范围为[-1，1]
		{
			while ((ch = getchar()) != '\n');
			printf("请输入范围为[-1，1]的数字（输入完后按回车）：");
		}
	}
	else
	{
		while (scanf("%lf", &data) != 1)
		{
			while ((ch = getchar()) != '\n');
			printf("输入错误，请重新输入（输入完后按回车）：");
		}
	}

	return data;
}