/**
* @file：main.c
* @brief:用户根据帮助信息输入相应指令完成对学生信息的添加、查看、删除等操作
* @author：胡新增
* @ID：BJ0082
* @data：2019.12.23
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "link_list.h"

int main(int argc, char *argv[])
{
	/* 帮助信息 */
	printf("\t**************************\t\n");
	printf("\t***insert 插入学生信息****\t\n");
	printf("\t***find 查找学生信息******\t\n");
	printf("\t***traverse 遍历链表信息**\t\n");
	printf("\t***delete 删除学生信息****\t\n");
	printf("\t***release 释放链表*******\t\n");
	printf("\t***quit 退出当前程序******\t\n");
	printf("\t**************************\t\n");
	
	char user_input[32] = "";
	while (1)
	{
		printf("请输入：");
		scanf("%s",user_input);
		getchar();
		
		if (0 == strcmp("insert",user_input))
		{
			/* 创建一个链表节点 */
			STUDENT *tmp = (STUDENT *)malloc(sizeof(STUDENT));
			
			printf("请输入学生信息 姓名 性别 年龄 学号\n");
			scanf("%s %s %d %s",tmp->name, tmp->sex, &tmp->age, tmp->number);
			
			/* 插入学生信息 */
			InsertStudentInformation(tmp);
		}
		else if (0 == strcmp("find",user_input))
		{
			STUDENT *tmp = NULL; /* 用来接查找函数的返回值*/
			char num[16] = ""; /* 保存用户输入的学生学号 */
			
			printf("请输入要查找的学生的学号：\n");
			scanf("%s",num);
			
			/* 查找对应学号的学生信息 */
			tmp = FindStudentInformation(num);
			
			if (tmp != NULL)
			{
				/* 打印该学生信息 */
				printf("\t姓名：%s\n\t性别：%s\n\t年龄：%d\n\t学号：%s\n",\
					   tmp->name, tmp->sex, tmp->age, tmp->number);
			}
		}
		else if (0 == strcmp("traverse",user_input))
		{
			/* 遍历链表打印学生信息 */
			TraversingTheList();
		}
		else if (0 == strcmp("delete",user_input))
		{
			char num[16] = ""; /* 保存用户输入的学生学号 */
			
			printf("请输入要删除的学生的学号：\n");
			scanf("%s",num);
			
			/* 删除对应学号的学生信息 */
			int tmp = DeleteStudentInformation(num);
			
		}
		else if (0 == strcmp("release",user_input))
		{
			/* 释放链表 */
			ReleaseLinkList();
		}
		else if (0 == strcmp("quit",user_input))
		{
			break;
		}
	}
}
