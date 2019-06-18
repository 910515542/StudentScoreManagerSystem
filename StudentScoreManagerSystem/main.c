/******************************************
项目名：学生成绩管理系统
项目介绍：该项目包括以下功能

<p> 1.录入每个学生的学号、姓名和各科考试成绩
<p> 2.计算每门课程的总分和平均分
<p> 3.计算每个学生的总分和平均分
<p> 4.按每个学生的总分由高到低排出名次表
<5> 5.输入学号修改或删除指定学生信息
<p> 6.按学号由小到大或由大到小排出成绩表
<p> 7.按姓名的字典顺序排出成绩表
<p> 8.按学号查询学生排名及其考试成绩
<p> 9.按姓名查询学生排名及其考试成绩
<p> 10.按优秀（90-100）、良好（80-89）、中等（70-79）、及格（60-69）、不及格（0-59）5个类别，对每门课程分别统计每个类别的人数
<p> 11.按优等生标准找出所有优等生
<p> 12.输出每个学生的学号、姓名、各科考试成绩，以及每门课程的总分和平均分
<p> 13.将每个学生的纪录信息写入文件  
<p> 14.将每门课程的记录信息写入文件
<p> 15.文件描述：
        (1).原始数据.txt ---> 第一次输入的学生数据
        (2).学生综合成绩.txt ---> 计算总分、平均分且排完名的学生数据
        (3).统计数据.txt ---> 每门课程数据
        (4).优等生.txt ---> 按标准筛选出来的优秀学生名单（A．平均成绩上 80。 B．平均成绩及格但未上 80，有单科成绩上 90。 C．平均成绩未及格，有单科满分。满足一项即可）
        (5).学生不及格科目.txt ---> 每个学生不及格的科目
        
<p> 作者：尹小轩  时间：2019/06/06 
****************************************/
#include "Student.h" 

/******************************
主函数：显示程序首页，循环显示菜单，获取用户选项并完成相应处理流程，直至退出 
**********************************/
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
