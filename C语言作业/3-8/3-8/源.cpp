#include<stdio.h>
#include<stdlib.h>

int main()
{
	double a;
	printf("����Ӣ��\n");
	scanf_s("%lf", &a);
	printf("%lf����\n", (a * 5280 * 12 * 2.54) / 100000);
	system("pause");


}