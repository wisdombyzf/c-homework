#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*����ѧ������ϵͳ�Ĳ˵�(^_^)
Ҳ����ذɣ�*/

/*�ṹ�嶨�����*/
struct student
{
	char  num[20];
	char name[10];
	float GPA;
	int  many;

}stu;

/*����*/
void help()
{
	printf("******û�а���********\n");
}

/*��һ��������Ϣ���������ļ��� */
void create()
{
	system("cls");
	char ch;
	FILE *fp;
	if ((fp = fopen("zf.dat", "wb+")) == NULL)
	{
		printf("�ļ�������\n");
		exit(0);
	}
	//�ļ��Ƿ����

	do
	{
		printf("������ɼ���--���:\t");
		getchar();
		gets_s(stu.num);
		printf("����:\t");
		gets_s(stu.name);
		printf("�ɼ�:\t");
		scanf("%f", &stu.GPA);
		printf("ѧ��:\t");
		scanf("%d", &stu.many);
		if (fwrite(&stu, sizeof(struct student), 1, fp) != 1)
		{
			printf("�ļ�������\n");
			exit(0);
		}

		printf("�Ƿ��������y or n ?\t");
		getchar();
		ch = getchar();
	} while (ch == 'y');
	fclose(fp);

}

/*��ѯ*/
void find()
{
	int a, b = 0;
	char ch[20];
	FILE *fp;
	if ((fp = fopen("zf.dat", "rb")) == NULL)
	{
		printf("cannot open file\n");
		exit(0);
	}
	printf("������Ҫ��ѯ�ĳɼ��ķ�ʽ\n\t1.��� 2.����:\n\t��ѡ�� 1 or 2 \t");
	scanf("%d", &a);
	if (a == 1)
	{
		getchar();
		printf("������ɼ��ı��:\t");
		gets_s(ch);
		while (fread(&stu, sizeof(struct student), 1, fp) == 1)
			if (strcmp(stu.num, ch) == 0)
			{
				b = 1;
				printf("���\t����\t�ɼ�\t\tѧ��\n");
				printf("%s\t%s\t%.3f\t\t%d\n", stu.num, stu.name, stu.GPA, stu.many);
			}
		if (b == 0) printf("�Բ���û���ҵ������Ϣ��\n");
	}
	else if (a == 2)
	{
		printf("������ɼ�������:\t");
		getchar();
		gets_s(ch);
		while (fread(&stu, sizeof(struct student), 1, fp) == 1)
			if (strcmp(stu.name, ch) == 0)
			{
				b = 1;
				printf("���\t����\t�ɼ�\t\tѧ��\n");
				printf("%s\t%s\t%.3f\t\t%d\n", stu.num, stu.name, stu.GPA, stu.many);
			}
		if (b == 0) printf("input error!\n");
	}
	fclose(fp);
}

/*���*/
void add()
{
	char ch;
	FILE *fp;
	if ((fp = fopen("zf.dat", "ab")) == NULL)
	{
		printf("�ļ�������\n");
		exit(0);
	}

	do
	{
		printf("������Ҫ��ӳɼ���--���:\t");
		getchar();
		gets_s(stu.num);
		printf("����:\t");
		gets_s(stu.name);
		printf("GPA:\t");
		scanf("%f", &stu.GPA);
		printf("ѧ��:\t");
		scanf("%d", &stu.many);
		if (fwrite(&stu, sizeof(struct student), 1, fp) != 1)
		{
			printf("�ļ�������\n");
			exit(0);
		}

		printf("�Ƿ��������y or n ?\t");
		getchar();
		ch = getchar();
	} while (ch == 'y' || ch == 'Y');
	fclose(fp);
}

/*����ĵ��е���Ϣ*/
void display()
{
	FILE *fp;
	if ((fp = fopen("zf.dat", "rb")) == NULL)
	{
		printf("�ļ�������\n");
		return;
	}
	printf("���\t����\t�ɼ�\t\tѧ��\n");
	while (fread(&stu, sizeof(struct student), 1, fp) == 1)
	{
		printf("%s\t%s\t%.3f\t\t%d\n", stu.num, stu.name, stu.GPA, stu.many);
	}
	fclose(fp);
}

/*ɾ�� */
void shanchu()
{
	FILE *fp2;
	int a, b = 0, c = 0, n = 0;
	char ch[20], ck;
	FILE *fp;

	do {
		if ((fp = fopen("zf.dat", "rb")) == NULL)
		{
			printf("cannot open file\n");
			exit(0);
		}
		if ((fp2 = fopen("temp.dat", "wb")) == NULL)
		{
			printf("cannot open file\n");
			exit(0);
		}
		printf("������Ҫɾ���ɼ��ı��:\t");
		scanf("%s", ch);
		n++;
		while (fread(&stu, sizeof(struct student), 1, fp) == 1)
		{
			if ((strcmp(stu.num, ch) == 0))
			{
				b = 1;
				printf("���\t����\t�ɼ�\t\tѧ��\n");
				printf("%s\t%s\t%.3f\t\t%d\n", stu.num, stu.name, stu.GPA, stu.many);
			}
			else if (strcmp(stu.num, ch) != 0)
				fwrite(&stu, sizeof(struct student), 1, fp2);
		}
		if (b == 0)
		{
			printf("\tû���ҵ������Ϣ��\n");
			getchar();
		}
		rewind(fp);
		getchar();
		getchar();
		printf("ɾ���ɹ���");
		getchar();
		printf("�Ƿ����ɾ����enter 'y' or 'n' \t");
		ck = getchar();
		fclose(fp);
		fclose(fp2);
		remove("zf.dat");
		rename("temp.dat", "zf.dat");
	} while (ck == 'y');
	if (b != 0)
		printf("\t����ɹ���\n");

}

/*�޸�*/
void change()
{
	shanchu();
	add();
}

/*����*/
void paiming()
{



}

/*�˵�*/
void interface()
{
	int choose;
	printf("\t\t\t******ѧ������ϵͳ**********\n");
	printf("\t\t\t****1.¼��		****\n");
	printf("\t\t\t****2.��ʾ		****\n");
	printf("\t\t\t****3.��ѯ		****\n");
	printf("\t\t\t****4.���		****\n");
	printf("\t\t\t****5.�޸�		****\n");
	printf("\t\t\t****6.ɾ��		****\n");
	printf("\t\t\t****0.����		****\n");
	printf("\t\t\t****************************\n");
	printf("��ѡ�� 0--7:\n");
	printf("���������ѡ��\n");
	scanf("%d", &choose);
	while (choose>7 || choose<0)
	{
		printf("��������������\n");
		getchar();			//û��������������ᱬ
		scanf("%d", &choose);
	}
	switch (choose)
	{

	case 0:
		help();
		break;
	case 1:
		create();
		break;
	case 2:
		display();
		break;
	case 3:
		find();
		break;
	case 4:
		add();
		break;
	case 5:
		change();
		break;
	case 6:
		shanchu();
		break;
	case 7:
		paiming();
		break;

	}
}

/*������*/
int main()
{
	while (1)
	{
		interface();
		system("pause");
		system("cls");
	}
}