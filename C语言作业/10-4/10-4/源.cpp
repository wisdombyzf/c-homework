#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*�ṹ�嶨�����*/
struct student
{
	char name[10];
	char  author[20];
	char pulish[30];
	char price[20];
	char num[10];
	char lei[20];
}book;

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
		printf("�������鼮������:\t");
		getchar();
		gets_s(book.name);

		printf("����:\t");
		gets_s(book.author);

		printf("������:\t");
		gets_s(book.pulish);
		
		printf("�۸�:\t");
		gets_s(book.price);
		
		printf("�����Ŀ:\t");
		gets_s(book.num);
		
		printf("����:\t");
		gets_s(book.lei);
		if (fwrite(&book, sizeof(struct student), 1, fp) != 1)
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
	printf("������Ҫ��ѯ�ķ�ʽ\n\t1.���� 2.����:\n\t��ѡ�� 1 or 2 \t");
	scanf("%d", &a);
	if (a == 1)
	{
		printf("����������:\t");
		getchar();
		gets_s(ch);
		while (fread(&book, sizeof(struct student), 1, fp) == 1)
			if (strcmp(book.name, ch) == 0)
			{
				b = 1;
				printf("����\t����\t������\t����\t�����Ŀ\t���\n");
				printf("%s\t%s\t%s\t%s\t%s\t%s\n", book.name, book.author, book.pulish, book.price,book.num,book.lei);
			}
		if (b == 0) printf("input error!\n");
	}
	else if (a == 2)
	{
		printf("����������:\t");
		getchar();
		gets_s(ch);
		while (fread(&book, sizeof(struct student), 1, fp) == 1)
			if (strcmp(book.name, ch) == 0)
			{
				b = 1;
				printf("����\t����\t������\t����\t�����Ŀ\t���\n");
				printf("%s\t%s\t%s\t%s\t%s\t%s\n", book.name, book.author, book.pulish, book.price, book.num, book.lei);
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
		printf("�������鼮������:\t");
		getchar();
		gets_s(book.name);

		printf("����:\t");
		gets_s(book.author);

		printf("������:\t");
		gets_s(book.pulish);

		printf("�۸�:\t");
		gets_s(book.price);

		printf("�����Ŀ:\t");
		gets_s(book.num);

		printf("����:\t");
		gets_s(book.lei);
		if (fwrite(&book, sizeof(struct student), 1, fp) != 1)
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

/*����ĵ��е���Ϣ*/
void display()
{
	FILE *fp;
	if ((fp = fopen("zf.dat", "rb")) == NULL)
	{
		printf("�ļ�������\n");
		return;
	}
	printf("����\t����\t������\t����\t�����Ŀ\t���\n");
	while (fread(&book, sizeof(struct student), 1, fp) == 1)
	{
		printf("%s\t%s\t%s\t%s\t%s\t%s\n", book.name, book.author, book.pulish, book.price, book.num, book.lei);
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
		printf("������Ҫɾ��������:\t");
		scanf("%s", ch);
		n++;
		while (fread(&book, sizeof(struct student), 1, fp) == 1)
		{
			if ((strcmp(book.name, ch) == 0))
			{
				b = 1;
				printf("����\t����\t������\t����\t�����Ŀ\t���\n");
				printf("%s\t%s\t%s\t%s\t%s\t%s\n", book.name, book.author, book.pulish, book.price, book.num, book.lei);
			}
			else if (strcmp(book.name, ch) != 0)
				fwrite(&book, sizeof(struct student), 1, fp2);
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


/*�˵�*/
void interface()
{
	int choose;
	printf("\t\t\t******ͼ�����ϵͳ**********\n");
	printf("\t\t\t****1.¼��		****\n");
	printf("\t\t\t****2.��ʾ		****\n");
	printf("\t\t\t****3.��ѯ		****\n");
	printf("\t\t\t****4.���		****\n");
	printf("\t\t\t****5.�޸�		****\n");
	printf("\t\t\t****6.ɾ��		****\n");
	printf("\t\t\t****0.����		****\n");
	printf("\t\t\t****************************\n");
	printf("\t\t\t*������û��˿����׳�ԣ���С�Ĳ���*\n");
	printf("��ѡ�� 0--6:\n");
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