#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a, b;
	printf("��������������");
	scanf_s("%d%d", &a, &b);
	printf("����%d\n", a + b);
	printf("�˻���%d\n", a *b);
	printf("����%d\n", a - b);
	if (b!=0)
	{
		printf("����%d\n", a / b);
		printf("������%d\n", a%b);
	}

	system("pause");
	return 0;
	



 }