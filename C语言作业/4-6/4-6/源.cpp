#include<stdio.h>
#include<stdlib.h>

double y(double x)
{
	return 2 * x*x*x - 4 * x*x + 3 * x - 6;
}

int main()
{
	double x=0,sum=1;						//2x^3-4x^2 + 3x - 6 = y  (�˷�����ߵ�������)
	double left, right;
	double l=-10, r=10;
	left = y(l);
	right = y(r);
	sum = y(x);
	if ((int)left==0)
	{
		printf("��Ϊ%lf", l);
	}
	if ((int)right == 0)
	{
		printf("��Ϊ%lf", r);
	}
	if ((int)sum == 0)
	{
		printf("��Ϊ%lf",x);
	}

	while ((sum!=0.000000))				//������Ե�����
	{
		if (sum>0)
		{
			r = x;
			x = (x + l) / 2;
			
		}
		else
		{
			l = x;
			x = (x + r) / 2;
			
		}
		sum = y(x);
	}
	printf("��Ϊ%lf\n",x);
	//printf("%lf", y(x));
	system("pause");


}
