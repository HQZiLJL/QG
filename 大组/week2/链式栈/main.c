#include <stdio.h>
#include <stdlib.h>

int q;

typedef enum Status
{
    ERROR = 0,
    SUCCESS = 1
} Status;

typedef int ElemType;

typedef struct StackNode
{
    ElemType data;
    struct StackNode* next;
} StackNode, * LinkStackPtr;

typedef struct LinkStack
{
    LinkStackPtr top; // 栈顶结点
    int count;        // 栈大小
} LinkStack;

Status initLStack(LinkStack* s) // 初始化栈
{
    s->top = NULL;
    s->count = 0;
    return SUCCESS;
}
Status isEmptyLStack(LinkStack* s) // 判断栈是否为空
{
    return s->count == 0;
}
Status traversal(LinkStack* s) // 遍历链表
{
    LinkStackPtr temp = s->top;
    while (temp != NULL)
    {
        // printf("遍历链表如下：");
        printf("%d-->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    return SUCCESS;
}

Status getTopLStack(LinkStack* s, ElemType* e) // 得到栈顶元素
{
    // 判断是否栈空
    if (s->top == NULL)
        return ERROR;
    *e = s->top->data;
    return SUCCESS;
}
Status clearLStack(LinkStack* s) // 清空栈
{
    LinkStackPtr p, q;
    // p指向栈顶结点
    p = s->top;
    while (p)
    {
        // 保存要删除的结点p
        q = p;
        // 然p指向它的下一个结点
        p = p->next;
        // 删除 p结点
        free(q);
        q = NULL;
    }
    return SUCCESS;
}
Status destroyLStack(LinkStack* s) // 销毁栈
{
    return SUCCESS;
}
ElemType LStackLength(LinkStack* s) // 检测栈长度
{
    return s->count;
}
Status pushLStack(LinkStack* s, ElemType data) // 入栈
{
    // 1. 创建一个新结点，
    LinkStackPtr newNode = (LinkStackPtr)malloc(sizeof(StackNode));
    // 2. 赋值给新结点
    newNode->data = data;
    // 3. 插入新结点到栈顶结点后面
    // 3.1 把当前的栈顶元素的结点指针指向直接后继结点
    newNode->next = s->top;
    // 3.2 将新结点赋值给栈顶指针
    s->top = newNode;
    // 栈大小+1
    s->count++;
    return SUCCESS;
}
Status popLStack(LinkStack* s, ElemType* data) // 出栈
{
    LinkStackPtr p;
    if (isEmptyLStack(s))
        return ERROR;
    // 1. 将栈顶元素赋值给*data
    *data = s->top->data;
    // 2. 将栈顶结点赋值给p
    p = s->top;
    // 3. 使得栈顶指针下移一位, 指向后一结点
    s->top = s->top->next;
    // 4. 释放p结点
    free(p);
    // 栈大小减1
    s->count--;
    return SUCCESS;
}
LinkStackPtr Search(LinkStack* s, ElemType data) // 查找数据
{
    LinkStackPtr cur = s->top;
    q = 0;
    while (cur) // cur指向NULL时退出循环
    {
        if (cur->data == data)
        {
            return cur;
        }
        cur = cur->next;
        q++;
    }
    return NULL;
}

void insert(LinkStack* s);
void out(LinkStack* s);
void search(LinkStack* s);
int main()
{
    printf("\n\n\n\n");
    LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
    printf("链式栈ADT\n\n1.创建空链表\n2.入栈\n3.出栈\n4.查找数据\n5.遍历链表\n6.退出(并置空链表)\n");
    printf("请输入一个数(1~6):");
    int x;
    while (scanf_s("%d", &x) == 0)
    {
        rewind(stdin);
        printf("输入数据类型错误！\n");
        printf("请输入一个数(1~6):");
    }
    while (x > 1)
    {
        rewind(stdin);
        printf("请先创建链表！\n");
        printf("请输入一个数(1~6):");
        while (scanf_s("%d", &x) == 0)
        {
            rewind(stdin);
            printf("输入数据类型错误！\n");
            printf("请输入一个数(1~6):");
        }
    }
    { // 创建链式栈
        system("cls");
        initLStack(s);
    }
    system("cls");
    printf("链式栈创建成功!\n");
    printf("\n\n\n");
    printf("链式栈ADT\n\n1.创建空链栈\n2.入栈\n3.出栈\n4.查找数据\n5.遍历链表\n6.退出(并置空链栈)\n");
    printf("请输入一个数(1~6):");
    while (scanf_s("%d", &x) == 0)
    {
        rewind(stdin);
        printf("输入数据类型错误！\n");
        printf("请输入一个数(1~6):");
    }
    while (1)
    {
        if (x == 1)
        {
            system("cls");
            printf("链式栈已创建成功，无需重复创建。\n");
        }
        else if (x == 2)
        {
            system("cls");
            insert(s);
        }
        else if (x == 3)
        {
            system("cls");
            out(s);
        }
        else if (x == 4)
        {
            system("cls");
            search(s);
        }
        else if (x == 5)
        {
            system("cls");
            traversal(s);
        }
        else if (x == 6) // 置空链表并退出
        {
            system("cls");
            clearLStack(s);
            printf("链式栈已置空！\n");
            break;
        }
        else if (x > 6)
        {
            system("cls");
            printf("更多功能敬请期待！\n");
        }
        printf("\n\n\n");
        printf("链式栈ADT\n\n1.创建空链栈\n2.入栈\n3.出栈\n4.查找数据\n5.遍历链表\n6.退出(并置空链栈)\n");
        printf("请输入一个数(1~6):");
        scanf_s("%d", &x);
    }
    system("pause");
    return 0;
}
void insert(LinkStack* s)
{
    printf("请输入新入栈的数据：");
    int data;
    while (scanf_s("%d", &data) == 0)
    {
        rewind(stdin);
        printf("输入数据类型错误！\n");
        printf("请输入新入栈的数据：");
    }
    pushLStack(s, data);
    printf("新链式栈如下：\n");
    traversal(s);
}
void out(LinkStack* s)
{
    int da= 0;
    popLStack(s, &da);
    printf("栈顶为%d\n", da);
}
void search(LinkStack* s)
{
    printf("请输入想要查找数据：");
    int x;
    while (scanf_s("%d", &x) == 0)
    {
        rewind(stdin);
        printf("输入数据类型错误！\n");
        printf("请输入想要查找数据：");
    }
    Search(s, x);
    if (Search(s, x) == NULL)
        printf("此链表不存在该数！");
    else
        printf("第%d位数字\n", q+1);
}