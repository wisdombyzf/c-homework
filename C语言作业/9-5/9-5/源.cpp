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
	printf("����������(���ȴ���3)��-1����\n");
	scanf_s("%d", &n);
	while (n!=-1)											//ͷ�ڵ��������
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

struct qq* nixu(struct qq* one)
{
	struct qq* first= one;
	struct qq* last=one;
	first = first->next;
	last = first;
	first = first->next;
	one->next = NULL;
	while ((first->next) != NULL)
	{
		last->next = one;
		one = last;
		last = first;
		first = first->next;
	}
	last->next = one;
	first->next = last;
	return first;
}

int main()
{
	printf("���ȴ���һ��������\n");
	struct qq *one, *two;
	one = creat();
	printf("����������\n");
	one = nixu(one);
	printf("��ӡ��������\n");
	while ((one->next) != NULL)					//�����ͷ���������
	{
		one = one->next;
		printf("%d\n", one->a);	
	}
	system("pause");
}