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
    LinkStackPtr top; // ջ�����
    int count;        // ջ��С
} LinkStack;

Status initLStack(LinkStack* s) // ��ʼ��ջ
{
    s->top = NULL;
    s->count = 0;
    return SUCCESS;
}
Status isEmptyLStack(LinkStack* s) // �ж�ջ�Ƿ�Ϊ��
{
    return s->count == 0;
}
Status traversal(LinkStack* s) // ��������
{
    LinkStackPtr temp = s->top;
    while (temp != NULL)
    {
        // printf("�����������£�");
        printf("%d-->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    return SUCCESS;
}

Status getTopLStack(LinkStack* s, ElemType* e) // �õ�ջ��Ԫ��
{
    // �ж��Ƿ�ջ��
    if (s->top == NULL)
        return ERROR;
    *e = s->top->data;
    return SUCCESS;
}
Status clearLStack(LinkStack* s) // ���ջ
{
    LinkStackPtr p, q;
    // pָ��ջ�����
    p = s->top;
    while (p)
    {
        // ����Ҫɾ���Ľ��p
        q = p;
        // Ȼpָ��������һ�����
        p = p->next;
        // ɾ�� p���
        free(q);
        q = NULL;
    }
    return SUCCESS;
}
Status destroyLStack(LinkStack* s) // ����ջ
{
    return SUCCESS;
}
ElemType LStackLength(LinkStack* s) // ���ջ����
{
    return s->count;
}
Status pushLStack(LinkStack* s, ElemType data) // ��ջ
{
    // 1. ����һ���½�㣬
    LinkStackPtr newNode = (LinkStackPtr)malloc(sizeof(StackNode));
    // 2. ��ֵ���½��
    newNode->data = data;
    // 3. �����½�㵽ջ��������
    // 3.1 �ѵ�ǰ��ջ��Ԫ�صĽ��ָ��ָ��ֱ�Ӻ�̽��
    newNode->next = s->top;
    // 3.2 ���½�㸳ֵ��ջ��ָ��
    s->top = newNode;
    // ջ��С+1
    s->count++;
    return SUCCESS;
}
Status popLStack(LinkStack* s, ElemType* data) // ��ջ
{
    LinkStackPtr p;
    if (isEmptyLStack(s))
        return ERROR;
    // 1. ��ջ��Ԫ�ظ�ֵ��*data
    *data = s->top->data;
    // 2. ��ջ����㸳ֵ��p
    p = s->top;
    // 3. ʹ��ջ��ָ������һλ, ָ���һ���
    s->top = s->top->next;
    // 4. �ͷ�p���
    free(p);
    // ջ��С��1
    s->count--;
    return SUCCESS;
}
LinkStackPtr Search(LinkStack* s, ElemType data) // ��������
{
    LinkStackPtr cur = s->top;
    q = 0;
    while (cur) // curָ��NULLʱ�˳�ѭ��
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
    printf("��ʽջADT\n\n1.����������\n2.��ջ\n3.��ջ\n4.��������\n5.��������\n6.�˳�(���ÿ�����)\n");
    printf("������һ����(1~6):");
    int x;
    while (scanf_s("%d", &x) == 0)
    {
        rewind(stdin);
        printf("�����������ʹ���\n");
        printf("������һ����(1~6):");
    }
    while (x > 1)
    {
        rewind(stdin);
        printf("���ȴ�������\n");
        printf("������һ����(1~6):");
        while (scanf_s("%d", &x) == 0)
        {
            rewind(stdin);
            printf("�����������ʹ���\n");
            printf("������һ����(1~6):");
        }
    }
    { // ������ʽջ
        system("cls");
        initLStack(s);
    }
    system("cls");
    printf("��ʽջ�����ɹ�!\n");
    printf("\n\n\n");
    printf("��ʽջADT\n\n1.��������ջ\n2.��ջ\n3.��ջ\n4.��������\n5.��������\n6.�˳�(���ÿ���ջ)\n");
    printf("������һ����(1~6):");
    while (scanf_s("%d", &x) == 0)
    {
        rewind(stdin);
        printf("�����������ʹ���\n");
        printf("������һ����(1~6):");
    }
    while (1)
    {
        if (x == 1)
        {
            system("cls");
            printf("��ʽջ�Ѵ����ɹ��������ظ�������\n");
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
        else if (x == 6) // �ÿ������˳�
        {
            system("cls");
            clearLStack(s);
            printf("��ʽջ���ÿգ�\n");
            break;
        }
        else if (x > 6)
        {
            system("cls");
            printf("���๦�ܾ����ڴ���\n");
        }
        printf("\n\n\n");
        printf("��ʽջADT\n\n1.��������ջ\n2.��ջ\n3.��ջ\n4.��������\n5.��������\n6.�˳�(���ÿ���ջ)\n");
        printf("������һ����(1~6):");
        scanf_s("%d", &x);
    }
    system("pause");
    return 0;
}
void insert(LinkStack* s)
{
    printf("����������ջ�����ݣ�");
    int data;
    while (scanf_s("%d", &data) == 0)
    {
        rewind(stdin);
        printf("�����������ʹ���\n");
        printf("����������ջ�����ݣ�");
    }
    pushLStack(s, data);
    printf("����ʽջ���£�\n");
    traversal(s);
}
void out(LinkStack* s)
{
    int da= 0;
    popLStack(s, &da);
    printf("ջ��Ϊ%d\n", da);
}
void search(LinkStack* s)
{
    printf("��������Ҫ�������ݣ�");
    int x;
    while (scanf_s("%d", &x) == 0)
    {
        rewind(stdin);
        printf("�����������ʹ���\n");
        printf("��������Ҫ�������ݣ�");
    }
    Search(s, x);
    if (Search(s, x) == NULL)
        printf("���������ڸ�����");
    else
        printf("��%dλ����\n", q+1);
}