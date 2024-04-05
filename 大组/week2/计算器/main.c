#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counter.h"
//#include "stack.h"     //以下代码关于本函数省略 详细查看分类专栏《数据结构_3、栈(先进后出)》


STACK* stack_create()
{
	STACK *new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return NULL;
	new->top = -1;
	return new;
}

void stack_create2(STACK** ptr)
{
	*ptr = malloc(sizeof(STACK));
	if (*ptr == NULL)
		return;

	(*ptr)->top = -1;
	return;
}

int stack_isempty(STACK* ptr)
{
	if (ptr->top == -1)
		return 1;
	return 0;

}
int stack_isfull(STACK* ptr)
{
	if (ptr->top == MAXSIZE - 1)
		return 1;
	return 0;
}

int stack_push(STACK* ptr, const int* x)
{
	if (stack_isfull(ptr))
		return -1;

	ptr->data[++ptr->top] = *x;
	return 0;
}

int stack_pop(STACK* ptr, int* x)
{
	if (stack_isempty(ptr))
		return -1;
	*x = ptr->data[ptr->top--];
	return 0;
}

int stack_top(STACK* ptr, int* x)  //取栈顶元素查看,不出栈
{
	if (stack_isempty(ptr))
		return -1;
	*x = ptr->data[ptr->top];
	return 0;
}

void stack_display(STACK* ptr)
{
	int i;
	if (stack_isempty(ptr))
		return;
	for (i = 0; i <= ptr->top; i++)
		printf("%d ", ptr->data[i]);
	printf("\n");
}

void stack_destroy(STACK* ptr)
{
	free(ptr);
	ptr = NULL;
}

//main

void compute(STACK* snum, int op)//结果运算
{
	int n1, n2, n;

	stack_pop(snum, &n2); //取栈顶元素n2并且出栈
	stack_pop(snum, &n1); //取栈顶元素n1并且出栈

	switch (op)
	{
	case '+':
		n = n1 + n2;
		break;
	case '-':
		n = n1 - n2;
		break;
	case '*':
		n = n1 * n2;
		break;
	case '/':
		n = n1 / n2;
		break;
	default:
		break;
	}
	stack_push(snum, &n);  //计算完成之后结果压栈到snum[]中
}

void deal_op(STACK* snum, STACK* sop, int op)//没有括号的运算函数
{//  +-*/(;  1+2*2
	int old_op;

	if (stack_isempty(sop) || op == '(')
	{//如果字符栈里面没有字符，则直接入栈
		stack_push(sop, &op);  //push为入栈函数
		return;
	}

	stack_top(sop, &old_op); //查看栈顶元素的值，存到old_op中去

	if (get_pri(op) > get_pri(old_op)) //get_pri 返回值 0 1 2
	{//如果该运算符优先级比栈顶元素优先级高，直接入栈
		stack_push(sop, &op);
		return;
	}

	while (get_pri(op) <= get_pri(old_op))
	{//如果该运算符优先级没有栈顶元素优先级高，或者优先级相等时
		stack_pop(sop, &old_op);	 //取栈顶元素并且出栈
		compute(snum, old_op);	//进行运算
		if (stack_isempty(sop))
			break;
		stack_top(sop, &old_op); //
	}

	stack_push(sop, &op); //
}

void deal_bracket(STACK* snum, STACK* sop)//遇到右括号时运算
{
	int old_op;

	stack_top(sop, &old_op); //查看符号栈栈顶的运算符

	while (old_op != '(') //直至遇到左括号时停止出栈
	{
		stack_pop(sop, &old_op); //‘-’出栈
		compute(snum, old_op); //计算括号里的表达式
		stack_top(sop, &old_op); //查看栈顶元素为‘(’ 结束循环
	}
	stack_pop(sop, &old_op);  //把‘(’出栈

}

int get_pri(int op)   //运算符优先级函数
//op为要运算的运算符
{
	switch (op)
	{
	case '(':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	}
}


int main()
{
	//char str1[30] = "11-(5-3)*6+15";//"1+2*3"; 
	char str[30] = { 0 };
	int q=0;
	printf("请输入计算式：");
	while ((str[q++] = getchar()) != '\n');
	q--;
	str[q] = 0;
	//printf("%s\n", str);
	//printf("%s\n", str1);
	//printf("%d\n", strcmp(str, str1));
	//scanf_s("%s", str[30]);
	STACK* snum, * sop;
	int i = 0, value = 0, flag = 0;
	int old_op=0;

	snum = stack_create();    //创建存放数字的栈
	/*if error*/
	sop = stack_create();     //创建存放运算符的栈
	/*if error*/

	for (; str[i] != '\0'; i++)  //开始遍历字符数字中每一个字符
	{
		// 	    "11-(5-3)*6+15";"1+2+3*3"
		if (str[i] >= '0' && str[i] <= '9')	//num
		{
			value = value * 10 + str[i] - '0'; 
			flag = 1;   //巧用标志位 用来存放两位数及以上的数字
		}
		else		//遇到符号+ - * / （） 执行else语句
		{
			if (flag)
			{
				stack_push(snum, &value);  //数字入栈，包括两位数的数字
				value = 0;
				flag = 0;
			}

			if (str[i] == ')')   //开始出栈，并开始计算
				deal_bracket(snum, sop);
			else	 // +-*/( 开始入符号栈     
				deal_op(snum, sop, str[i]);
		}
	}
	//到这里所有的括号里面的元素都运算完了，开始下面的运算
	if (flag)
	{//将字符数组中的最后一个数字压栈
		stack_push(snum, &value);
	}

	while (!stack_isempty(sop))
	{//只要符号栈不为空就开始运算
		stack_pop(sop, &old_op);
		compute(snum, old_op);
	}

	stack_pop(snum, &value); //value为最后要输出的结果，将它出栈
	printf("%s = %d\n", str, value);
	system("pause");

	stack_destroy(snum);
	stack_destroy(sop);

	exit(0);
}
