#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a[20086];
int binary_search(int d[], int s, int e, int q)
{
	int t;
	if ((q<a[s]) || (q >= a[e]))
	{
		return -1;
	}
	while ((e - s)>1)
	{
		t = (e + s) / 2;
		if (a[t] == q)
		{
			return t;
		}
		if (a[t]>q)
		{
			s = t;
		}
		if (a[t]<q)
		{
			e = t;
		}
	}
	return -1;
}

int main()
{

	int n;
	printf("���������С\n");
	scanf_s("%d", &n);
	printf("��������Ԫ��\n");
	for (int i = 0; i <n; i++)
	{
		scanf_s("%d", &a[i]);
		
	}
	
	printf("������ҵ���ʼ�±�����ֹ�±�����ҵ���\n");
	int s, e, q;
	scanf_s("%d%d%d", &s, &e, &q);
	
	printf("%d", binary_search(a, s, e, q));
	
	system("pause");
}