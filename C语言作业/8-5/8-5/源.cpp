#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

char a[1008];
int substitute(char str[], char oldchar, char newchar)
{

	int len, n = 0;
	len = strlen(a);
	for (int i = 0; i < len; i++)
	{
		if (a[i] == oldchar)
		{
			a[i] = newchar;
			n++;
		}
	}
	printf("%d ", n);
	printf("%s\n", a);
	return 0;
}

int find()
{
	int n, sum = 0;
	char a[11][11];
	char str[1008];
	printf("����Ҫ���ҵ��ַ�������\n");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", &a[i]);
	}
	printf("����ԭ�ַ���\n");
	scanf("%s", &str);
	int l = strlen(str);
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		int len = strlen(a[i]);
		for (int x = 0, y = 0; x < l; x++)        //xΪԭ�ַ���
		{
			char w = a[i][y];
			char e = str[x];
			if (a[i][y] == str[x])
			{
				if (y == (len - 1))
				{
					y = 0;
					sum++;
				}
				else
				{
					y++;
				}
			}
			else
			{
				x = x - y;
				y = 0;
			}
		}
		printf("�ַ�������Ϊ%d\n", sum);
	}
	return 0;
}
int main()
{
	printf("��ѡ���� 1.�����ַ���\t2.�滻�ַ���\n");
	int chose;
	scanf("%d", &chose);
	if (chose==1)
	{
		find();
	}
	else
	{
		char b, c;
		printf("����ԭʼ�ַ�����ԭ�ַ����滻�ַ�\n");
		scanf("%s", &a);
		getchar();
		scanf("%c %c", &b,&c);
		substitute(a, b, c);
	}	
	system("pause");
}
