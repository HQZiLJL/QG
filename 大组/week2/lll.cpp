

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 30

struct       // 设定运算符优先级
{            // 运算符
    char ch; // 优先级
    int pri;
} leftPri[] = {{'=', 0}, {'(', 1}, {'*', 5}, {'/', 5}, {'+', 3}, {'-', 3}, {')', 6}},
  rightPri[] = {{'=', 0}, {'(', 6}, {'*', 4}, {'/', 4}, {'+', 2}, {'-', 2}, {')', 1}};

int LeftPri(char op);                      // 左运算符op的优先级
int RightPri(char op);                     // 右运算符op的优先级
bool InOp(char ch);                        // 判断ch是否为运算符
int ConpareCode(char op1, char op2);       // 比较op1与op2的优先级
void Transform(char *exp, char postExp[]); // 将exp（用户输入的表达式）转变成栈中元素，
float Compute(char *postExp);              // 进行后缀表达式运算，返回结果

int main()
{
    char exp[30];
    printf("计算器：\n\n");
    printf("请输入数学计算公式：");
    scanf("%s", exp); // 在不同编译器中可能报错，vs中可写成scanf_s("%s",exp,n) n建议取30.
    char postExp[MaxSize];
    Transform(exp, postExp);
    printf("答案：%g\n\n", Compute(postExp));

    return 0;
}

int LeftPri(char op) // 左运算符op的优先级
{
    for (int i = 0; i < 7; i++)
        if (leftPri[i].ch == op)
            return leftPri[i].pri;
}

int RightPri(char op) // 右运算符op的优先级
{
    int i;
    for (int i = 0; i < 7; i++)
        if (rightPri[i].ch == op)
            return rightPri[i].pri;
}

bool InOp(char ch) // 判断ch是否为运算符
{
    if (ch == '(' || ch == ')' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return true;
    else
        return false;
}

int ConpareCode(char op1, char op2)
{
    if (LeftPri(op1) == RightPri(op2))
        return 0;
    else if (LeftPri(op1) < RightPri(op2))
        return -1;
    else
        return 1;
}

void Transform(char *exp, char postExp[])
{
    struct
    {
        char data[MaxSize];
        int top;
    } op;
    int i = 0;
    int flag = 0;
    op.top = -1;
    op.top++;
    op.data[op.top] = '='; // top = 0
    while (*exp != '\0')
    {
        if (!InOp(*exp))
        {
            while (*exp >= '0' && *exp <= '9')
            {
                postExp[i++] = *exp;
                exp++;
            }
            postExp[i++] = '#';
        }
        else
        {
            switch (ConpareCode(op.data[op.top], *exp)) // top = 0即op.data[op.top] = '='
            {
            case -1:
                op.top++; // top = 1
                op.data[op.top] = *exp;
                exp++;
                break;
            case 0:
                op.top--; // top = 0
                exp++;
                break;
            case 1:
                postExp[i++] = op.data[op.top];
                op.top--;
                break;
            }
        }
    }
    while (op.data[op.top] != '=') // 减到0之后就退出，
    {

        postExp[i++] = op.data[op.top];
        op.top--; // top的值越大，优先级就越高！
    }
    postExp[i] = '\0';
}

float Compute(char *postExp)
{
    struct
    {
        float data[MaxSize];
        int top;
    } ser;

    float a, b, c, d;
    ser.top = -1;
    while (*postExp != '\0')
    {
        switch (*postExp)
        {
        case '+':
            a = ser.data[ser.top];
            ser.top--;
            b = ser.data[ser.top];
            ser.top--;
            c = a + b;
            ser.top++;
            ser.data[ser.top] = c;
            break;
        case '-':
            a = ser.data[ser.top];
            ser.top--;
            b = ser.data[ser.top];
            ser.top--;
            c = b - a;
            ser.top++;
            ser.data[ser.top] = c;
            break;
        case '*':
            a = ser.data[ser.top];
            ser.top--;
            b = ser.data[ser.top];
            ser.top--;
            c = b * a;
            ser.top++;
            ser.data[ser.top] = c;
            break;
        case '/':
            a = ser.data[ser.top];
            ser.top--;
            b = ser.data[ser.top];
            ser.top--;
            if (a != 0)
            {
                c = b / a;
                ser.top++;
                ser.data[ser.top] = c;
            }
            else
            {
                printf("\n\t格式错误");
                exit(0);
            }

            break;
        default:
            d = 0;
            while (*postExp >= '0' && *postExp <= '9')
            {
                d = 10 * d + *postExp - '0';
                postExp++; // 两个postExp++恰好跳过了‘#’符号
            }
            ser.top++;
            ser.data[ser.top] = d;
        }
        postExp++;
    }
    return (ser.data[ser.top]);
}
