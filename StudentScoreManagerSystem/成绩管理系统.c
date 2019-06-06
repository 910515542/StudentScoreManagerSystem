/*********************************
���иó���ʱ����ն˿���̨������������޷���ȫ��ʾ 
***************************/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<stdlib.h>

#define   MAX_LEN  10                	   /* �ַ�����󳤶� */
#define   STU_NUM 30                       /* ����ѧ������ */
#define   COURSE_NUM 6                     /* ���Ŀ��Կ�Ŀ�� */
#define   LEN sizeof(struct Student)		/*�ṹ�������ֽڳ���*/ 

typedef struct Student
{
	long num;	                    /* ÿ��ѧ����ѧ�� */
	char name[MAX_LEN];            	/* ÿ��ѧ�������� */
	float score[COURSE_NUM];	    /* ÿ��ѧ��COURSE_NUM�Ź��εĳɼ� */
	float sum;                      /* ÿ��ѧ�����ܳɼ� */
	float aver;						/* ÿ��ѧ����ƽ���ɼ� */
	int rankNum;					// ÿ��ѧ������ 
	struct Student *next;
}STU;

struct {
	float avescore, sumscore;
	int sectionNum[5];
} Course[COURSE_NUM];

char courseName[COURSE_NUM][MAX_LEN];                  //����γ����� 

int   Menu(void);                                      //�����˵�
void  Print(STU *head, int n, int m);                  //��ӡѧ����Ϣ 
void print1(int courseNum);                             //��ӡ�γ���Ϣ 
void  AverSumofEveryStudent(STU *head, int n, int m);  //����ÿ�ſγ̵��ֺܷ�ƽ����
void  AverSumofEveryCourse(STU *head, int n, int m);   //����ÿ��ѧ�����ֺܷ�ƽ����
STU  *SortbyScore(STU *head, int n);				   //��ÿ��ѧ�����ܷ��ɸߵ����ų����α�
STU  *Creat(int n, int m);   							//��������¼����Ϣ
STU  *Creat1(int n, int m);
STU  *SortbyNumber1(STU *head, int n);                  //��ѧ���ɸߵ����ų��ɼ���
STU  *SortbyNum(STU *head);                            //��ѧ���ɵ͵����ų��ɼ���
STU  *SortbyName(STU *head, int n);                    //���������ֵ�˳���ų��ɼ���
void  SearchbyNum(STU *head, int n, int m);            //��ѧ�Ų�ѯѧ���������俼�Գɼ�
void  SearchbyName(STU *head, int n, int m);           //��������ѯѧ���������俼�Գɼ�
STU* deleteStu(STU *head, int *n, int m);			   //��ѧ��ɾ��ѧ����Ϣ
void addStu(STU *head, int *stuNum, int m);			   //���ѧ����Ϣ 
void Modify(STU *head, int n, int m);				   //�޸�ѧ����Ϣ 
void  StatisticAnalysis(STU *head, int n, int m);      //����𼰱������
void topStu(STU *head, int n);						   //�����ŵ������������ļ� 
void failStu(STU *head, int n);						   //����ѧ���������Ŀ���������ļ� 
void  WritetoFile(STU *head, char filename[20], int n, int m); //��ÿ��ѧ���ļ�¼��Ϣд���ļ�
STU  *ReadfromFile(STU *head, int *n, int *m);         //���ļ��ж���ÿ��ѧ���ļ�¼��Ϣ����ʾ

int main()
{
	int n = 0, m = 0;//ѧ���������γ���Ŀ 
	int i, j, flag = 0; //�ж��Ƿ�������ܷ֣�����δ�����ܷ־����� 
	char filename[20];
	STU *head = NULL;  //����ͷ�ڵ�
	while (1)
	{
		system("cls"); 
		i = Menu();
		if (i == 1)
		{
			system("cls");  //����
			printf("\t\t\t******************************************************************************\n");
			printf("\t\t\tInput student number(n<30):"); //����ѧ����
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
			printf("¼�����ݳɹ�!�����������......");
			getche(); 
			system("cls");  
			break;
		case 2:
			system("cls");  
			AverSumofEveryCourse(head, n, m);
			print1(m); 
			printf("���ݼ������!�����������......");
			getche(); 
			break;
		case 3:
			system("cls");  
			AverSumofEveryStudent(head, n, m);
			flag = 1; 
			printf("���ݼ������!�����������......");
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
				printf("�����������!�����������......");
			}
			else
			{
				printf("δ�����ܷ�,�޷����򣬰����������......");
			}
			getche(); 
			break;
		case 5:
			system("cls");  
			printf("\n\n\n");
			printf("\t\t\tSort from high to low in ascending order by number:\n");
			head = SortbyNumber1(head, n);
			Print(head, n, m);
			printf("�����������!�����������......");
			getche(); 
			break;
		case 6:
			system("cls"); 
			printf("\n\n\n");
			printf("\t\t\tSort from low to high in ascending order by number:\n");
			head = SortbyNum(head);
			Print(head, n, m);
			printf("�����������!�����������......");
			getche();
			break;
		case 7:
			system("cls");  
			printf("\n\n\n");
			printf("\t\t\tSort in dictionary order by name:\n");
			head = SortbyName(head, n);
			Print(head, n, m);
			printf("�����������!�����������......");
			getche();
			break;
		case 8:
			system("cls");  
			printf("\n\n\n");
			printf("\t\t\t******************************************************************************\n");
			printf("\t\t\tInput the number you want to search:\n");
			SearchbyNum(head, n, m);
			printf("�����������......");
			getche();	
			break;
		case 9:
			system("cls");  
			printf("\n\n\n");
			printf("\t\t\t******************************************************************************\n");
			printf("\t\t\tInput the name you want to search:\n");
			SearchbyName(head, n, m);
			printf("�����������......");
			getche();
			break;
		case 10:
			system("cls");
			printf("\t\t\t******************************************************************************\n");
			head = deleteStu(head, &n, m);
			printf("�����������......");
			getche();
			break;
		case 11:
			system("cls");  
			printf("\n\n\n");
			addStu(head, &n, m);
			printf("��ӳɹ��������������......");
			getche();
			break;
		case 12:
				system("cls");
				printf("\n\n\n");
				Modify(head, n, m);
				printf("�����������......");
				getche();
				break;
		case 13:
			system("cls");  
			printf("\n\n\n");
			topStu(head, m);
			printf("�����������......");
			getche();
			break;
		case 14:
			system("cls");  
			printf("\n\n\n");
			failStu(head, m);
			printf("�����������......");
			getche();
			break;
		case 15:
			system("cls");  
			printf("\n\n\n");
			Print(head, n, m);
			printf("�����������......");
			getche();
			break;
		case 16:
			system("cls");
			printf("\t\t\tplease file name:");
			fflush(stdin);
			gets(filename);
			WritetoFile(head, filename, n, m);
			printf("�����������......");
			getche();
			break;
		case 17:
			system("cls");  
			head = ReadfromFile(head, &n, &m);
			printf("�����������......");
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
// �����˵�
int   Menu(void)
{
	int i;
	system("title ѧ���ɼ�����ϵͳV7.0  By wyxiang");
	printf("\n\n");
	printf("\t\t\t                         ѧ���ɼ�����ϵͳV1.0\n");
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
	printf("\t\t\t*                17. Read from a file                                        *\n");
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

// ��������
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
	
	memset(Course, 0, sizeof(Course));     //��ʼ������Course 
	p = head;
	if (head != NULL)									/*��ֹû������ѧ����Ϣhead=NULLʱ������head->next�������*/
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

STU  *SortbyScore(STU *head, int n)   //ð������ 
{
	STU *endpt;    //����ѭ���Ƚ�
	STU *p;        //��ʱָ�����
	STU *p1, *p2;
	int data = -1, ranknum = 0;//��ѧ���������м���� 
	
	p1 = (STU *)malloc(LEN);
	p1->next = head;        //ע����⣺��������һ���ڵ㣬���ڵ�һ���ڵ��ǰ�棬��Ҫ��Ϊ�˱��ڱȽϡ���Ϊ��һ���ڵ�û��ǰ�������ǲ��ܽ�����ַ
	head = p1;                 //��headָ��p1�ڵ㣬������ɺ������ٰ�p1�ڵ��ͷŵ�

	for (endpt = NULL; endpt != head; endpt = p) 
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)//���һ�ζ�û��������Ȼp = head�����Ѿ��ź�������ѭ������ֹ 
		{
			if (p1->next->sum < p1->next->next->sum)  //���ǰ��Ľڵ��ֵ�Ⱥ���ڵ�ļ�ֵ���򽻻�
			{
				p2 = p1->next->next;			//		��������p1->a->b->c->......										 
				p1->next->next = p2->next;		//		�Ȱ�b���浽p2����p2 =  p1->next->next							
				p2->next = p1->next;			//		����a��һ��ָ��c,a->c��b��һ��ָ��a��b->a��						
				p1->next = p2;					//		����p1ָ��p2����p1ָ��b��p1->b									
				p = p1->next->next;				//		�ۺ����漴�ɵó���p1->b->a->c; 									
			}									//		p = a? �����涼û�ٽ�������Ȼ����a->c->......���涼�Ѿ��ź�����	 
		}										//		����һ��ѭ���Ƚ�ʱֻ����a�ڵ�֮ǰ����������� 
	}
	
	p1 = head;              //��p1����Ϣȥ��
	head = head->next;       //��headָ�������ĵ�һ���ڵ�
	free(p1);          //�ͷ�p1
	
	//�ִܷӸߵ�����������ÿ��ͬѧ��������ͬ�ܷ����β��� 
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
	STU *endpt;    //����ѭ���Ƚ�
	STU *p;        //��ʱָ�����
	STU *p1, *p2;

	p1 = (STU *)malloc(LEN);
	p1->next = head;        //ע����⣺��������һ���ڵ㣬���ڵ�һ���ڵ��ǰ�棬��Ҫ��Ϊ�˱��ڱȽϡ���Ϊ��һ���ڵ�û��ǰ�������ǲ��ܽ�����ַ
	head = p1;                 //��headָ��p1�ڵ㣬������ɺ������ٰ�p1�ڵ��ͷŵ�

	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (p1->next->num < p1->next->next->num)  //���ǰ��Ľڵ��ֵ�Ⱥ���ڵ�ļ�ֵ���򽻻�
			{
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;
				p = p1->next->next;
			}
		}
	}

	p1 = head;              //��p1����Ϣȥ��
	head = head->next;       //��headָ�������ĵ�һ���ڵ�
	free(p1);          //�ͷ�p1
	p1 = NULL;          //p1��ΪNULL����֤��������Ұָ�롱������ַ��ȷ����ָ�����

	return head;
}

STU *SortbyNum(STU *head)    //���뷨���� 
{
	STU *first;    //Ϊԭ����ʣ������ֱ�Ӳ�������Ľڵ�ͷָ��
	STU *t;        //��ʱָ�����������ڵ�
	STU *p, *q;     //��ʱָ�����,q��Ϊ���������ͷ,p����ǰһ���ڵ� 

	if(head == NULL)
	{
		return head;
	}
	first = head->next;      //ԭ����ʣ������ֱ�Ӳ�������Ľڵ�����
	head->next = NULL;       //����һ���ڵ���Ϊ��һ����������

	while (first != NULL)        //����ʣ�����������
	{
		//ע�⣺����for����������ֱ�Ӳ�������˼��ĵط�
		for (t = first, q = head; ((q != NULL) && (q->num < t->num)); p = q, q = q->next);  //����������������ڵ��������������Ҳ����λ��

		first = first->next; //���������еĽڵ��뿪���Ա������뵽����������

		if (q == head)      //���ڵ�һ���ڵ�֮ǰ
		{
			head = t;
		}
		else            //p��q��ǰ��
		{
			p->next = t;
		}
		t->next = q;     //��ɲ��붯��
						 //first = first->next;
	}
	return head;
}

STU  *SortbyName(STU *head, int n)
{
	STU *endpt;    //����ѭ���Ƚ�
	STU *p;        //��ʱָ�����
	STU *p1, *p2;

	p1 = (STU *)malloc(LEN);
	p1->next = head;        //ע����⣺��������һ���ڵ㣬���ڵ�һ���ڵ��ǰ�棬��Ҫ��Ϊ�˱��ڱȽϡ���Ϊ��һ���ڵ�û��ǰ�������ǲ��ܽ�����ַ
	head = p1;                 //��headָ��p1�ڵ㣬������ɺ������ٰ�p1�ڵ��ͷŵ�

	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (strcmp(p1->next->name, p1->next->next->name)>0)  //���ǰ��Ľڵ��ֵ�Ⱥ���ڵ�ļ�ֵ���򽻻�
			{
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;     //��ϵ�4�����
				p = p1->next->next;   //��ϵ�6�����
			}
		}
	}

	p1 = head;              //��p1����Ϣȥ��
	head = head->next;       //��headָ�������ĵ�һ���ڵ�
	free(p1);          //�ͷ�p1
	p1 = NULL;          //p1��ΪNULL����֤��������Ұָ�롱������ַ��ȷ����ָ�����

	return head;
}


void Print(STU *head, int n, int m)
{
	STU *p;
	int i;
	p = head;

	if (head != NULL)        //ֻҪ���ǿ�������������������нڵ�
	{
		printf("\t\t\t******************************************************************************\n");
		printf("\t\t\t%-10s\t%-10s\t", "ѧ��", "����"); 
		for(i = 0; i < m; i++)
		{
			printf("%-10s\t", courseName[i]);
		}
		printf("%-10s\t%-10s\t%-10s\n", "�ܷ�", "ƽ����", "����"); 
		do
		{

			printf("\t\t\t%-10ld\t%-10s\t", p->num, p->name);
			for (i = 0; i<m; i++)
			{
				printf("%-10.1f\t", p->score[i]);
			}
			printf("%-10.1f\t%-10.1f\t%-10d\n", p->sum, p->sum / m, p->rankNum);
			p = p->next;     //�Ƶ���һ���ڵ�
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
				printf("\t\t\t%-10s\t%-10s\t", "ѧ��", "����"); 
				for(i = 0; i < m; i++)
				{
					printf("%-10s\t", courseName[i]);
				}
				printf("%-10s\t%-10s\t%-10s\n", "�ܷ�", "ƽ����", "����");
				
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
				printf("\t\t\t%-10s\t%-10s\t", "ѧ��", "����"); 
				for(i = 0; i < m; i++)
				{
					printf("%-10s\t", courseName[i]);
				}
				printf("%-10s\t%-10s\t%-10s\n", "�ܷ�", "ƽ����", "����");
				
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
				printf("\t\t\t%-10s\t%-10s\t", "ѧ��", "����"); 
				for(i = 0; i < m; i++)
				{
					printf("%-10s\t", courseName[i]);
				}
				printf("%-10s\t%-10s\t%-10s\n", "�ܷ�", "ƽ����", "����");
				
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
					printf("ɾ���ɹ��������������......");
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
	//������ӵ�ѧ����������ԭ����β 
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
					printf("\t\t\t%-10s\t%-10s\t", "ѧ��", "����"); 
					for(i = 0; i < m; i++)
					{
						printf("%-10s\t", courseName[i]);
					}
					printf("%-10s\t%-10s\t%-10s\n", "�ܷ�", "ƽ����", "����");
					
					printf("\t\t\t");
					printf("%-10ld\t%-10s\t", p->num, p->name);
					for (i = 0; i<m; i++)
					{
						printf("%-10.1f\t", p->score[i]);
					}
					printf("%-10.1f\t%-10.1f\t%-10d\n", p->sum, p->sum / m, p->rankNum);
					
					printf("\t\t\tplease input the modified information:\n");
					printf("\t\t\t%-10s\t%-10s\t", "ѧ��", "����"); 
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
					printf("�޸ĳɹ���"); 
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
		p = head; // ��Ҫ���˳�ʼ������Ȼ��ը
		for (j = 0; j<6; j++)  // ��ʼ��
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
	if(strcmp(filename, "ԭʼ����.txt") == 0 || strcmp(filename, "ѧ���ۺϳɼ�.txt") == 0)
	{
		fprintf(fp, "\t\t\tstudent number:%d(��)\tcourse number:%d(��)\n", n, m);
		fprintf(fp, "%-10s\t\t%-10s\t", "ѧ��", "����"); 
		for(i = 0; i < m; i++)
		{
			fprintf(fp, "%-10s\t", courseName[i]);
		}
		fprintf(fp, "%-10s\t%-10s\t%-10s\n", "�ܷ�", "ƽ����", "����");
		
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
		fprintf(fp, "%-10s\t%-5s\t%-3s\t\t%-3s\t%-3s\t\t%-3s\t\t%-3s\t\t%-3s\n", "course", "sum", "averscore", "<60", "[60,70)", "[70,80)", "[80,90)", ">=90");
		for(i = 0; i < m; i++)
		{
			fprintf(fp, "%-10s\t%-5.1f\t%-3.1f\t\t%-3d\t%-3d\t\t%-3d\t\t%-3d\t\t%-3d\n", courseName[i], Course[i].sumscore, Course[i].avescore, Course[i].sectionNum[0],
													  				 Course[i].sectionNum[1], Course[i].sectionNum[2], Course[i].sectionNum[3], Course[i].sectionNum[4]);
		}
	}
	{
		
	}
	printf("\t\t\tExport Successfully!\n");
	fclose(fp);
	printf("\t\t\t******************************************************************************\n");

}

/*
void  ReadfromFile(STU1 stu[], int *n, int *m)
{
FILE *fp;
int i, j;
printf("\n\n\n");
printf("\t\t\t******************************************************************************\n");
if ((fp = fopen("student.txt", "r")) == NULL)
{
printf("\t\t\tFail to open student.txt\n");
return;
}
fscanf(fp, "%d\t%d\n", n, m);
for (i = 0; i<*n; i++)
{
fscanf(fp, "%12ld", &stu[i].num);
fscanf(fp, "%12s", stu[i].name);
for (j = 0; j<*m; j++)
{
fscanf(fp, "%12f", &stu[i].score[j]);
}
fscanf(fp, "%12f%12f", &stu[i].sum, &stu[i].aver);

}
printf("\t\t\tImport Successfully!\n");
fclose(fp);


for (i = 0; i < *n; i++)
{
printf("\t\t\t%ld\t%s\t", stu[i].num, stu[i].name);
for (j = 0; j<*m; j++)
{
printf("%.0f\t", stu[i].score[j]);
}
printf("%.0f\t%.0f\n", stu[i].sum, stu[i].aver);
}

printf("\t\t\t******************************************************************************\n");

}
*/

void topStu(STU *head, int n)
{
	STU *p = head;
	FILE *fp;
	int i, flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 1, count = 0;//�ŵ����������� 
	
	if((fp = fopen("�ŵ���.txt", "w")) == NULL)
	{
		printf("���ļ�ʧ�ܣ�\n");
		flag4 = 0;
	}
	for(; p; p= p->next)
	{
		flag1 = 0;//��ʼ������������������ 
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
		if(flag1 || flag2 || flag3)//����һ�������ŵ��� 
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
		printf("���ŵ���!");
		if(flag4)
		fprintf(fp, "���ŵ���"); 
	}
	else
	{
		printf("�ŵ�����%d��\n", count);
		if(flag4)
		fprintf(fp, "\t�ŵ�����%d��\n", count);
	}
	fclose(fp);
}

void failStu(STU *head, int n)
{
	STU *p = head;
	int i, flag1 = 0, flag2 = 1, flag3 = 1;
	FILE *fp;
	
	if((fp = fopen("ѧ���������Ŀ.txt", "w")) == NULL)
	{
		printf("���ļ�ʧ��\n");
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
		printf("�޲�����ѧ��\n");
		if(flag3)
		{
			fprintf(fp, "�޲�����ѧ��\n");
		}
	}
	fclose(fp);
}

//��������ֱ��������һ���µ�����ȷ������ֱ�Ӷ�ȡ��õ�����
STU *ReadfromFile(STU *head, int *n, int *m)
{
	STU *p;
	FILE *fp;
	int i, j;
	if ((fp = fopen("student.txt", "r")) == NULL)
	{
		printf("\t\t\tFail to open student.txt\n");
		return NULL;
	}
	fscanf(fp, "%d\t%d\n", n, m);
	head = Creat1(*n, *m);  //������һ�����������Ҹ���head
	p = head;
	for (i = 0; i<*n; i++)
	{
		fscanf(fp, "%12ld", &p->num);
		fscanf(fp, "%12s", &p->name);
		for (j = 0; j<*m; j++)
		{
			fscanf(fp, "%12f", &p->score[j]);
		}
		fscanf(fp, "%12f%12f", &p->sum, &p->aver);

		p = p->next;

	}
	i = *n;
	j = *m;
	printf("\t\t\tImport Successfully!\n");
	fclose(fp);

	Print(head, i, j);

	return head;
}




