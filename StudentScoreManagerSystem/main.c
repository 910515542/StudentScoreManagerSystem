/******************************************
��Ŀ����ѧ���ɼ�����ϵͳ
��Ŀ���ܣ�����Ŀ�������¹���

<p> 1.¼��ÿ��ѧ����ѧ�š������͸��ƿ��Գɼ�
<p> 2.����ÿ�ſγ̵��ֺܷ�ƽ����
<p> 3.����ÿ��ѧ�����ֺܷ�ƽ����
<p> 4.��ÿ��ѧ�����ܷ��ɸߵ����ų����α�
<5> 5.����ѧ���޸Ļ�ɾ��ָ��ѧ����Ϣ
<p> 6.��ѧ����С������ɴ�С�ų��ɼ���
<p> 7.���������ֵ�˳���ų��ɼ���
<p> 8.��ѧ�Ų�ѯѧ���������俼�Գɼ�
<p> 9.��������ѯѧ���������俼�Գɼ�
<p> 10.�����㣨90-100�������ã�80-89�����еȣ�70-79��������60-69����������0-59��5����𣬶�ÿ�ſγ̷ֱ�ͳ��ÿ����������
<p> 11.���ŵ�����׼�ҳ������ŵ���
<p> 12.���ÿ��ѧ����ѧ�š����������ƿ��Գɼ����Լ�ÿ�ſγ̵��ֺܷ�ƽ����
<p> 13.��ÿ��ѧ���ļ�¼��Ϣд���ļ�  
<p> 14.��ÿ�ſγ̵ļ�¼��Ϣд���ļ�
<p> 15.�ļ�������
        (1).ԭʼ����.txt ---> ��һ�������ѧ������
        (2).ѧ���ۺϳɼ�.txt ---> �����ܷ֡�ƽ��������������ѧ������
        (3).ͳ������.txt ---> ÿ�ſγ�����
        (4).�ŵ���.txt ---> ����׼ɸѡ����������ѧ��������A��ƽ���ɼ��� 80�� B��ƽ���ɼ�����δ�� 80���е��Ƴɼ��� 90�� C��ƽ���ɼ�δ�����е������֡�����һ��ɣ�
        (5).ѧ���������Ŀ.txt ---> ÿ��ѧ��������Ŀ�Ŀ
        
<p> ���ߣ���С��  ʱ�䣺2019/06/06 
****************************************/
#include "Student.h" 

/******************************
����������ʾ������ҳ��ѭ����ʾ�˵�����ȡ�û�ѡ������Ӧ�������̣�ֱ���˳� 
**********************************/
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
			printf("\t\t\t����ִ����Ӧ��������󱣴�����Ӧ�ļ��У����㡢������޷��ٽ���ԭʼ���ݱ���\n");
			printf("\t\t\tplease file name(ԭʼ����.txt ͳ������.txt ѧ���ۺϳɼ�.txt): ");
			fflush(stdin);
			gets(filename);
			WritetoFile(head, filename, n, m);
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
