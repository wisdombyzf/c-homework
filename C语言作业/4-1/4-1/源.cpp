#include<stdio.h>
#include<stdlib.h>

int main()
{
	printf("�������\n");
	double grade;
	bool a =true;
	while (a)
	{
		scanf_s("%lf", &grade);
		if (grade < 0 || grade>100)
		{
			printf("����������\n");
		}
		else
		{
			a = false;
		}
	}
	int b = (int)(grade / 10);
	switch (b)
	{
	case 10:
		printf("A");
		break;
	case 9:
		printf("A");
		break;
	case 8:
		printf("B");
		break;
	case 7:
		printf("C");
		break;
	case 6:
		printf("D");
		break;
	default:
		printf("E");
		break;
	}
	system("pause");

}
