#include<stdio.h>
#include<stdlib.h>

int max(int a, int b, int c)
{
	int max;
	a > b ? max = a : max = b;
	max > c ? max = max : max = c;
	return max;
}
int min(int a, int b, int c)
{
	int min;
	a > b ? min = b : min = a;
	min > c ? min =c : min = min;
	return min;
}
int main()
{
	int a, b, c;
	printf("����������\n");
	scanf_s("%d%d%d", &a, &b, &c);
	printf("��Ϊ%d\n", a + b + c);
	printf("ƽ��ֵΪ%d\n", (a + b + c) / 3);
	printf("��Ϊ%d\n", a * b * c);
	printf("��СֵΪ%d\n", min(a, b, c));
	printf("���ֵΪ%d\n", max(a, b, c));
	system("pause");

}