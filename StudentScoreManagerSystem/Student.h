#ifndef __STUDENT__
#define __STUDENT__

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

#endif
