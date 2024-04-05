/***************************************************************************************
 *	File Name				:	counter.h
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

#ifndef COUNTER_H_INCLUDED
#define COUNTER_H_INCLUDED

/**************************************************************
 *	Macro Define Section
 **************************************************************/

#define MAXSIZE 200
int q;

/**************************************************************
 *	Struct Define Section
 **************************************************************/

// 定义结点
typedef struct
{
  int data[MAXSIZE];
  int top;
} STACK;

STACK *stack_create();
void stack_create2(STACK **ptr);
int stack_isempty(STACK *ptr);
int stack_isfull(STACK *ptr);
int stack_push(STACK *ptr, const int *x);
int stack_pop(STACK *ptr, int *x);
int stack_top(STACK *ptr, int *x); // 取栈顶元素查看,不出栈
void stack_display(STACK *ptr);
void stack_destroy(STACK *ptr);
/**************************************************************
 *	End-Multi-Include-Prevent Section
 **************************************************************/
#endif