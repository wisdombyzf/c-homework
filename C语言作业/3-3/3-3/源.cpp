#include<stdio.h>
#include<stdlib.h>

int main()
{
	double a, b;	//a=�۸� b=֧��
	printf("����۸�\n");
	scanf_s("%lf", &a);
	printf("����֧����Ǯ\n");	
	scanf_s("%lf",&b);
	printf("��Ǯ��Ϊ%lf\n", a - b);
	system("pause");
}