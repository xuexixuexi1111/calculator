/*
* ��Ŀ���ƣ����׼�������ʵ��
* ����˵��: ���sin����
* С���Ա�����ԣ����˫�֡�Ԭ����
* ���ߣ�Ԭ����
*/


#include "basic.h"
#include<stdio.h>
#include <math.h>

char Zero = 1;

/*
* �������: ��
* ���ز�������
*    
*/

void basic(void)
{
    char op;
    float num1, num2, result;

    printf("��������������: ");
    scanf("%f %f", &num1, &num2);
    if (num1 >= 3.4e38 || num1 <= -3.4e38 || num2 >= 3.4e38 || num2 <= -3.4e38)     //���������ֵĴ�С�������ƣ�ʹ������float������ȡֵ��Χ
    {
        printf("�������ִ�������������");
        scanf("%f %f", &num1, &num2);
    }
    while (getchar() != '\n');                      //��ջ�����������scanf����ʱenter��Ӱ��
    printf("�����������(+, -, *, /): ");
    scanf("%c", &op);                               //�ȴ��û�����涨�������������

    result = 0;
    switch (op)
    {                                               //�ж��û���������ĸ�����
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
            if ((fabs(num2) <= 1e-6)) {            //���뱣��С�������λ�����ñ�����С�ڵ���1e-6ʱ����Ϊ��Ϊ0         
                printf("���󣺳�������Ϊ0\n"); 
                Zero = 0;
            }
            else {
                result = num1 / num2;
            }
            break;
        default:
        {
            printf("������Ч�������\n");
            Zero = 0;
        }
        
    }
    if(Zero)   printf("%.6f %c %.6f = %.6f\n", num1, op, num2, result);
    Zero = 1;
}
