#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

/*�ṹ�嶨�����*/
struct student                                                     
{
	int num;
	double GPA;

}a[10];

student*max(student *p1, int n)
{
	student *pp = p1;
	for (int k = 1; k <n; k++)
	{
		if ((pp->GPA)<((p1 + 1)->GPA))
		{
			pp = (p1+1);
		}
		p1++;
	}
	return pp;
}

student*min(student *p1, int n)
{
	student *pp = p1;
	for (int k = 1; k <n; k++)
	{
		if ((pp->GPA)>((p1 + 1)->GPA))
		{
			pp = (p1 + 1);
		}
		p1++;
	}
	return pp;
}
student*avg(student *p1, int n)
{
	double sum = 0;
	student *pp = p1;
	for (int k = 0; k < n; k++)
	{
		sum = sum + (p1->GPA);
		p1++;
	}
	sum = sum /(double)n;
	printf("ƽ����%lf", sum);
	double cha;
	p1 = pp;
	cha = fabs((p1->GPA) - sum);
	for (int k = 0; k <n; k++)
	{
		if (fabs(((pp->GPA)-sum))<cha)
		{
			cha = ((pp->GPA) - sum);
			p1 = pp;
		}
		pp++;
	}
	return p1;
}

int main()
{
	int n;
	printf("������ѧ����Ŀ\n");
	scanf_s("%d", &n);
	printf("������ID��ɼ�\n");
	for (int  i = 0; i <n; i++)
	{
		scanf_s("%d", &a[i].num);
		scanf_s("%lf", &a[i].GPA);
	}
	student *p,*p1;
	p=p1=a;
	p1 = max(p, n);

	printf("���ѧ����%d\t%lf\t", p1->num,p1->GPA);
	printf("��߷��±꣺%d\n",p1-p);
	
	p1 = min(p, n);
	printf("���ѧ����%d\t%lf\t", p1->num, p1->GPA);
	printf("��ͷ��±꣺%d\n", p1 - p);

	p1 = avg(p, n);
	printf("ƽ��ѧ����%d\t%lf\t", p1->num, p1->GPA);
	printf("ƽ��ѧ���±꣺%d\n", p1 - p);


	system("pause");
}