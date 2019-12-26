/**
* @file：link_list.h
* @brief:链表的定义、链表节点的插入（尾插）、链表节点的查找、链表节点的删除、链表的遍历、链表的释放
* @author：胡新增
* @ID：BJ0082
* @data：2019.12.23
* @function：InsertStudentInformation:往链表里插入学生信息
*            FindStudentInformation:根据学生的学号查询学生的信息
*            TraversingTheList：遍历链表信息并在终端显示
*            DeleteStudentInformation:根据学生的学号删除学生的信息
*            ReleaseLinkList：释放链表
*/
#ifndef LINK_LIST_H
#define LINK_LIST_H

/** 单项链表 每一个节点保存的信息为学生的姓名、性别、年龄、学号 */
typedef struct student
{
	/* 学生信息 */
	char name[32];
	char sex[16];
	char number[32];
	int age;
	
	/* 指向下一个节点*/
	struct student *next;
}STUDENT;

/** 链表头节点 */
extern STUDENT *g_head;

/**
 * @Description：尾插法，把要增加的信息插入到链表尾部
 * @param insert：指向待插入的节点
 * @return 无
 */
 extern void InsertStudentInformation(const STUDENT *insert);
 
/**
 * @Description：根据学生的学号查询学生的信息
 * @param num：10-12位的学号
 * @return：成功：存储该学生信息的节点地址，失败：NULL 
*/
 extern STUDENT* FindStudentInformation(const char *num);
 
 /**
 * @Description：删除学号所对应的学生信息
 * @param num:10-12位的学号
 * @return: 成功：1，失败：0
 */
extern int DeleteStudentInformation(const char *num);

/**
 * @Description：遍历链表信息
 * @return: 无
 */
 extern void TraversingTheList();
 
 /**
 * @Description：链表空间释放
 * @return: 无
 */
 extern void ReleaseLinkList();
 
#endif