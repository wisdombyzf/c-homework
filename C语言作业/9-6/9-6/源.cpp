#include<stdio.h>
#include<stdlib.h>

struct qq
{
	int a;
	struct qq *next;
};

struct qq* creat()
{
	struct qq *head, *first, *last;
	head = (struct qq*)malloc(sizeof(struct qq));
	first = last = head;
	int n;
	printf("������������-1����\n");
	scanf_s("%d", &n);
	while (n != -1)											//ͷ�ڵ��������
	{
		first = (struct qq*)malloc(sizeof(struct qq));
		last->a = n;
		last->next = first;
		last = first;
		first->next = NULL;
		scanf_s("%d", &n);
	}
	return head;
}

struct qq* find(struct qq* one , int a)
{
	if (one->next == NULL)
	{
		return NULL;
	}
	if (one->a==a)
	{
		return one;
	}	
	one = one->next;
	find(one, a);
}

int main()
{
	printf("���ȴ���һ��������\n");
	struct qq *one, *two;
	one = creat();
	printf("����ݹ���ҵ�ֵ\n");
	int a;
	scanf_s("%d", &a);
	one = find(one,a);
	system("pause");
}