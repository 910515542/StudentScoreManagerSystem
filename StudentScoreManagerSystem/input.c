#include "Student.h"

/********************************
�������ܣ���ʾ�˵� 
�������� 
����ֵ���û�ѡ��Ĳ˵���� 
*******************************/
int   Menu(void)
{
	int i;
	system("title ѧ���ɼ�����ϵͳV1.0  ����: ��С��");
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
/********************************
�������ܣ��������� 
������ѧ���������γ���Ŀ 
����ֵ������ͷ��� 
*******************************/
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

