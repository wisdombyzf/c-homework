#include <stdio.h>  
#include <stdlib.h>  

int main()
{
	int i, j, k;		//i,j,k�ֱ��Ӧa,b,c�Ķ��� 
	printf("���н��\n");
	for (i = 'x'; i <= 'z'; i++)
	{
		for (j = 'x'; j <= 'z'; j++)
		{
			if (j != i)
			{
				for (k = 'x'; k < 'z'; k++)
				{
					if (k != i&&k != j)
					{
						printf("a��ս%c  b��ս%c  c��ս%c\n", i, j, k);
					}
				}
			}
		}
	}

	printf("����\n");
	for (i = 'x'; i <= 'z'; i++)
	{
		for (j = 'x'; j <= 'z'; j++)
		{
			if (j != i)
			{
				for (k = 'x'; k < 'z'; k++)
				{
					if (k != i&&k != j)
					{
						if (i != 'x'&&k != 'x'&&k != 'z')
						{
							printf("a��ս%c  b��ս%c  c��ս%c", i, j, k);
						}
					}
				}
			}
		}
	}

	system("pause");
}