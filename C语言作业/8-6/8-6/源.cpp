#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*�����ö�ά����*/

void xipai(int *p)
{
	srand((unsigned)time(NULL));
	int *pp = p;
	int n = 100;
	while (n--)
	{
		int q;
		int t=rand()%52;
		q = *(p + t);
		*(p + t) = *p;
		*p = q;
	}
}

void fapai(int *p)
{
	int dui = 0;
	for (int  i = 0; i <4; i++)
	{
		dui++;
		printf("��%d�ѣ�", dui);
		for (int  k= 1; (k%14)!=0; k++)
		{
			int huase;
			huase = (*p) / 13;
			switch (huase)
			{
			case 0:
				printf("���ң�");
				break;
			case 1:
				printf("÷����");
				break;
			case 2:
				printf("���飺");
				break;
			case 3:
				printf("���ң�");
				break;
			}
			int o = (*p) % 13;
			if (o==0)
			{
				printf("A");
			}
			if (o==11)
			{
				printf("J");
			}
			if (o==12)
			{
				printf("Q");
			}
			if (o==1)
			{
				printf("K");
			}
			if ((o>1)&&(o<11))
			{
				printf("%d", o);
			}
			printf("   ");
			p++;
		}
		printf("\n");
	}
}

int main()
{
	printf("\t�˿���ϴ�Ʒ��Ƴ���\n");
	int a[51];
	int n = 52;
	while (n-1)
	{
		a[n-1] = n;
		n--;
	}
	a[0] = 1;
	int *p = a;
	xipai(p);

	p = a;
	fapai(p);
	system("pause");
	return 0;
}