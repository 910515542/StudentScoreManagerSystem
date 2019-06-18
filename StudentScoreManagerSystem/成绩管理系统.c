/*********************************
运行该程序时请把终端控制台放至最大，以免无法完全显示 
***************************/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<stdlib.h>

#define   MAX_LEN  10                	   /* 字符串最大长度 */
#define   STU_NUM 30                       /* 最多的学生人数 */
#define   COURSE_NUM 6                     /* 最多的考试科目数 */
#define   LEN sizeof(struct Student)	   /*结构体类型字节长度*/ 

typedef struct Student
{
	long num;	                    /* 每个学生的学号 */
	char name[MAX_LEN];            	/* 每个学生的姓名 */
	float score[COURSE_NUM];	    /* 每个学生COURSE_NUM门功课的成绩 */
	float sum;                      /* 每个学生的总成绩 */
	float aver;					/* 每个学生的平均成绩 */
	int rankNum;					// 每个学生排名 
	struct Student *next;
}STU;

struct {
	float avescore, sumscore;
	int sectionNum[5];
} Course[COURSE_NUM];

char courseName[COURSE_NUM][MAX_LEN];                  //保存课程名称 

int   Menu(void);                                      //创建菜单
void  Print(STU *head, int n, int m);                  //打印学生信息 
void print1(int courseNum);                             //打印课程信息 
void  AverSumofEveryStudent(STU *head, int n, int m);  //计算每门课程的总分和平均分
void  AverSumofEveryCourse(STU *head, int n, int m);   //计算每个学生的总分和平均分
STU  *SortbyScore(STU *head, int n);				   //按每个学生的总分由高到低排出名次表
STU  *Creat(int n, int m);   							//创建链表并录入信息
STU  *Creat1(int n, int m);
STU  *SortbyNumber1(STU *head, int n);                  //按学号由高到低排出成绩表
STU  *SortbyNum(STU *head);                            //按学号由低到高排出成绩表
STU  *SortbyName(STU *head, int n);                    //按姓名的字典顺序排出成绩表
void  SearchbyNum(STU *head, int n, int m);            //按学号查询学生排名及其考试成绩
void  SearchbyName(STU *head, int n, int m);           //按姓名查询学生排名及其考试成绩
STU* deleteStu(STU *head, int *n, int m);			   //按学号删除学生信息
void addStu(STU *head, int *stuNum, int m);			   //添加学生信息 
void Modify(STU *head, int n, int m);				   //修改学生信息 
void  StatisticAnalysis(STU *head, int n, int m);      //按类别及比例输出
void topStu(STU *head, int n);						   //查找优等生并保存至文件 
void failStu(STU *head, int n);						   //查找学生不及格科目并保存至文件 
void  WritetoFile(STU *head, char filename[20], int n, int m); //将每个学生的纪录信息写入文件

int main()
{
	int n = 0, m = 0;//学生人数、课程数目 
	int i, j, flag = 0; //判断是否计算了总分，以免未计算总分就排名 
	char filename[20];
	STU *head = NULL;  //定义头节点
	while (1)
	{
		system("cls"); 
		i = Menu();
		if (i == 1)
		{
			system("cls");  //清屏
			printf("\t\t\t******************************************************************************\n");
			printf("\t\t\tInput student number(n<30):"); //输入学生数
			scanf("%d", &n);
			printf("\t\t\tInput course number(m<=6):");
			scanf("%d", &m);
			printf("\t\t\tInput course name(name<10):\n");
			printf("\t\t\t");
			fflush(stdin);
			for(j = 0; j < m; j++)
			{
				scanf("%s", courseName[j]);
			}
		}
		switch (i)
		{
		case 1:
			printf("\t\t\tInput student's ID, name and course score");
			printf("(");
			for(j = 0; j < m; j++)
			{
				printf(" %s", courseName[j]);
			}
			printf(" )\n");
			head = Creat(n, m);
			printf("录入数据成功!按任意键继续......");
			getche(); 
			system("cls");  
			break;
		case 2:
			system("cls");  
			AverSumofEveryCourse(head, n, m);
			print1(m); 
			printf("数据计算完毕!按任意键继续......");
			getche(); 
			break;
		case 3:
			system("cls");  
			AverSumofEveryStudent(head, n, m);
			flag = 1; 
			printf("数据计算完毕!按任意键继续......");
			getche(); 
			break;
		case 4:
			system("cls");  
			printf("\n\n\n");
			printf("\t\t\tSort in ascending order by score:\n");
			if(flag)
			{
				head = SortbyScore(head, n);
				Print(head, n, m);
				printf("数据排序完毕!按任意键继续......");
			}
			else
			{
				printf("未计算总分,无法排序，按任意键继续......");
			}
			getche(); 
			break;
		case 5:
			system("cls");  
			printf("\n\n\n");
			printf("\t\t\tSort from high to low in ascending order by number:\n");
			head = SortbyNumber1(head, n);
			Print(head, n, m);
			printf("数据排序完毕!按任意键继续......");
			getche(); 
			break;
		case 6:
			system("cls"); 
			printf("\n\n\n");
			printf("\t\t\tSort from low to high in ascending order by number:\n");
			head = SortbyNum(head);
			Print(head, n, m);
			printf("数据排序完毕!按任意键继续......");
			getche();
			break;
		case 7:
			system("cls");  
			printf("\n\n\n");
			printf("\t\t\tSort in dictionary order by name:\n");
			head = SortbyName(head, n);
			Print(head, n, m);
			printf("数据排序完毕!按任意键继续......");
			getche();
			break;
		case 8:
			system("cls");  
			printf("\n\n\n");
			printf("\t\t\t******************************************************************************\n");
			printf("\t\t\tInput the number you want to search:\n");
			SearchbyNum(head, n, m);
			printf("按任意键继续......");
			getche();	
			break;
		case 9:
			system("cls");  
			printf("\n\n\n");
			printf("\t\t\t******************************************************************************\n");
			printf("\t\t\tInput the name you want to search:\n");
			SearchbyName(head, n, m);
			printf("按任意键继续......");
			getche();
			break;
		case 10:
			system("cls");
			printf("\t\t\t******************************************************************************\n");
			head = deleteStu(head, &n, m);
			printf("按任意键继续......");
			getche();
			break;
		case 11:
			system("cls");  
			printf("\n\n\n");
			addStu(head, &n, m);
			printf("添加成功！按任意键继续......");
			getche();
			break;
		case 12:
				system("cls");
				printf("\n\n\n");
				Modify(head, n, m);
				printf("按任意键继续......");
				getche();
				break;
		case 13:
			system("cls");  
			printf("\n\n\n");
			topStu(head, m);
			printf("按任意键继续......");
			getche();
			break;
		case 14:
			system("cls");  
			printf("\n\n\n");
			failStu(head, m);
			printf("按任意键继续......");
			getche();
			break;
		case 15:
			system("cls");  
			printf("\n\n\n");
			Print(head, n, m);
			printf("按任意键继续......");
			getche();
			break;
		case 16:
			system("cls");
			printf("\t\t\t请在执行相应计算操作后保存至相应文件中，计算、排序后将无法再进行原始数据保存\n");
			printf("\t\t\tplease file name(原始数据.txt 统计数据.txt 学生综合成绩.txt): ");
			fflush(stdin);
			gets(filename);
			WritetoFile(head, filename, n, m);
			printf("按任意键继续......");
			getche();
			break;
		case 0:
			system("cls");  
			printf("\n\n\n");
			printf("\t\t\t******************************************************************************\n");
			printf("\t\t\tEnd of program!\n");
			printf("\t\t\t******************************************************************************\n");
			return 0;
		default:
			system("cls");  
			printf("\n\n\n");
			printf("\t\t\t******************************************************************************\n");
			printf("\t\t\tInput error!\n");
			printf("\t\t\t******************************************************************************\n");

		}

	}

	return 0;


}
// 创建菜单
int   Menu(void)
{
	int i;
	system("title 学生成绩管理系统V1.0  作者: 尹小轩");
	printf("\n\n");
	printf("\t\t\t                         学生成绩管理系统V1.0\n");
	printf("\t\t\t******************************************************************************\n");
	printf("\t\t\t*                Management for Students' scores                             *\n");
	printf("\t\t\t*                1.  Input record                                            *\n");
	printf("\t\t\t*                2.  Caculate each section and average score of every course *\n");
	printf("\t\t\t*                3.  Caculate total and average score of every student       *\n");
	printf("\t\t\t*                4.  Sort in descending order by  total score                *\n");
	printf("\t\t\t*                5.  Sort form high to low in ascending order by number      *\n");
	printf("\t\t\t*                6.  Sort from low to high in ascending order by number      *\n");
	printf("\t\t\t*                7.  Sort in dictionary order by name                        *\n");
	printf("\t\t\t*                8.  Search by number                                        *\n");
	printf("\t\t\t*                9.  Search by name                                          *\n");
	printf("\t\t\t*                10. Delete student by number                                *\n");
	printf("\t\t\t*                11. Add student(s)                                          *\n");
	printf("\t\t\t*                12. Modify student informaton                               *\n");
	printf("\t\t\t*                13. search and save top student(s)                          *\n");
	printf("\t\t\t*                14. search and save student(s) failling subject             *\n");
	printf("\t\t\t*                15. print link-lists                                        *\n");
	printf("\t\t\t*                16. Write to a file                                         *\n");
	printf("\t\t\t*                0.  Exit                                                    *\n");
	printf("\t\t\t******************************************************************************\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\t\t*****************Please Input your choice:");
	scanf("%d", &i);
	return i;

}

// 创建链表
STU *Creat(int n, int m) {
	STU *head = NULL;
	STU *p1, *p2;
	int i, j;
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
			head = p2 = p1;
		}
		else
		{
			p2->next = p1;
			p2 = p1;
		}
	}
	return(head);
}

STU *Creat1(int n, int m)
{
	STU *head;
	STU *p1, *p2;
	int i, j;
	// system("cls");
	for (i = 1; i<n + 1; i++)
	{
		p1 = (STU *)malloc(LEN);
		p1->next = NULL;
		if (i == 1)
		{
			head = p2 = p1;
		}
		else
		{
			p2->next = p1;
			p2 = p1;
		}
	}
	return(head);
}
void  AverSumofEveryCourse(STU *head, int n, int m)
{
	STU *p;
	int i;
	char ch;
	float sum;
	
	memset(Course, 0, sizeof(Course));     //初始化数组Course 
	p = head;
	if (head != NULL)									/*防止没有输入学生信息head=NULL时而进行head->next错误操作*/
	{
		for (i = 0; i<m; i++)
		{
			p = head;
			sum = 0.0;
			do {
				sum += p->score[i];
				if(p->score[i] < 60)
				{
					Course[i].sectionNum[0]++;
				}
				if(p->score[i] >= 60 && p->score[i] < 70)
				{
					Course[i].sectionNum[1]++;
				}
				if(p->score[i] >= 70 && p->score[i] < 80)
				{
					Course[i].sectionNum[2]++;
				}
				if(p->score[i] >= 80 && p->score[i] < 90)
				{
					Course[i].sectionNum[3]++;
				}
				if(p->score[i] >= 90)
				{
					Course[i].sectionNum[4]++;
				}
				p = p->next;
			} while (p != NULL);
			Course[i].avescore = sum / n;
			Course[i].sumscore = sum;
		}
	}
	else
	{
		printf("Please input student information before doing this\n!!!\n");
	} 
}

void  AverSumofEveryStudent(STU *head, int n, int m)
{
	STU *p;
	int i, j;
	p = head;
	if (head != NULL)
	{
		printf("\n\n\n");
		printf("\t\t\t******************************************************************************\n");
		for (i = 0; i<n; i++)
		{
			p->sum = 0.0;
			for (j = 0; j<m; j++)
			{
				p->sum += p->score[j];
			}
			p->aver = p->sum / m;
			printf("\t\t\tstudent %-10s:    sum=%-4.1f, aver=%-4.1f\n", p->name, p->sum, p->aver);
			p = p->next;
		}
		printf("\t\t\t******************************************************************************\n");
	}
	else
	{
		printf("Please input student information before doing this!!!\n");
	} 
}

STU  *SortbyScore(STU *head, int n)   //冒泡排序 
{
	STU *endpt;    //控制循环比较
	STU *p;        //临时指针变量
	STU *p1, *p2;
	int data = -1, ranknum = 0;//给学生排名的中间变量 
	
	p1 = (STU *)malloc(LEN);
	p1->next = head;        //注意理解：我们增加一个节点，放在第一个节点的前面，主要是为了便于比较。因为第一个节点没有前驱，我们不能交换地址
	head = p1;                 //让head指向p1节点，排序完成后，我们再把p1节点释放掉

	for (endpt = NULL; endpt != head; endpt = p) 
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)//如果一次都没交换，显然p = head，即已经排好序，外面循环则终止 
		{
			if (p1->next->sum < p1->next->next->sum)  //如果前面的节点键值比后面节点的键值大，则交换
			{
				p2 = p1->next->next;			//		例如链表p1->a->b->c->......										 
				p1->next->next = p2->next;		//		先把b保存到p2，即p2 =  p1->next->next							
				p2->next = p1->next;			//		再让a下一个指向c,a->c；b下一个指向a，b->a。						
				p1->next = p2;					//		再让p1指向p2，即p1指向b：p1->b									
				p = p1->next->next;				//		综合上面即可得出：p1->b->a->c; 									
			}									//		p = a? 若后面都没再交换，显然，从a->c->......后面都已经排好序了	 
		}										//		则下一次循环比较时只需检查a节点之前的排序情况了 
	}
	
	p1 = head;              //把p1的信息去掉
	head = head->next;       //让head指向排序后的第一个节点
	free(p1);          //释放p1
	
	//总分从高到低排完序后给每个同学排名，相同总分名次并列 
	for(p = head; p; p = p->next)
	{
		if(p->sum == data)
		{
			p->rankNum = ranknum;
		}
		else
		{
			ranknum++;
			p->rankNum = ranknum;
			data = p->sum;
		}
	}

	return head;
}

STU  *SortbyNumber1(STU *head, int n)
{
	STU *endpt;    //控制循环比较
	STU *p;        //临时指针变量
	STU *p1, *p2;

	p1 = (STU *)malloc(LEN);
	p1->next = head;        //注意理解：我们增加一个节点，放在第一个节点的前面，主要是为了便于比较。因为第一个节点没有前驱，我们不能交换地址
	head = p1;                 //让head指向p1节点，排序完成后，我们再把p1节点释放掉

	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (p1->next->num < p1->next->next->num)  //如果前面的节点键值比后面节点的键值大，则交换
			{
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;
				p = p1->next->next;
			}
		}
	}

	p1 = head;              //把p1的信息去掉
	head = head->next;       //让head指向排序后的第一个节点
	free(p1);          //释放p1
	p1 = NULL;          //p1置为NULL，保证不产生“野指针”，即地址不确定的指针变量

	return head;
}

STU *SortbyNum(STU *head)    //插入法排序 
{
	STU *first;    //为原链表剩下用于直接插入排序的节点头指针
	STU *t;        //临时指针变量：插入节点
	STU *p, *q;     //临时指针变量,q作为有序链表的头,p保存前一个节点 

	if(head == NULL)
	{
		return head;
	}
	first = head->next;      //原链表剩下用于直接插入排序的节点链表
	head->next = NULL;       //将第一个节点作为第一个有序链表

	while (first != NULL)        //遍历剩下无序的链表
	{
		//注意：这里for语句就是体现直接插入排序思想的地方
		for (t = first, q = head; ((q != NULL) && (q->num < t->num)); p = q, q = q->next);  //遍历有序链表，无序节点在有序链表中找插入的位置

		first = first->next; //无序链表中的节点离开，以便它插入到有序链表中

		if (q == head)      //插在第一个节点之前
		{
			head = t;
		}
		else            //p是q的前驱
		{
			p->next = t;
		}
		t->next = q;     //完成插入动作
						 //first = first->next;
	}
	return head;
}

STU  *SortbyName(STU *head, int n)
{
	STU *endpt;    //控制循环比较
	STU *p;        //临时指针变量
	STU *p1, *p2;

	p1 = (STU *)malloc(LEN);
	p1->next = head;        //注意理解：我们增加一个节点，放在第一个节点的前面，主要是为了便于比较。因为第一个节点没有前驱，我们不能交换地址
	head = p1;                 //让head指向p1节点，排序完成后，我们再把p1节点释放掉

	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (strcmp(p1->next->name, p1->next->next->name)>0)  //如果前面的节点键值比后面节点的键值大，则交换
			{
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;     //结合第4点理解
				p = p1->next->next;   //结合第6点理解
			}
		}
	}

	p1 = head;              //把p1的信息去掉
	head = head->next;       //让head指向排序后的第一个节点
	free(p1);          //释放p1
	p1 = NULL;          //p1置为NULL，保证不产生“野指针”，即地址不确定的指针变量

	return head;
}


void Print(STU *head, int n, int m)
{
	STU *p;
	int i;
	p = head;

	if (head != NULL)        //只要不是空链表，就输出链表中所有节点
	{
		printf("\t\t\t******************************************************************************\n");
		printf("\t\t\t%-10s\t%-10s\t", "学号", "姓名"); 
		for(i = 0; i < m; i++)
		{
			printf("%-10s\t", courseName[i]);
		}
		printf("%-10s\t%-10s\t%-10s\n", "总分", "平均分", "排名"); 
		do
		{

			printf("\t\t\t%-10ld\t%-10s\t", p->num, p->name);
			for (i = 0; i<m; i++)
			{
				printf("%-10.1f\t", p->score[i]);
			}
			printf("%-10.1f\t%-10.1f\t%-10d\n", p->sum, p->sum / m, p->rankNum);
			p = p->next;     //移到下一个节点
		} while (p != NULL);
		printf("\t\t\t******************************************************************************\n");
	}
}

void print1(int courseNum)
{
	int i;
	
	printf("\t\t\t%-10s\t%-5s\t%-3s\t%-3s\t%-3s\t\t%-3s\t\t%-3s\t\t%-3s\n", "course", "sum", "averscore", "<60", "[60,70)", "[70,80)", "[80,90)", ">=90");
	for(i = 0; i < courseNum; i++)
	{
		printf("\t\t\t%-10s\t%-5.1f\t%-3.1f\t\t%-3d\t%-3d\t\t%-3d\t\t%-3d\t\t%-3d\n", courseName[i], Course[i].sumscore, Course[i].avescore, Course[i].sectionNum[0],
										  				 Course[i].sectionNum[1], Course[i].sectionNum[2], Course[i].sectionNum[3], Course[i].sectionNum[4]);
	}
}

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




