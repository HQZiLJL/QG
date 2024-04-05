#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counter.h"
//#include "stack.h"     //���´�����ڱ�����ʡ�� ��ϸ�鿴����ר�������ݽṹ_3��ջ(�Ƚ����)��


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

int stack_top(STACK* ptr, int* x)  //ȡջ��Ԫ�ز鿴,����ջ
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

void compute(STACK* snum, int op)//�������
{
	int n1, n2, n;

	stack_pop(snum, &n2); //ȡջ��Ԫ��n2���ҳ�ջ
	stack_pop(snum, &n1); //ȡջ��Ԫ��n1���ҳ�ջ

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
	stack_push(snum, &n);  //�������֮����ѹջ��snum[]��
}

void deal_op(STACK* snum, STACK* sop, int op)//û�����ŵ����㺯��
{//  +-*/(;  1+2*2
	int old_op;

	if (stack_isempty(sop) || op == '(')
	{//����ַ�ջ����û���ַ�����ֱ����ջ
		stack_push(sop, &op);  //pushΪ��ջ����
		return;
	}

	stack_top(sop, &old_op); //�鿴ջ��Ԫ�ص�ֵ���浽old_op��ȥ

	if (get_pri(op) > get_pri(old_op)) //get_pri ����ֵ 0 1 2
	{//�������������ȼ���ջ��Ԫ�����ȼ��ߣ�ֱ����ջ
		stack_push(sop, &op);
		return;
	}

	while (get_pri(op) <= get_pri(old_op))
	{//�������������ȼ�û��ջ��Ԫ�����ȼ��ߣ��������ȼ����ʱ
		stack_pop(sop, &old_op);	 //ȡջ��Ԫ�ز��ҳ�ջ
		compute(snum, old_op);	//��������
		if (stack_isempty(sop))
			break;
		stack_top(sop, &old_op); //
	}

	stack_push(sop, &op); //
}

void deal_bracket(STACK* snum, STACK* sop)//����������ʱ����
{
	int old_op;

	stack_top(sop, &old_op); //�鿴����ջջ���������

	while (old_op != '(') //ֱ������������ʱֹͣ��ջ
	{
		stack_pop(sop, &old_op); //��-����ջ
		compute(snum, old_op); //����������ı��ʽ
		stack_top(sop, &old_op); //�鿴ջ��Ԫ��Ϊ��(�� ����ѭ��
	}
	stack_pop(sop, &old_op);  //�ѡ�(����ջ

}

int get_pri(int op)   //��������ȼ�����
//opΪҪ����������
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
	printf("���������ʽ��");
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

	snum = stack_create();    //����������ֵ�ջ
	/*if error*/
	sop = stack_create();     //��������������ջ
	/*if error*/

	for (; str[i] != '\0'; i++)  //��ʼ�����ַ�������ÿһ���ַ�
	{
		// 	    "11-(5-3)*6+15";"1+2+3*3"
		if (str[i] >= '0' && str[i] <= '9')	//num
		{
			value = value * 10 + str[i] - '0'; 
			flag = 1;   //���ñ�־λ ���������λ�������ϵ�����
		}
		else		//��������+ - * / ���� ִ��else���
		{
			if (flag)
			{
				stack_push(snum, &value);  //������ջ��������λ��������
				value = 0;
				flag = 0;
			}

			if (str[i] == ')')   //��ʼ��ջ������ʼ����
				deal_bracket(snum, sop);
			else	 // +-*/( ��ʼ�����ջ     
				deal_op(snum, sop, str[i]);
		}
	}
	//���������е����������Ԫ�ض��������ˣ���ʼ���������
	if (flag)
	{//���ַ������е����һ������ѹջ
		stack_push(snum, &value);
	}

	while (!stack_isempty(sop))
	{//ֻҪ����ջ��Ϊ�վͿ�ʼ����
		stack_pop(sop, &old_op);
		compute(snum, old_op);
	}

	stack_pop(snum, &value); //valueΪ���Ҫ����Ľ����������ջ
	printf("%s = %d\n", str, value);
	system("pause");

	stack_destroy(snum);
	stack_destroy(sop);

	exit(0);
}
