#include "Student.h"

/********************************
�������ܣ���ӡ����ѧ����Ϣ�� 
����������ͷ��㡢ѧ���������γ���Ŀ 
����ֵ���� 
*******************************/
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
/********************************
�������ܣ���ӡÿ���γ���Ϣ 
�������γ���Ŀ
����ֵ���� 
*******************************/
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
