#include<stdio.h>
#include<stdlib.h>
/*oj���Ǵ�ģ�������������ôд�ģ�*/

int main()
{
	union 
	{
		int n;
		char s[5];
	}a;
	printf("����һ����\n");
	scanf_s("%d", &a.n);
	for (int i = 0; i < sizeof(int); i++)
	{
		printf("%d�ĵ�%d�ֽڱ����ǣ�%x\n", a.n, i + 1, a.s[i] & 0xff);
	}
	system("pause");
	return 0;
}