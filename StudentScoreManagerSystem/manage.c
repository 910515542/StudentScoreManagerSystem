#include "Student.h"

/********************************
函数功能：输入学号搜索学生 
参数：链表头结点、学生人数、课程数目 
返回值：无 
*******************************/
void  SearchbyNum(STU *head, int n, int m)
{
	long num;
	int i;
	int flag = 1;
	printf("\t\t\t");
	scanf("%ld", &num);
	STU *p;
	p = head;
	if (head != NULL)
	{
		do {
			if (p->num == num)
			{
				printf("\t\t\t%-10s\t%-10s\t", "学号", "姓名"); 
				for(i = 0; i < m; i++)
				{
					printf("%-10s\t", courseName[i]);
				}
				printf("%-10s\t%-10s\t%-10s\n", "总分", "平均分", "排名");
				
				printf("\t\t\t");
				printf("%-10ld\t%-10s\t", p->num, p->name);
				for (i = 0; i<m; i++)
				{
					printf("%-10.1f\t", p->score[i]);
				}
				printf("%-10.1f\t%-10.1f\t%-10d\n", p->sum, p->sum / m, p->rankNum);
				flag = 0;
				break;
			}
			p = p->next;

		} while (p != NULL);
		if (flag)
		{
			printf("\t\t\t");
			printf("Not found!\n");
		}
	}
	printf("\t\t\t******************************************************************************\n");

}
/********************************
函数功能：输入学生名字搜索学生 
参数：链表头结点、学生人数、课程数目 
返回值：无 
*******************************/
void  SearchbyName(STU *head, int n, int m)
{
	char name[MAX_LEN];
	int i;
	int flag = 1;
	printf("\t\t\t");
	scanf("%s", name);
	STU *p;
	p = head;
	if (head != NULL)
	{
		do {
			if (strcmp(name, p->name) == 0)
			{
				printf("\t\t\t%-10s\t%-10s\t", "学号", "姓名"); 
				for(i = 0; i < m; i++)
				{
					printf("%-10s\t", courseName[i]);
				}
				printf("%-10s\t%-10s\t%-10s\n", "总分", "平均分", "排名");
				
				printf("\t\t\t");
				printf("%-10ld\t%-10s\t", p->num, p->name);
				for (i = 0; i<m; i++)
				{
					printf("%-10.1f\t", p->score[i]);
				}
				printf("%-10.1f\t%-10.1f\t%-10d\n", p->sum, p->sum / m, p->rankNum);
				flag = 0;
			}
			p = p->next;

		} while (p != NULL);
		if (flag)
		{
			printf("\t\t\t");
			printf("Not found!\n");
		}
	}
	printf("\t\t\t******************************************************************************\n");

}
/********************************
函数功能：输入学号删除学生 
参数：链表头结点、学生人数、课程数目 
返回值：新的链表头结点 
*******************************/
STU* deleteStu(STU *head, int *n, int m)
{
	long num;
	int i;
	int flag = 1;
	char temp[5];
	
	printf("\t\t\tplease input number you want to delete\n");
	printf("\t\t\t");
	scanf("%ld", &num);
	STU *p, *q;
	p = head;
	if (head != NULL)
	{
		do {
			if (p->num == num)
			{
				printf("\t\t\t%-10s\t%-10s\t", "学号", "姓名"); 
				for(i = 0; i < m; i++)
				{
					printf("%-10s\t", courseName[i]);
				}
				printf("%-10s\t%-10s\t%-10s\n", "总分", "平均分", "排名");
				
				printf("\t\t\t");
				printf("%-10ld\t%-10s\t", p->num, p->name);
				for (i = 0; i<m; i++)
				{
					printf("%-10.1f\t", p->score[i]);
				}
				printf("%-10.1f\t%-10.1f\t%-10d\n", p->sum, p->sum / m, p->rankNum);
				flag = 0;
				printf("\t\t\tAre you surn to delete?(yes/no):");
				scanf("%s", temp);
				if(strcmp(temp, "yes") == 0)
				{
					if(p == head)
					{
						head = p->next;
					}
					else
					{
						q->next = p->next;
					}
					free(p);
					*n = *n - 1;
					printf("删除成功！按任意键继续......");
					getche();
				}
				break;
			}
			q = p;
			p = p->next;

		} while (p != NULL);
		if (flag)
		{
			printf("\t\t\t");
			printf("Not found!\n");
		}
	}
	printf("\t\t\t******************************************************************************\n");
	
	return head;
}
/********************************
函数功能：输入学号添加学生 
参数：链表头结点、学生人数、课程数目 
返回值：无 
*******************************/
void addStu(STU *head, int *stuNum, int m)
{
	STU *Nhead = NULL;
	STU *p1, *p2;
	int i, j, n;
	
	printf("please input student number you want to add:");
	scanf("%d", &n);
	*stuNum += n;
	printf("\t\t\tInput student's ID, name and course score");
	printf("(");
	for(j = 0; j < m; j++)
		{
			printf(" %s", courseName[j]);
		}
	printf(" )\n");
	
	// system("cls");
	for (i = 1; i<n + 1; i++)
	{
		p1 = (STU *)malloc(LEN);
		printf("\t\t\t");
		scanf("%ld %s", &p1->num, p1->name);
		for (j = 0; j<m; j++)
		{
			scanf("%f", &p1->score[j]);
		}
		p1->rankNum = 0;
		p1->aver = 0;
		p1->sum = 0;
		p1->next = NULL;
		if (i == 1)
		{
			Nhead = p2 = p1;
		}
		else
		{
			p2->next = p1;
			p2 = p1;
		}
	}
	//将新添加的学生链表连在原链表尾 
	p2 = head;
	while(p2->next)
	{
		p2 = p2->next;
	}
	p2->next = Nhead;
}
/********************************
函数功能：输入学号修改学生信息 
参数：链表头结点、学生人数、课程数目 
返回值：无 
*******************************/
void Modify(STU *head, int n, int m)
{
	long num;
	int i;
	int flag = 1;
	STU *p = head;
		
	printf("\t\t\tplease input number you want to modify\n");
	printf("\t\t\t");
	scanf("%ld", &num);
	if (head != NULL)
	{
		do {
				if (p->num == num)
				{
					printf("\t\t\t%-10s\t%-10s\t", "学号", "姓名"); 
					for(i = 0; i < m; i++)
					{
						printf("%-10s\t", courseName[i]);
					}
					printf("%-10s\t%-10s\t%-10s\n", "总分", "平均分", "排名");
					
					printf("\t\t\t");
					printf("%-10ld\t%-10s\t", p->num, p->name);
					for (i = 0; i<m; i++)
					{
						printf("%-10.1f\t", p->score[i]);
					}
					printf("%-10.1f\t%-10.1f\t%-10d\n", p->sum, p->sum / m, p->rankNum);
					
					printf("\t\t\tplease input the modified information:\n");
					printf("\t\t\t%-10s\t%-10s\t", "学号", "姓名"); 
					for(i = 0; i < m; i++)
					{
						printf("%-10s\t", courseName[i]);
					}
					printf("\n\t\t\t");
					scanf("%ld %s", &p->num, p->name);
					for(i = 0; i < m; i++)
					{
						scanf("%f", &p->score[i]);
					}
					flag = 0;
					printf("修改成功！"); 
				}
				p = p->next;
		}while(p);
		
		if(flag)
		{
			printf("Not find!\n");
		}
	}
}
/********************************
函数功能：计算每门课程各分段人数并显示 
参数：链表头结点、学生人数、课程数目 
返回值：无 
*******************************/
void  StatisticAnalysis(STU *head, int n, int m)
{
	int a[6];
	STU *p;
	p = head;
	int i, j;
	for (i = 0; i<m; i++)
	{
		p = head; // 不要忘了初始化，不然会炸
		for (j = 0; j<6; j++)  // 初始化
		{
			a[j] = 0;
		}
		do {
			if (p->score[i]<60)
			{
				a[0]++;
			}
			else if (p->score[i]<70)
			{
				a[1]++;
			}
			else if (p->score[i]<80)
			{
				a[2]++;
			}
			else if (p->score[i]<90)
			{
				a[3]++;
			}
			else if (p->score[i]<100)
			{
				a[4]++;
			}
			else
			{
				a[5]++;
			}

			p = p->next;

		} while (p != NULL);
		printf("\n\n\n");
		printf("\t\t\t******************************************************************************\n");
		printf("\t\t\t* For course %d:\n", i + 1);
		printf("\t\t\t* <60\t%d\t%.2f%%\n", a[0], 100 * a[0] / 6.0);
		printf("\t\t\t* %d-%d\t%d\t%.2f%%\n", 60, 69, a[1], 100 * a[1] / 6.0);
		printf("\t\t\t* %d-%d\t%d\t%.2f%%\n", 70, 79, a[2], 100 * a[2] / 6.0);
		printf("\t\t\t* %d-%d\t%d\t%.2f%%\n", 80, 89, a[3], 100 * a[3] / 6.0);
		printf("\t\t\t* %d-%d\t%d\t%.2f%%\n", 90, 99, a[4], 100 * a[4] / 6.0);
		printf("\t\t\t* %d\t%d\t%.2f%%\n", 100, a[5], 100 * a[5] / 6.0);
		printf("\t\t\t******************************************************************************\n");

	}
}
/********************************
函数功能：保存至相应文件 
参数：链表头结点、文件名、学生人数、课程数目 
返回值：无
*******************************/
void  WritetoFile(STU *head, char filename[20], int n, int m)
{
	STU *p;
	p = head;
	FILE *fp;
	int i, j;
	printf("\n\n\n");
	printf("\t\t\t******************************************************************************\n");
	if ((fp = fopen(filename, "w")) == NULL)
	{
		printf("\t\t\tFail to open %s\n", filename);
		printf("\t\t\t******************************************************************************\n");
		return;
	}
	if(strcmp(filename, "原始数据.txt") == 0 || strcmp(filename, "学生综合成绩.txt") == 0)
	{
		fprintf(fp, "\t\t\tstudent number:%d(人)\tcourse number:%d(门)\n", n, m);
		fprintf(fp, "%-10s\t\t%-10s\t", "学号", "姓名"); 
		for(i = 0; i < m; i++)
		{
			fprintf(fp, "%-10s\t", courseName[i]);
		}
		fprintf(fp, "%-10s\t%-10s\t%-10s\n", "总分", "平均分", "排名");
		
		for (i = 0; i<n; i++)
		{
			fprintf(fp, "%-10ld\t%-10s\t", p->num, p->name);
			for (j = 0; j<m; j++)
			{
				fprintf(fp, "%-10.1f\t", p->score[j]);
			}
			fprintf(fp, "%-10.1f\t%-10.1f\t%-10d\n", p->sum, p->sum / m, p->rankNum);
			p = p->next;
		}
	}
	else
	{
		if(strcmp(filename, "统计数据.txt") == 0)
		{
			fprintf(fp, "%-10s\t%-5s\t%-3s\t\t%-3s\t%-3s\t\t%-3s\t\t%-3s\t\t%-3s\n", "course", "sum", "averscore", "<60", "[60,70)", "[70,80)", "[80,90)", ">=90");
			for(i = 0; i < m; i++)
			{
				fprintf(fp, "%-10s\t%-5.1f\t%-3.1f\t\t%-3d\t%-3d\t\t%-3d\t\t%-3d\t\t%-3d\n", courseName[i], Course[i].sumscore, Course[i].avescore, Course[i].sectionNum[0],
														  				 Course[i].sectionNum[1], Course[i].sectionNum[2], Course[i].sectionNum[3], Course[i].sectionNum[4]);
			}
		}
		else
		{
			printf("filename is wrong!\n");
			return ;
		}
	}
	{
		
	}
	printf("\t\t\tExport Successfully!\n");
	fclose(fp);
	printf("\t\t\t******************************************************************************\n");

}
/********************************
函数功能：筛选优等生 并保存至文件 
参数：链表头结点、学生人数
返回值：无 
*******************************/
void topStu(STU *head, int n)
{
	STU *p = head;
	FILE *fp;
	int i, flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 1, count = 0;//优等生三个条件 
	
	if((fp = fopen("优等生.txt", "w")) == NULL)
	{
		printf("打开文件失败！\n");
		flag4 = 0;
	}
	for(; p; p= p->next)
	{
		flag1 = 0;//初始化三个条件都不满足 
		flag2 = 0;
		flag3 = 0;
		
		if(p->aver >= 80)
		{
			flag1 = 1;
		}
		if(p->aver >= 60 && p->aver <90)
		{
			for(i = 0; i < n; i++)
			{
				if(p->score[i] >= 90)
				{
					flag2 = 1;
					break;
				}
			}
		}
		if(p->aver < 60)
		{
			for(i = 0; i < n; i++)
			{
				if(p->score[i] == 100)
				{
					flag3 = 1;
					break;
				}
			}
		}
		if(flag1 || flag2 || flag3)//满足一个就是优等生 
		{
			count++;
			printf("%-10ld\t%-10s\n", p->num, p->name);
			if(flag4)
			{
				fprintf(fp, "%-10ld\t%-10s\n", p->num, p->name);
			}
		}
	}
	if(count == 0)
	{
		printf("无优等生!");
		if(flag4)
		fprintf(fp, "无优等生"); 
	}
	else
	{
		printf("优等生共%d人\n", count);
		if(flag4)
		fprintf(fp, "\t优等生共%d人\n", count);
	}
	fclose(fp);
}
/********************************
函数功能：查找学生不及格科目信息并保存 
参数：链表头结点、学生人数
返回值：无 
*******************************/
void failStu(STU *head, int n)
{
	STU *p = head;
	int i, flag1 = 0, flag2 = 1, flag3 = 1;
	FILE *fp;
	
	if((fp = fopen("学生不及格科目.txt", "w")) == NULL)
	{
		printf("打开文件失败\n");
		flag3 = 0;
	}
	for(; p; p = p->next)
	{
		flag1 = 0;
		for(i = 0; i < n; i++)
		{
		//	printf("flag1 = %d score[%d] = %.1f ", flag1, i, p->score[i]);
			if(p->score[i] < 60)
			{
				flag1 = 1;
				break;
			}
		}
		//printf("flag1 = %d\n", flag1);
		if(flag1)
		{
			flag2 = 0;
			printf("%-10ld\t%-10s\t", p->num, p->name);
			if(flag3)
			{
				fprintf(fp, "%-10ld\t%-10s\t", p->num, p->name);
			}
			for(i = 0; i < n; i++)
			{
				if(p->score[i] < 60)
				{
					printf("%-10s:%-5.1f\t", courseName[i], p->score[i]);
					if(flag3)
					{
						fprintf(fp, "%-10s:%-5.1f\t", courseName[i], p->score[i]);
					}
				}
			}
			printf("\n");
			if(flag3)
			fprintf(fp, "\n");
		}
	}
	if(flag2)
	{
		printf("无不及格学生\n");
		if(flag3)
		{
			fprintf(fp, "无不及格学生\n");
		}
	}
	fclose(fp);
}
