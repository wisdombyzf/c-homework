#include<stdio.h>
#include<stdlib.h>
#define pi 3.141592

int main()
{
	printf("����뾶\n");
	double a;
	scanf_s("%lf", &a);
	printf("ֱ����%lf\n", 2 * a);
	printf("�ܳ���%lf\n", 2 * pi*a);
	printf("�����%lf\n", pi*a*a);
	system("pause");
}