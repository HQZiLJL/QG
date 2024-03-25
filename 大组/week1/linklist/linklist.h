/***************************************************************************************
 *	File Name				:	linklist.h
 *	CopyRight				:	2024 QG Studio
 *	SYSTEM					:   win11
 *	Create Data				:	2024.3.21
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/

/**************************************************************
 *	Multi-Include-Prevent Section
 **************************************************************/

#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

/**************************************************************
 *	Macro Define Section
 **************************************************************/

#define OVERFLOW -1
int q;

/**************************************************************
 *	Struct Define Section
 **************************************************************/

// 定义结点
typedef int ElemType;
typedef struct link_list
{
    ElemType data;
    struct link_list *next;
} link_link, *link_list;

link_list CreatNode(ElemType x);
link_list Link_Search(link_list L, ElemType x);         // 单链表的查找
void front_insert(link_list L, ElemType x, ElemType y); // 前部插入新结点
// x为被插入位置的值。y为新结点的值
void tail_insert(link_list L, ElemType x, ElemType y); // 尾部插入新结点
// x为被插入位置的值。y为新结点的值
link_list top_create(link_list L);         // 头部创建链表
link_list b_create(link_list L);           // 尾部创建链表
void traversal(link_list L);               // 遍历链表
void delete_list(link_list L);             // 置空链表
void delete_node(link_list L, ElemType x); // 删除某一位置的结点
link_list solution(link_list L);           // 查找中间结点
link_list inverse(link_list L);
/**
 * 检测链表是否有环，若有环则找到入口
 * 使用快慢指针的方式
 *
 * @param   L 链表头节点
 * @return 若为空，则不存在环；不为空，则返回入口节点
 */
link_list detectCircle(link_list L);

/**************************************************************
 *	End-Multi-Include-Prevent Section
 **************************************************************/
#endif