// 双链表结构体定义：
// 【1】预编译部分
#include "dulinklist.h"
#include <stdio.h>
#include <stdlib.h>

// 【5】双链表初始化（头结点的初始化）
bool InitDuLinkList(DuLinkList L)
{
    L->data = 0;    // 头结点的data域用来存储表长
    L->next = NULL; // 头结点的next域用来指向链表的第一个结点
    L->prior = NULL;
}

// 【6】双链表的遍历
bool PrintDuLinkList(DuLinkList L)
{
    DuLNode *HeadDuLNode = L;
    while (HeadDuLNode->next) // 非0即真
    {
        HeadDuLNode = HeadDuLNode->next;
        printf("%d-->", HeadDuLNode->data);
    }
    printf("NULL\n");
    return true; // 因为是bool
}

// 【7】双链表的头插法
bool HeadInsert_DuLinkList(DuLinkList L, ElemType count, ElemType o)
{
    DuLNode *NewNode;      // 新结点声明
    ElemType NewNode_data; // 新结点的数据域
    printf("Please enter a number at the heading:");
    scanf("%d", &NewNode_data); // 输入新结点的数据域值
    while (count < (o - 1))
    {
        count++;
        // 进行插入操作
        DuLNode *HeadDuLNode = L;
        NewNode->next = HeadDuLNode->next; // 尾结点指向头结点的下一个结点
        NewNode->prior = HeadDuLNode;      // 新结点的前继结点指向头结点
        HeadDuLNode->next = NewNode;       // 让头结点的后继指向新结点
        NewNode->data = NewNode_data;      // 给新结点data域赋值
        L->data++;                         // 让头结点存储的表长+1
        printf("Please enter a number at the heading:");
        scanf("%d", &NewNode_data); // 继续插入下一个结点
    }
    return true;
}

// 【8】双链表的尾插法
bool TailInsertDuLinkList(DuLinkList L, ElemType count, ElemType o)
{
    DuLNode *NewNode;                // 指向新结点的指针
    DuLNode *TaiDuLNode = L;         // 尾指针指向头结点
    ElemType NewNode_data;           // 新结点的data域
    while (TaiDuLNode->next != NULL) // 让tail一直从头结点往后移，直到移到尾结点
    {
        TaiDuLNode = TaiDuLNode->next; // 让taiDuLNode往后移一位
    }
    printf("\nPlease enter a number at the ending:");
    scanf("%d", &NewNode_data);
    while (count < (o - 1))
    {
        count++;
        NewNode = (DuLNode *)malloc(sizeof(DuLNode)); // 给NewNode的存储空间赋值
        NewNode->data = NewNode_data;                 // 给新结点data域赋值
        NewNode->next = TaiDuLNode->next;             // 新结点的后继指针指向NULL
        NewNode->prior = TaiDuLNode;                  // 新结点的前驱指针指向原先的最后一个
        TaiDuLNode->next = NewNode;                   // 让原先的尾结点指向新结点
        TaiDuLNode = NewNode;                         // 让尾指针指向新结点
        L->data++;                                    // 表长++
        printf("Please enter a number at the ending:");
        scanf("%d", &NewNode_data);
    }
    return true;
}

// 【9】尾部删除
bool DeleTail(DuLinkList L)
{
    if (!L->next) // 说明是空表
    {
        printf("This DuLinkList is empty!\n");
        return false;
    }
    DuLNode *TaiDuLNode = L;         // 尾指针指向头结点
    while (TaiDuLNode->next != NULL) // 让tail一直从头结点往后移，直到移到尾结点
    {
        TaiDuLNode = TaiDuLNode->next; // 让taiDuLNode往后移一位
    }
    TaiDuLNode = TaiDuLNode->prior;
    free(TaiDuLNode->next);
    TaiDuLNode->next = NULL;
    L->data--;
    return true;
}

// 【10】头删除
bool HeadTail(DuLinkList L)
{
    if (!L->next) // 说明是空表
    {
        printf("This DuLinkList is empty!\n");
        return false;
    }
    DuLNode *HeadDuLNode = L;
    DuLNode *TaiDuLNode = L;
    while (TaiDuLNode->next != NULL) // 让tail一直从头结点往后移，直到移到尾结点
    {
        TaiDuLNode = TaiDuLNode->next; // 让taiDuLNode往后移一位
    }
    DuLNode *DelHeadNode = HeadDuLNode->next; // 保存删除的结点
    HeadDuLNode->next = DelHeadNode->next;
    // 判断是不是只有一个结点，有则需对尾结点进行特殊处理
    if (DelHeadNode->next != NULL)
    {
        DelHeadNode->next->prior = HeadDuLNode;
    }
    else
    {
        TaiDuLNode = HeadDuLNode;
    }
    free(DelHeadNode);
    L->data--;
    return true;
}
// 【9】查找
DuLNode *find(DuLinkList L, ElemType data)
{
    if (!L->next) // 说明是空表
    {
        printf("This DuLinkList is empty!\n");
        return L;
    }
    DuLNode *HeadDuLNode = L;
    HeadDuLNode = (DuLNode *)malloc(sizeof(DuLNode)); // 给NewNode的存储空间赋值
    DuLNode *curNode = HeadDuLNode->next;
    while (curNode != NULL)
    {
        if (curNode->data == data)
        {
            return curNode;
        }
        curNode = curNode->next;
    }
    return NULL;
}

// 插入
bool insert(DuLinkList L, DuLNode *iterator, ElemType data)
{
    DuLNode *newNode;
    newNode = (DuLNode *)malloc(sizeof(DuLNode)); // 给NewNode的存储空间赋值
    newNode->data = data;
    DuLNode *prevNode;
    prevNode = (DuLNode *)malloc(sizeof(DuLNode)); // 给prevNode的存储空间赋值
    prevNode = iterator->prior;                    // 保存要插入位置的上一个结点

    newNode->next = iterator; // 让新结点连上去
    newNode->prior = prevNode;

    iterator->prior = newNode; // 让前后结点连上新结点
    prevNode->next = newNode;
    L->data++;
    return true;
}

// 【9】按位查找数据元素
DuLNode *GetElem(DuLinkList L, ElemType i) // L是要查找的链表 i是位序
{
    if (i == 0) //[1]判断i的合法性
    {
        printf("The DuLinkList's element you are looking for does not exist!\nReturn the head pointer of the DuLinkList!\n");
        return L;
    }

    if (i < 1 || i > L->data)
    {
        printf("The DuLinkList's element you are looking for does not exist!\nReturn NULL!\n");
        return NULL;
    }
    //[2]查找元素
    DuLNode *p = L;
    for (int j = 0; j < i; j++) // 也可以写成j=1;j<=i
    {
        p = p->next;
    }
    return p;
}
// 【9-2】销毁链表的按位查找数据元素
DuLNode *GetElem_Del(DuLinkList L, ElemType i) // L是要查找的链表 i是位序
{
    if (i == 0) //[1]判断i的合法性
    {
        return L;
    }

    if (i < 1 || i > L->data)
    {
        return NULL;
    }
    //[2]查找元素
    DuLNode *p = L;
    for (int j = 0; j < i; j++) // 也可以写成j=1;j<=i
    {
        p = p->next;
    }
    return p;
}

// 【10】按值查找数据元素
DuLNode *LocateElem(DuLinkList L, ElemType e)
{
    if (!L->next) // 说明是空表
    {
        printf("This DuLinkList is empty!\n");
        return L;
    }
    DuLNode *p = L;
    while (p->next) // 如果next存在
    {
        p = p->next;
        if (p->next == e)
            return p;
    }
    printf("The DuLinkList's element you are looking for does not exist!\n");
    return NULL; // 不存在的话返回NULL
}

// 【12】双链表的按位删除
bool LocalDeleteElem(DuLinkList L, ElemType i, ElemType *e)
{
    //[1]检测i的合法性
    if (!L->next) // 空表直接退出
    {
        printf("This DuLinkList is empty!\n");
        *e = 9999;
        return false;
    }
    if (i < 1 || i > L->data) // 比表长小/大也不能删
    {
        printf("The position of the element is invalid!\n");
        *e = 9999;
        return false;
    }
    //[2]删除指定元素
    DuLNode *p = GetElem(L, i - 1); // 待删除元素的前驱结点
    DuLNode *q = p->next;           // 待删除元素
    p->next = q->next;
    *e = q->data;
    free(q);
    L->data--;
    return true;
}
// 【12-2】销毁链表的双链表的按位删除
bool LocalDeleteElem_Del(DuLinkList L, ElemType i, ElemType *e)
{
    //[1]检测i的合法性
    if (!L->next) // 空表直接退出
    {
        printf("This DuLinkList is empty!\n");
        *e = 9999;
        return false;
    }
    if (i < 1 || i > L->data) // 比表长小/大也不能删
    {
        printf("The position of the element is invalid!\n");
        *e = 9999;
        return false;
    }
    //[2]删除指定元素
    DuLNode *p = GetElem_Del(L, i - 1); // 待删除元素的前驱结点
    DuLNode *q = p->next;               // 待删除元素
    p->next = q->next;
    *e = q->data;
    free(q);
    L->data--;
    return true;
}
// 【11】按位插入
bool LocalInsertDuLinkList(DuLinkList L, ElemType i, ElemType e)
{
    //[1]判断i的合法性
    if (i < 1 || i > (L->data + 1)) // 不能插在第0位或多一位（只有5位插在第七位）
    {
        printf("The position of the element to be inserted is invalid!\n");
        return false;
    }
    //[2]插入新元素
    // 让
    // DuLNode *p=GetElem(L,i-1);//找到前一个
    // DuLNode *NewNode=(DuLNode*)malloc(sizeof(DuLNode));//生成新的结点
    // NewNode->prior=p;
    // NewNode->next=p->;

    DuLNode *p = GetElem(L, i - 1);                        // 找到前一位的指针 如果i=1，那么GetElem(L,0),0的情况是返回L，那么就插在头结点的下一位
    DuLNode *NewNode = (DuLNode *)malloc(sizeof(DuLNode)); // 生成新的结点
    NewNode->data = e;
    NewNode->next = p->next; // 让新结点的next域指向下一个结点
    p->next = NewNode;       // 让p的next域指向新结点
    L->data++;
    return true;
}
// 【13】销毁双链表
bool DestroyDuLinkList(DuLinkList L)
{
    int e;
    while (L->data)
    {
        LocalDeleteElem_Del(L, 1, &e);
    }
    free(L);
}
int main()
{
    ElemType m = 0, j, k, n, e, l, o, count = 0, q, r;
    DuLinkList L; // 初始化头指针（结点）
    printf("\n\n\n\n");
    L = (DuLNode *)malloc(sizeof(DuLNode)); // 不能写在初始化 因为L在初始化里是个临时变量 跳出函数时L出不来
    printf("双链表ADT\n\n1.初始化链表\n2.插入新结点\n3.删除结点\n4.遍历链表\n5.查询链表的值\n6.查询中间结点\n7.退出系统\n");
    printf("请输入对应的数字(1~7):");
    int x;
    while (scanf("%d", &x) == 0)
    {
        rewind(stdin);
        printf("输入数据类型错误！\n");
        printf("请输入一个数(1~7):");
    }
    while (x > 1)
    {
        rewind(stdin);
        printf("请先创建链表！\n");
        printf("请输入一个数(1~7):");
        while (scanf("%d", &x) == 0)
        {
            rewind(stdin);
            printf("输入数据类型错误！\n");
            printf("请输入一个数(1~7):");
        }
    }
    {
        system("cls");
        InitDuLinkList(L);
        printf("请输入需要创建结点的个数：");
        scanf("%d", &o);
        TailInsertDuLinkList(L, count, o); // 尾插法
        printf("双链表创建成功！\n");
    }
    system("cls");
    PrintDuLinkList(L);
    printf("双链表创建成功!\n");
    printf("\n");
    printf("双链表ADT\n\n1.初始化链表\n2.插入新结点\n3.删除结点\n4.遍历链表\n5.查询链表的值\n6.查询中间结点\n7.退出系统\n");
    printf("请输入对应的数字(1~7):");
    scanf("%d", &x);
    while (1)
    {
        if (x == 1)
        {
            system("cls");
            printf("链表已创建成功，无需重复创建。\n");
        }
        else if (x == 2)
        {
            system("cls");
            PrintDuLinkList(L);
            printf("请输入想要插入的位置以及要插入的值：");
            scanf("%d", &j);
            printf("\n");
            scanf("%d", &k);
            LocalInsertDuLinkList(L, j, k);
            printf("成功插入新结点\n");
            printf("新链表如下：\n");
            PrintDuLinkList(L); // 遍历链表
            system("pause");
        }
        else if (x == 3)
        {
            system("cls");
            PrintDuLinkList(L);
            printf("请输入要删除结点的位置：");
            scanf("%d", &n);
            LocalDeleteElem(L, n, &e);
            printf("已成功删除该结点！\n");
            printf("新链表如下：\n");
            PrintDuLinkList(L); // 遍历链表
        }
        else if (x == 4)
        {
            system("cls");
            PrintDuLinkList(L); // 遍历链表
        }
        else if (x == 5)
        {
            system("cls");
            PrintDuLinkList(L);
            printf("请输入您想查找的位置：");
            scanf("%d", &l);
            if (l == 0)
            {
                printf("The DuLinkList's element you are looking for does not exist!\n");
            }
            else if (l < 1 || l > L->data)
            {
                printf("The DuLinkList's element you are looking for does not exist!\nReturn NULL!\n");
                printf("NULL\n");
            }
            else
            {
                printf("该位置的值为%d\n", GetElem(L, l)->data);
            }
        }
        else if (x == 6)
        {
            system("cls");
            DuLNode *p = L;
            for (int j = 0; j < (o / 2 + 1); j++) // 也可以写成j=1;j<=i
            {
                p = p->next;
            }
            printf("中间结点对应的数据域值为%d\n", p->data);
        }
        else if (x == 7) // 置空链表并退出
        {
            system("cls");
            DestroyDuLinkList(L);
            printf("链表删除完成!\n已退出系统!");
            break;
        }
        else if (x > 7)
        {
            system("cls");
            printf("更多功能敬请期待！");
        }
        printf("\n\n");
        printf("双链表ADT\n\n1.初始化链表\n2.插入新结点\n3.删除结点\n4.遍历链表\n5.查询链表的值\n6.查询中间结点\n7.退出系统\n");
        printf("请输入对应的数字(1~7):");
        scanf("%d", &x);
    }
    system("pause");
    return 0;
}
