#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a, b;
	scanf_s("%d%d", &a, &b);
	printf("����%d\n", a + b);
	printf("����%d\n", a - b);
	printf("����%d\n", a * b);
	if (b!=0)
	{
		printf("����%lf\n",(double) a /(double)b);
		printf("������%d\n", a%b);
	}
	system("pause");

}