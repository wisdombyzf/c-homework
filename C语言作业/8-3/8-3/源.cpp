#include<stdio.h>
#include<stdlib.h>
/*
OJ��û�й�������
*/

int main()
{
	int x, y;
	printf("����������������\n");
	while (scanf_s("%d%d", &x, &y))
	{
		printf("�������Ԫ��\n");
		int **matrix = (int **)malloc(sizeof(int *) * x);
		for (int i = 0; i < x; i++)
		{
			*(matrix + i) = (int *)malloc(sizeof(int) * y);
			for (int k = 0; k < y; k++)
			{
				scanf_s("%d", (*(matrix + i) + k));
			}
		}
		printf("ת�ú�ľ���Ϊ\n");

		for (int i = 0; i < y; i++)
		{
			for (int k = 0; k < x; k++)
			{
				printf("%d ", *(*(matrix + k) + i));
			}
			printf("\n");
		}
	}

	system("pause");

}