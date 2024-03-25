// ˫����ṹ�嶨�壺
// ��1��Ԥ���벿��
#include "dulinklist.h"
#include <stdio.h>
#include <stdlib.h>

// ��5��˫�����ʼ����ͷ���ĳ�ʼ����
bool InitDuLinkList(DuLinkList L)
{
    L->data = 0;    // ͷ����data�������洢��
    L->next = NULL; // ͷ����next������ָ������ĵ�һ�����
    L->prior = NULL;
}

// ��6��˫����ı���
bool PrintDuLinkList(DuLinkList L)
{
    DuLNode *HeadDuLNode = L;
    while (HeadDuLNode->next) // ��0����
    {
        HeadDuLNode = HeadDuLNode->next;
        printf("%d-->", HeadDuLNode->data);
    }
    printf("NULL\n");
    return true; // ��Ϊ��bool
}

// ��7��˫�����ͷ�巨
bool HeadInsert_DuLinkList(DuLinkList L, ElemType count, ElemType o)
{
    DuLNode *NewNode;      // �½������
    ElemType NewNode_data; // �½���������
    printf("Please enter a number at the heading:");
    scanf("%d", &NewNode_data); // �����½���������ֵ
    while (count < (o - 1))
    {
        count++;
        // ���в������
        DuLNode *HeadDuLNode = L;
        NewNode->next = HeadDuLNode->next; // β���ָ��ͷ������һ�����
        NewNode->prior = HeadDuLNode;      // �½���ǰ�̽��ָ��ͷ���
        HeadDuLNode->next = NewNode;       // ��ͷ���ĺ��ָ���½��
        NewNode->data = NewNode_data;      // ���½��data��ֵ
        L->data++;                         // ��ͷ���洢�ı�+1
        printf("Please enter a number at the heading:");
        scanf("%d", &NewNode_data); // ����������һ�����
    }
    return true;
}

// ��8��˫�����β�巨
bool TailInsertDuLinkList(DuLinkList L, ElemType count, ElemType o)
{
    DuLNode *NewNode;                // ָ���½���ָ��
    DuLNode *TaiDuLNode = L;         // βָ��ָ��ͷ���
    ElemType NewNode_data;           // �½���data��
    while (TaiDuLNode->next != NULL) // ��tailһֱ��ͷ��������ƣ�ֱ���Ƶ�β���
    {
        TaiDuLNode = TaiDuLNode->next; // ��taiDuLNode������һλ
    }
    printf("\nPlease enter a number at the ending:");
    scanf("%d", &NewNode_data);
    while (count < (o - 1))
    {
        count++;
        NewNode = (DuLNode *)malloc(sizeof(DuLNode)); // ��NewNode�Ĵ洢�ռ丳ֵ
        NewNode->data = NewNode_data;                 // ���½��data��ֵ
        NewNode->next = TaiDuLNode->next;             // �½��ĺ��ָ��ָ��NULL
        NewNode->prior = TaiDuLNode;                  // �½���ǰ��ָ��ָ��ԭ�ȵ����һ��
        TaiDuLNode->next = NewNode;                   // ��ԭ�ȵ�β���ָ���½��
        TaiDuLNode = NewNode;                         // ��βָ��ָ���½��
        L->data++;                                    // ��++
        printf("Please enter a number at the ending:");
        scanf("%d", &NewNode_data);
    }
    return true;
}

// ��9��β��ɾ��
bool DeleTail(DuLinkList L)
{
    if (!L->next) // ˵���ǿձ�
    {
        printf("This DuLinkList is empty!\n");
        return false;
    }
    DuLNode *TaiDuLNode = L;         // βָ��ָ��ͷ���
    while (TaiDuLNode->next != NULL) // ��tailһֱ��ͷ��������ƣ�ֱ���Ƶ�β���
    {
        TaiDuLNode = TaiDuLNode->next; // ��taiDuLNode������һλ
    }
    TaiDuLNode = TaiDuLNode->prior;
    free(TaiDuLNode->next);
    TaiDuLNode->next = NULL;
    L->data--;
    return true;
}

// ��10��ͷɾ��
bool HeadTail(DuLinkList L)
{
    if (!L->next) // ˵���ǿձ�
    {
        printf("This DuLinkList is empty!\n");
        return false;
    }
    DuLNode *HeadDuLNode = L;
    DuLNode *TaiDuLNode = L;
    while (TaiDuLNode->next != NULL) // ��tailһֱ��ͷ��������ƣ�ֱ���Ƶ�β���
    {
        TaiDuLNode = TaiDuLNode->next; // ��taiDuLNode������һλ
    }
    DuLNode *DelHeadNode = HeadDuLNode->next; // ����ɾ���Ľ��
    HeadDuLNode->next = DelHeadNode->next;
    // �ж��ǲ���ֻ��һ����㣬�������β���������⴦��
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
// ��9������
DuLNode *find(DuLinkList L, ElemType data)
{
    if (!L->next) // ˵���ǿձ�
    {
        printf("This DuLinkList is empty!\n");
        return L;
    }
    DuLNode *HeadDuLNode = L;
    HeadDuLNode = (DuLNode *)malloc(sizeof(DuLNode)); // ��NewNode�Ĵ洢�ռ丳ֵ
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

// ����
bool insert(DuLinkList L, DuLNode *iterator, ElemType data)
{
    DuLNode *newNode;
    newNode = (DuLNode *)malloc(sizeof(DuLNode)); // ��NewNode�Ĵ洢�ռ丳ֵ
    newNode->data = data;
    DuLNode *prevNode;
    prevNode = (DuLNode *)malloc(sizeof(DuLNode)); // ��prevNode�Ĵ洢�ռ丳ֵ
    prevNode = iterator->prior;                    // ����Ҫ����λ�õ���һ�����

    newNode->next = iterator; // ���½������ȥ
    newNode->prior = prevNode;

    iterator->prior = newNode; // ��ǰ���������½��
    prevNode->next = newNode;
    L->data++;
    return true;
}

// ��9����λ��������Ԫ��
DuLNode *GetElem(DuLinkList L, ElemType i) // L��Ҫ���ҵ����� i��λ��
{
    if (i == 0) //[1]�ж�i�ĺϷ���
    {
        printf("The DuLinkList's element you are looking for does not exist!\nReturn the head pointer of the DuLinkList!\n");
        return L;
    }

    if (i < 1 || i > L->data)
    {
        printf("The DuLinkList's element you are looking for does not exist!\nReturn NULL!\n");
        return NULL;
    }
    //[2]����Ԫ��
    DuLNode *p = L;
    for (int j = 0; j < i; j++) // Ҳ����д��j=1;j<=i
    {
        p = p->next;
    }
    return p;
}
// ��9-2����������İ�λ��������Ԫ��
DuLNode *GetElem_Del(DuLinkList L, ElemType i) // L��Ҫ���ҵ����� i��λ��
{
    if (i == 0) //[1]�ж�i�ĺϷ���
    {
        return L;
    }

    if (i < 1 || i > L->data)
    {
        return NULL;
    }
    //[2]����Ԫ��
    DuLNode *p = L;
    for (int j = 0; j < i; j++) // Ҳ����д��j=1;j<=i
    {
        p = p->next;
    }
    return p;
}

// ��10����ֵ��������Ԫ��
DuLNode *LocateElem(DuLinkList L, ElemType e)
{
    if (!L->next) // ˵���ǿձ�
    {
        printf("This DuLinkList is empty!\n");
        return L;
    }
    DuLNode *p = L;
    while (p->next) // ���next����
    {
        p = p->next;
        if (p->next == e)
            return p;
    }
    printf("The DuLinkList's element you are looking for does not exist!\n");
    return NULL; // �����ڵĻ�����NULL
}

// ��12��˫����İ�λɾ��
bool LocalDeleteElem(DuLinkList L, ElemType i, ElemType *e)
{
    //[1]���i�ĺϷ���
    if (!L->next) // �ձ�ֱ���˳�
    {
        printf("This DuLinkList is empty!\n");
        *e = 9999;
        return false;
    }
    if (i < 1 || i > L->data) // �ȱ�С/��Ҳ����ɾ
    {
        printf("The position of the element is invalid!\n");
        *e = 9999;
        return false;
    }
    //[2]ɾ��ָ��Ԫ��
    DuLNode *p = GetElem(L, i - 1); // ��ɾ��Ԫ�ص�ǰ�����
    DuLNode *q = p->next;           // ��ɾ��Ԫ��
    p->next = q->next;
    *e = q->data;
    free(q);
    L->data--;
    return true;
}
// ��12-2�����������˫����İ�λɾ��
bool LocalDeleteElem_Del(DuLinkList L, ElemType i, ElemType *e)
{
    //[1]���i�ĺϷ���
    if (!L->next) // �ձ�ֱ���˳�
    {
        printf("This DuLinkList is empty!\n");
        *e = 9999;
        return false;
    }
    if (i < 1 || i > L->data) // �ȱ�С/��Ҳ����ɾ
    {
        printf("The position of the element is invalid!\n");
        *e = 9999;
        return false;
    }
    //[2]ɾ��ָ��Ԫ��
    DuLNode *p = GetElem_Del(L, i - 1); // ��ɾ��Ԫ�ص�ǰ�����
    DuLNode *q = p->next;               // ��ɾ��Ԫ��
    p->next = q->next;
    *e = q->data;
    free(q);
    L->data--;
    return true;
}
// ��11����λ����
bool LocalInsertDuLinkList(DuLinkList L, ElemType i, ElemType e)
{
    //[1]�ж�i�ĺϷ���
    if (i < 1 || i > (L->data + 1)) // ���ܲ��ڵ�0λ���һλ��ֻ��5λ���ڵ���λ��
    {
        printf("The position of the element to be inserted is invalid!\n");
        return false;
    }
    //[2]������Ԫ��
    // ��
    // DuLNode *p=GetElem(L,i-1);//�ҵ�ǰһ��
    // DuLNode *NewNode=(DuLNode*)malloc(sizeof(DuLNode));//�����µĽ��
    // NewNode->prior=p;
    // NewNode->next=p->;

    DuLNode *p = GetElem(L, i - 1);                        // �ҵ�ǰһλ��ָ�� ���i=1����ôGetElem(L,0),0������Ƿ���L����ô�Ͳ���ͷ������һλ
    DuLNode *NewNode = (DuLNode *)malloc(sizeof(DuLNode)); // �����µĽ��
    NewNode->data = e;
    NewNode->next = p->next; // ���½���next��ָ����һ�����
    p->next = NewNode;       // ��p��next��ָ���½��
    L->data++;
    return true;
}
// ��13������˫����
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
    DuLinkList L; // ��ʼ��ͷָ�루��㣩
    printf("\n\n\n\n");
    L = (DuLNode *)malloc(sizeof(DuLNode)); // ����д�ڳ�ʼ�� ��ΪL�ڳ�ʼ�����Ǹ���ʱ���� ��������ʱL������
    printf("˫����ADT\n\n1.��ʼ������\n2.�����½��\n3.ɾ�����\n4.��������\n5.��ѯ�����ֵ\n6.��ѯ�м���\n7.�˳�ϵͳ\n");
    printf("�������Ӧ������(1~7):");
    int x;
    while (scanf("%d", &x) == 0)
    {
        rewind(stdin);
        printf("�����������ʹ���\n");
        printf("������һ����(1~7):");
    }
    while (x > 1)
    {
        rewind(stdin);
        printf("���ȴ�������\n");
        printf("������һ����(1~7):");
        while (scanf("%d", &x) == 0)
        {
            rewind(stdin);
            printf("�����������ʹ���\n");
            printf("������һ����(1~7):");
        }
    }
    {
        system("cls");
        InitDuLinkList(L);
        printf("��������Ҫ�������ĸ�����");
        scanf("%d", &o);
        TailInsertDuLinkList(L, count, o); // β�巨
        printf("˫�������ɹ���\n");
    }
    system("cls");
    PrintDuLinkList(L);
    printf("˫�������ɹ�!\n");
    printf("\n");
    printf("˫����ADT\n\n1.��ʼ������\n2.�����½��\n3.ɾ�����\n4.��������\n5.��ѯ�����ֵ\n6.��ѯ�м���\n7.�˳�ϵͳ\n");
    printf("�������Ӧ������(1~7):");
    scanf("%d", &x);
    while (1)
    {
        if (x == 1)
        {
            system("cls");
            printf("�����Ѵ����ɹ��������ظ�������\n");
        }
        else if (x == 2)
        {
            system("cls");
            PrintDuLinkList(L);
            printf("��������Ҫ�����λ���Լ�Ҫ�����ֵ��");
            scanf("%d", &j);
            printf("\n");
            scanf("%d", &k);
            LocalInsertDuLinkList(L, j, k);
            printf("�ɹ������½��\n");
            printf("���������£�\n");
            PrintDuLinkList(L); // ��������
            system("pause");
        }
        else if (x == 3)
        {
            system("cls");
            PrintDuLinkList(L);
            printf("������Ҫɾ������λ�ã�");
            scanf("%d", &n);
            LocalDeleteElem(L, n, &e);
            printf("�ѳɹ�ɾ���ý�㣡\n");
            printf("���������£�\n");
            PrintDuLinkList(L); // ��������
        }
        else if (x == 4)
        {
            system("cls");
            PrintDuLinkList(L); // ��������
        }
        else if (x == 5)
        {
            system("cls");
            PrintDuLinkList(L);
            printf("������������ҵ�λ�ã�");
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
                printf("��λ�õ�ֵΪ%d\n", GetElem(L, l)->data);
            }
        }
        else if (x == 6)
        {
            system("cls");
            DuLNode *p = L;
            for (int j = 0; j < (o / 2 + 1); j++) // Ҳ����д��j=1;j<=i
            {
                p = p->next;
            }
            printf("�м����Ӧ��������ֵΪ%d\n", p->data);
        }
        else if (x == 7) // �ÿ������˳�
        {
            system("cls");
            DestroyDuLinkList(L);
            printf("����ɾ�����!\n���˳�ϵͳ!");
            break;
        }
        else if (x > 7)
        {
            system("cls");
            printf("���๦�ܾ����ڴ���");
        }
        printf("\n\n");
        printf("˫����ADT\n\n1.��ʼ������\n2.�����½��\n3.ɾ�����\n4.��������\n5.��ѯ�����ֵ\n6.��ѯ�м���\n7.�˳�ϵͳ\n");
        printf("�������Ӧ������(1~7):");
        scanf("%d", &x);
    }
    system("pause");
    return 0;
}
