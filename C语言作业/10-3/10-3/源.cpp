#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*
����治��............

��������������Ӧ��ֻ��ͨ��Դ�����99999
*/
double cubie(int n)
{
	return n*n*n*exp(n*sin(n));
}

int main()
{
	FILE *fr = NULL;
	fr = fopen("unix", "w+");
	if (fr == NULL)
	{
		printf("�ļ�������\n");
		system("pause");
		exit(1);
	}

	FILE *pp = fopen("dos", "w+");
	int n;
	while (!feof(pp))
	{
		fscanf(pp, "%d", &n);
		if ((n<1) || (n>20))
		{
			fprintf(fr, "%s", "���ֲ���Ҫ��");
			fprintf(fr, "%d", n);
		}
		else
		{
			fprintf(fr, "%lf", cubie(n));
		}
	}
	system("pause");
}