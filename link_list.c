/**
* @file：link_list.c
* @brief:链表的定义、链表节点的插入（尾插）、链表节点的查找、链表节点的删除、链表的遍历、链表的释放
* @author：胡新增
* @ID：BJ0082
* @data：2019.12.23
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "link_list.h"

/** 链表头节点 */
STUDENT *g_head = NULL;

/**
 * @Description：尾插法，把要增加的信息插入到链表尾部
 * @param insert：指向待插入的节点
 * @return 无
 */
 void InsertStudentInformation(const STUDENT *insert)
 {
	if (g_head == NULL)
	{
		g_head = (STUDENT *)insert;
		g_head->next = NULL;
	}
	else
	{
		/* 定义一个链表指针临时保存头结点的位置 */
		STUDENT *pb = g_head;
		
		/* 查找链表尾节点 */
		while (pb->next != NULL)
		{
			pb = pb->next;
		}
		
		pb->next = (STUDENT *)insert;
		pb->next->next = NULL;
	}
	
	return;
 }
 
/**
 * @Description：根据学生的学号查询学生的信息
 * @param num：10-12位的学号
 * @return：成功：存储该学生信息的节点地址，失败：NULL 
*/
 STUDENT* FindStudentInformation(const char *num)
 {
    if (g_head == NULL)
	{
		return NULL;
	}
	else
	{
		/* 定义一个链表指针临时保存头结点的位置 */
		STUDENT *pb = g_head;
		
		while (pb != NULL)
		{
			if (0 == strcmp(pb->number,num))
			{
				return pb;
			}
			else
			{
				pb = pb->next;
			}
		}
	}
	
	return NULL;
 }
 
 /**
 * @Description：删除学号所对应的学生信息
 * @param num:10-12位的学号
 * @return: 成功：1，失败：0
 */
int DeleteStudentInformation(const char *num)
{
	if (g_head == NULL)
	{
		printf("链表内容为空\n");
		return 0;
	}
	else
	{
		/* 定义一个链表指针临时保存头结点的位置 */
		STUDENT *pb = g_head;
		/* 定义一个链表指针用来保存pb的前一个节点位置 */
		STUDENT *pf = NULL;
		
		/* 判断头结点是否是所寻节点 */
		if (0 == strcmp(g_head->number, num))
		{
			printf("删除成功\n");
			g_head = g_head->next;
			free(pb);
			return 1;
		}
		else
		{
			while (pb != NULL)
			{
				if (0 == strcmp(pb->number, num))
				{
					printf("删除成功\n");
					pf->next = pb->next;
					free(pb);
					return 1;
				}
				else
				{
					pf = pb;
					pb = pb->next;
				}
			}
			
			printf("未找到该学生信息\n");
		}
	}

	return 0;
}
 
 /**
 * @Description：遍历链表信息
 * @return: 无
 */
 void TraversingTheList()
 {
	if (g_head == NULL)
	{
		printf("链表内容为空\n");
		return;
	}
	else
	{
		/* 定义一个链表指针临时保存头结点的位置 */
		STUDENT *pb = g_head;
		
		while (pb != NULL)
		{
			printf("\t姓名：%s\n\t性别：%s\n\t年龄：%d\n\t学号：%s\n",\
				   pb->name, pb->sex, pb->age, pb->number);
			pb = pb->next;
		}
	}
	
	return;
 }
 
 /**
 * @Description：链表空间释放
 * @return: 无
 */
 void ReleaseLinkList()
 {
	 if (g_head == NULL)
	 {
		 printf("链表已经为空\n");
		 return;
	 }
	 else
	 {
		 /* 定义一个链表指针临时保存头结点的位置 */
		STUDENT *pb = g_head;
		
		while(pb != NULL)
		{
			g_head = g_head->next;
			free(pb);
			pb = g_head;
		}
		
		printf("链表释放完毕\n");
	 }
	 
	 return;
 }