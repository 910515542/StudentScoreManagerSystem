#include "Student.h"

/********************************
�������ܣ�����ÿ�ſγ�ƽ���֡��ܷ� 
����������ͷ��㡢ѧ���������γ���Ŀ 
����ֵ���� 
*******************************/
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
/********************************
�������ܣ�����ÿ��ѧ���ܷ֡�ƽ���� 
����������ͷ��㡢ѧ���������γ���Ŀ 
����ֵ���� 
*******************************/
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
/********************************
�������ܣ���ѧ���ִܷӸߵ������� 
����������ͷ��㡢ѧ������ 
����ֵ������ͷ��� 
*******************************/
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
/********************************
�������ܣ���ѧ��ѧ�ŴӴ�С���� 
����������ͷ��㡢ѧ������
����ֵ������ͷ��� 
*******************************/
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
/********************************
�������ܣ���ѧ��ѧ�Ŵ�С�������� 
����������ͷ���
����ֵ������ͷ��� 
*******************************/
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
/********************************
�������ܣ���ѧ�����ֵ���ĸ˳������ 
����������ͷ��㡢ѧ������
����ֵ������ͷ��� 
*******************************/
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
