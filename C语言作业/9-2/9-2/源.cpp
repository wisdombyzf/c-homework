#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

/*�ṹ�嶨�����*/
typedef struct student 
{
	int num;
	double GPA;

}STU; 

 int avg(student *p1, int n)
{
	double sum = 0;
	student *pp = p1;
	for (int k = 0; k < n; k++)
	{
		sum = sum + (p1->GPA);
		p1++;
	}
	sum = sum / (double)n;
	printf("ƽ����:%lf\n", sum);
	int w=0;
	p1 = pp;
	printf("85�����ϵ�ѧ��\n");
	for (int k = 0; k <n; k++)
	{
		if ((pp->GPA)>85)
		{
			printf("ѧ�ţ�%d\t������%lf\n", pp->num, pp->GPA);
			w++;
		}
		pp++;
	}
	return w;
}

int main()
{
	STU a[10] = { 0 };
	int n;
	printf("������ѧ����Ŀ\n");
	scanf_s("%d", &n);
	printf("������ID��ɼ�\n");
	for (int i = 0; i <n; i++)
	{
		scanf_s("%d", &a[i].num);
		scanf_s("%lf", &a[i].GPA);
	}

	student *p, *p1;
	p = p1 = a;

	printf("85�����ϵ�ѧ����%d", avg(p1, n));
	system("pause");
}