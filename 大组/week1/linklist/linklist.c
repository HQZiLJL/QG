#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

link_list CreatNode(ElemType x) // 创建新结点
{
    link_list new_node = (link_list)malloc(sizeof(link_list));
    if (new_node == NULL)
    {
        perror("malloc fail:");
        return NULL;
    }
    new_node->data = x;
    new_node->next = NULL;
    return new_node;
}

link_list Link_Search(link_list L, ElemType x) // 单链表的查找
{
    link_list cur = L;
    q = 0;
    while (cur) // cur指向NULL时退出循环
    {
        if (cur->data == x)
        {
            return cur;
        }
        cur = cur->next;
        q++;
    }
    return NULL;
}

void front_insert(link_list L, ElemType x, ElemType y) // 前部插入新结点
// x为被插入位置的值。y为新结点的值
{
    link_list node = CreatNode(y);
    link_list pos = Link_Search(L, x);
    link_list prev = L;
    while (prev->next != pos)
    {
        prev = prev->next;
    }
    node->next = pos;
    prev->next = node;
}

void tail_insert(link_list L, ElemType x, ElemType y) // 尾部插入新结点
// x为被插入位置的值。y为新结点的值
{
    link_list node = CreatNode(y);
    link_list pos = Link_Search(L, x);
    node->next = pos->next;
    pos->next = node;
}

link_list top_create(link_list L) // 头部创建链表
{
    // link_list L = (link_list)malloc(sizeof(link_list));
    L->next = NULL;
    // 进行插入操作
    printf("Please enter a number(9999 means the end):");
    int temp_data;
    while (scanf("%d", &temp_data) == 0) // 输入新结点的数据域值
    {
        rewind(stdin);
        printf("输入数据类型错误！\n");
        printf("Please enter a number(9999 means the end):");
    }
    while (temp_data != 9999)
    {
        link_list temp = (link_list)malloc(sizeof(link_list)); // 让新结点的指针域指向下一个结点（即头结点原本指向的结点）
        temp->data = temp_data;
        temp->next = L->next; // 让头结点指向新结点
        L->next = temp;
        L->data++; // 让头结点存储的表长+1
        printf("Please enter a number(9999 means the end):");
        while (scanf("%d", &temp_data) == 0) // 继续插入下一个结点
        {
            rewind(stdin);
            printf("输入数据类型错误！\n");
            printf("Please enter a number(9999 means the end):");
        }
    }
    return L;
}

link_list b_create(link_list L) // 尾部创建链表
{
    // L = (link_list)malloc(sizeof(link_list));
    L->next = NULL;
    // link_list temp, middle;
    link_list middle = (link_list)malloc(sizeof(link_list));
    middle = L;
    // 进行插入操作
    printf("Please enter a number(9999 means the end):");
    int temp_data;
    while (scanf("%d", &temp_data) == 0) // 输入新结点的数据域值
    {
        rewind(stdin);
        printf("输入数据类型错误！\n");
        printf("Please enter a number(9999 means the end):");
    }
    while (temp_data != 9999)
    {
        link_list temp = (link_list)malloc(sizeof(link_list)); // 新结点定义
        // 让新结点的指针域指向下一个结点（即头结点原本指向的结点）
        temp->data = temp_data;
        temp->next = NULL;   // 让头结点指向新结点
        middle->next = temp; // 给新结点data域赋值
        middle = temp;
        L->data++; // 让头结点存储的表长+1
        printf("Please enter a number(9999 means the end):");
        while (scanf("%d", &temp_data) == 0) // 继续插入下一个结点
        {
            rewind(stdin);
            printf("输入数据类型错误！\n");
            printf("Please enter a number(9999 means the end):");
        }
    }
    return L;
}

void traversal(link_list L) // 遍历链表
{
    link_list temp = L->next;
    while (temp != NULL)
    {
        // printf("遍历链表如下：");
        printf("%d-->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void delete_list(link_list L) // 置空链表
{
    link_list p = (link_list)malloc(sizeof(link_list));
    link_list next = (link_list)malloc(sizeof(link_list));
    p = L;
    while (p)
    {
        next = p->next;
        // free(p);
        p = NULL;
        p = next;
    }
    L = NULL;
}

void delete_node(link_list L, ElemType x) // 删除某一位置的结点
{
    link_list pos = Link_Search(L, x);
    while (pos == NULL)
    {
        printf("此链表不存在该数据！\n");
        printf("请输入想要删除结点的数据域值：");
        scanf("%d", &x);
        while (scanf("%d", &x) == 0) // 输入新结点的数据域值
        {
            rewind(stdin);
            printf("输入数据类型错误！\n");
            printf("请输入想要删除结点的数据域值：");
        }
    }
    link_list prev = L;
    while (prev->next != pos)
    {
        prev = prev->next;
    }
    prev->next = pos->next;
    // free(pos);
    pos = NULL;
}

link_list solution(link_list L) // 查找中间结点
{
    link_list slow = (link_list)malloc(sizeof(link_list));
    link_list fast = (link_list)malloc(sizeof(link_list));
    slow = fast = L;
    int count = 0;
    while (fast != NULL)
    {
        count++;
        fast = fast->next;
        if (count % 2 == 1)
        {
            slow = slow->next;
        }
    }
    return slow;
}

link_list inverse(link_list L)
{ // 反转链表(前插法)
    link_list node = (link_list)malloc(sizeof(link_list));
    link_list L1 = (link_list)malloc(sizeof(link_list));
    link_list nb = (link_list)malloc(sizeof(link_list));
    L1->next = NULL;
    node = nb = L->next;
    while (node != NULL)
    {
        front_insert(L1, nb->data, node->data);
        nb = node;
        node = node->next;
    }
    return L1;
}

/**
 * 检测链表是否有环，若有环则找到入口
 * 使用快慢指针的方式
 *
 * @param L 链表头节点
 * @return 若为空，则不存在环；不为空，则返回入口节点
 */
link_list detectCircle(link_list L)
{
    // 快慢指针从头节点开始
    link_list fast = (link_list)malloc(sizeof(link_list));
    link_list slow = (link_list)malloc(sizeof(link_list));
    fast = slow = L;
    // 用于记录相遇点
    link_list encounter = NULL;
    // fast一次走两步，所以要保证next和next.next都不为空，为空就说明无环
    while (fast->next != NULL && fast->next->next != NULL)
    {
        // fast走两步，slow走一步
        fast = fast->next->next;
        slow = slow->next;
        // fast和slow一样，说明相遇了，或者fast追上slow了。
        if (fast == slow)
        {
            // 记录相遇点，fast或slow都一样
            encounter = fast;
            // 相遇了，就退出环检测过程
            break;
        }
    }
    // 如果encounter为空，说明没有环，就不用继续找环入口了。
    if (encounter == NULL)
    {
        return encounter;
    }
    // fast回到head位置
    fast = L;
    // 只要两者不相遇，就一直走下去
    while (fast != slow)
    {
        // fast每次走一步，slow每次走一步，速度一样
        fast = fast->next;
        slow = slow->next;
    }
    // 相遇点，即为环入口
    return fast;
}

void Front_insert(link_list L); // 前插新结点
void Tail_insert(link_list L);  // 尾部插入新结点
void Delete_node(link_list L);  // 任意位置删除结点
void Delete_list(link_list L);
void search(link_list L);
void Solution(link_list L);
void Inverse(link_list L);
void DetectCircle(link_list L);
int main()
{
    printf("\n\n\n\n");
    link_list L = (link_list)malloc(sizeof(link_list));
    printf("单链表ADT\n\n1.头部创建链表\n2.尾部创建链表\n3.删除结点\n4.遍历链表\n5.查找数据\n6.前插新结点\n7.尾插新结点\n8.查找中间结点\n9.反转链表\n10.判断链表是否成环\n11.退出(并置空链表)\n");
    printf("请输入一个数(1~11):");
    int x;
    while (scanf("%d", &x) == 0)
    {
        rewind(stdin);
        printf("输入数据类型错误！\n");
        printf("请输入一个数(1~11):");
    }
    while (x > 2)
    {
        rewind(stdin);
        printf("请先创建链表！\n");
        printf("请输入一个数(1~11):");
        while (scanf("%d", &x) == 0)
        {
            rewind(stdin);
            printf("输入数据类型错误！\n");
            printf("请输入一个数(1~11):");
        }
    }
    if (x == 1)
    {
        system("cls");
        L = top_create(L);
    }
    else if (x == 2)
    {
        system("cls");
        L = b_create(L);
    }
    system("cls");
    traversal(L);
    printf("单链表创建成功!\n");
    printf("\n\n\n");
    printf("单链表ADT\n\n1.头部创建链表\n2.尾部创建链表\n3.删除结点\n4.遍历链表\n5.查找数据\n6.前插新结点\n7.尾插新结点\n8.查找中间结点\n9.反转链表\n10.判断链表是否成环\n11.退出(并置空链表)\n");
    printf("请输入一个数(1~11):");
    scanf("%d", &x);
    while (1)
    {
        if (x == 1 || x == 2)
        {
            system("cls");
            printf("链表已创建成功，无需重复创建。\n");
        }
        else if (x == 3)
        {
            system("cls");
            traversal(L);
            Delete_node(L);
        }
        else if (x == 4)
        {
            system("cls");
            traversal(L);
        }
        else if (x == 5)
        {
            system("cls");
            search(L);
        }
        else if (x == 6)
        {
            system("cls");
            traversal(L);
            Front_insert(L);
        }
        else if (x == 7)
        {
            system("cls");
            traversal(L);
            Tail_insert(L);
        }
        else if (x == 8) // 查找中间结点
        {
            system("cls");
            Solution(L);
        }
        else if (x == 9) // 反转链表
        {
            system("cls");
            traversal(L);
            Inverse(L);
        }
        else if (x == 10) // 判断链表是否成环/
        {
            system("cls");
            DetectCircle(L);
        }
        else if (x == 11) // 置空链表并退出
        {
            system("cls");
            Delete_list(L);
            break;
        }
        else if (x > 11)
        {
            system("cls");
            printf("更多功能敬请期待！");
        }
        printf("\n\n\n");
        printf("单链表ADT\n\n1.头部创建链表\n2.尾部创建链表\n3.删除结点\n4.遍历链表\n5.查找数据\n6.前插新结点\n7.尾插新结点\n8.查找中间结点\n9.反转链表\n10.判断链表是否成环\n11.退出(并置空链表)\n");
        printf("请输入一个数(1~11):");
        scanf("%d", &x);
    }
    system("pause");
    return 0;
}
void Tail_insert(link_list L)
{
    printf("请输入被尾插结点的数据域值：");
    int old_node;
    while (scanf("%d", &old_node) == 0)
    {
        rewind(stdin);
        printf("输入数据类型错误！\n");
        printf("请输入被尾插结点的数据域值：");
    }
    printf("请输入一个新结点的数据域值：");
    int new_node;
    while (scanf("%d", &new_node) == 0)
    {
        rewind(stdin);
        printf("输入数据类型错误！\n");
        printf("请输入一个新结点的数据域值：");
    }
    tail_insert(L, old_node, new_node);
    printf("新链表如下：\n");
    traversal(L);
}

void Front_insert(link_list L)
{

    printf("请输入被前插结点的数据域值：");
    int old_node;
    while (scanf("%d", &old_node) == 0)
    {
        rewind(stdin);
        printf("输入数据类型错误！\n");
        printf("请输入被前插结点的数据域值：");
    }
    printf("请输入一个新结点的数据域值：");
    int new_node;
    while (scanf("%d", &new_node) == 0)
    {
        rewind(stdin);
        printf("输入数据类型错误！\n");
        printf("请输入一个新结点的数据域值：");
    }
    front_insert(L, old_node, new_node);
    printf("新链表如下：\n");
    traversal(L);
}

void Delete_node(link_list L)
{
    printf("请输入想要删除结点的数据域值：");
    int x;
    while (scanf("%d", &x) == 0) // 输入新结点的数据域值
    {
        rewind(stdin);
        printf("输入数据类型错误！\n");
        printf("请输入想要删除结点的数据域值：");
    }
    delete_node(L, x);
    printf("新链表如下：\n");
    traversal(L);
}
void search(link_list L)
{
    printf("请输入想要查找结点的数据域值：");
    int x;
    while (scanf("%d", &x) == 0)
    {
        rewind(stdin);
        printf("输入数据类型错误！\n");
        printf("请输入想要查找结点的数据域值：");
    }
    Link_Search(L, x);
    if (Link_Search(L, x) == NULL)
        printf("此链表不存在该数！");
    else
        printf("第%d位数字\n", q);
}
void Delete_list(link_list L)
{
    printf("链表已置空\n");
    delete_list(L);
}

void Solution(link_list L)
{
    link_list pos = (link_list)malloc(sizeof(link_list));
    pos = solution(L);
    printf("中间结点对应的数据域值：%d\n", pos->data);
}
void Inverse(link_list L)
{
    link_list L1 = (link_list)malloc(sizeof(link_list));
    L1 = inverse(L);
    printf("反转链表如下：\n");
    traversal(L1);
}

void DetectCircle(link_list L)
{
    link_list circle = (link_list)malloc(sizeof(link_list));
    circle = detectCircle(L);
    if (circle == NULL)
        printf("该链表不成环\n");
    else
        printf("成环入口结点的数据域为：%d\n", circle->data);
}