#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char name[20], ch;
	FILE *fp;
	int n = 0;
	printf("�����ļ���(Ҫ����׺,�ļ�����ֻ��zf.txt)\n");
	scanf("%s", name);
	if ((fp = fopen(name, "r+")) == NULL)
	{
		printf("�ļ�������\n");
		system("pause");
		exit(1);
	}
	
	FILE *p, *pp;
	p =fopen(name, "r+");
	pp = fopen(name, "r+");
	ch = fgetc(fp);
	printf("�˽��Ʊ�ʾ\n");
	while (ch != EOF)
	{
		printf("%o", ch);
		n++;
		ch = fgetc(fp);
	}
	printf("\nʮ�����Ʊ�ʾ\n");
	ch = fgetc(p);
	while (ch != EOF)
	{
		printf("%x",ch);
		n++;
		ch = fgetc(p);
	}
	printf("\nASCLL��ʾ\n");
	ch = fgetc(pp);
	while (ch != EOF)
	{
		printf("%c", ch);
		n++;
		ch = fgetc(pp);
	}
	printf("\n");
	fclose(fp);
	system("pause");
}