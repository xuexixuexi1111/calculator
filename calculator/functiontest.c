/*
* 项目名称：简易计算器的实现
* 程序说明: 测试函数
* 测试时间：2024年4月12日
* 小组成员：伏皓裕、龚双林、袁龙龙
* 作者：龚双林

*/
#define _USE_MATH_DEFINES
#include <stdio.h>  
#include <math.h>  
#include "sin.h"
#include "cos.h"
#include "tan.h"
#include "arcsin.h"
#include "arccos.h"
#include "arctan.h"  

  
// 测试函数  
void test_trig_functions() {  
    const int num_tests = 1000; // 测试点的数量  
    const double max_value = 1.0; // 对于sin, cos的最大值  
    const double max_angle = 1.0; // 对于asin, acos, atan的最大角度（弧度）  
    double value, diff_sin, diff_cos, diff_tan, diff_asin, diff_acos, diff_atan;  
    int i;  
  
    // 测试sin和cos函数  
    for (i = 0; i < num_tests; ++i) {  
        value = (double)i / (num_tests - 1) * 2.0 * M_PI; // 生成[0, 2π]范围内的值  
        diff_sin = fabs(sin(value) - sin_taylor(value,10));  
        diff_cos = fabs(cos(value) - cos_taylor(value,10));  
        printf("sin(%f): diff = %e\n", value, diff_sin);  
        printf("cos(%f): diff = %e\n", value, diff_cos);  
    }  
  
    // 测试tan函数  
    for (i = 0; i < num_tests; ++i) {  
        value = (double)i / (num_tests - 1) * (M_PI / 2.0) - M_PI / 4.0; // 生成[-π/4, π/4]范围内的值以避免无穷大  
        diff_tan = fabs(tan(value) - tan_taylor(value));  
        printf("tan(%f): diff = %e\n", value, diff_tan);  
    }  
  
    // 测试asin, acos, atan函数  
    for (i = 0; i < num_tests; ++i) {  
        value = (double)i / (num_tests - 1) * 2.0 * max_value - max_value; // 生成[-max_value, max_value]范围内的值  
        diff_asin = fabs(asin(value) - arcsin(value));  
        diff_acos = fabs(acos(value) - arccos(value));  
        diff_atan = fabs(atan(value) - arctan(value));  
        printf("asin(%f): diff = %e\n", value, diff_asin);  
        printf("acos(%f): diff = %e\n", value, diff_acos);  
        printf("atan(%f): diff = %e\n", value, diff_atan);  
    }  
}  
  
int main() {  
    test_trig_functions();  
    return 0;  
}