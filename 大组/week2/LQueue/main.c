#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LQueue.h"

int p = 0;

// ʹ��void*���洢��Щ��ַ  
void* genericPointer;

int intValue;
float floatValue;
char charValue;
int Type;

/**
  *  @name        : void InitLQueue(LQueue *Q)
  *    @description : ��ʼ������
  *    @param         Q ����ָ��Q
  *  @notice      : None
  */
void InitLQueue(LQueue* q) {
	//���������ÿ�
	//q=(LQueue*)malloc(sizeof(LQueue));
	//������ͷβָ����Ϊ��
	Node* t = (Node*)malloc(sizeof(Node*));
	t->next = NULL;
	q->front = q->rear = t;
	q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *q)
 *    @description : ���ٶ���
 *    @param         q ����ָ��q
 *  @notice      : None
 */
//void DestoryLQueue(LQueue* q) {
//	Node* r = (Node*)malloc(sizeof(Node*));
//	r = q->front->next;
//	while (q->rear != q->front) {
//		q->front->next = r->next;
//		if (r->next == NULL)//!!!!!!!!!!!!!!!!!!
//			q->rear = q->front;
//		(q->front->data--);
//		free(r);
//		r = r->next;
//	}
//}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue* q) {
	// �ж϶����Ƿ�Ϊ��
	if (q->front == q->rear)
		return 1;
	return 0;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
void* GetHeadLQueue(LQueue* q) {
	if (IsEmptyLQueue(q) == 1)//��Ϊ�ն�
		return NULL;
	else
		return (q->front->next->data);
}

/*
 *  @name        : int LengthLQueue(LQueue *q)
 *    @description : ȷ�����г���
 *    @param         q ����ָ��q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
void* LengthLQueue(LQueue* q) {
	// ȡ������Ԫ�ظ���
	return(q->front->data);
}
	//ȡ��ͷԪ�ص�ֵ����̬����


/*
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         q ����ָ��q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue* q, void* data) {        //��Ԫ��data���
    Node* t=(Node*)malloc(sizeof(Node*));
    t->data = data;
    t->type = Type;
	t->next = NULL;
	q->rear->next = t;//data���
	q->rear = t;
	//(q->front->data)++;
    return 1;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
//void* DeLQueue(LQueue* q) {
//	if (IsEmptyLQueue(q)) //�ж϶����Ƿ��
//	{
//		printf("The Q is empty!\n");
//		return NULL;
//	}
//	//�ƶ���ͷָ��
//	Node *r = q->front->next;
//	void*  e = r->data;//ȡ��ͷԪ��
//	q->front->next = r->next;
//	if (r->next == NULL)//!!!!!!!!!!!!!!!!!!
//		q->rear = q->front;
//	(q->front->data)--;
//	free(r);
//	return e;
//}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         q ����ָ��q
 *  @notice      : None
 */
void ClearLQueue(LQueue* q) { 
	{
		LQueue* q = (LQueue*)malloc(sizeof(LQueue*));
		Node* next = (Node*)malloc(sizeof(Node*));
		
		do{
			next = q->front->next;
			next->data = 0;
			next=next->next;
		} while (next == NULL);
	}
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
//, void (*foo)(void* q)
Status TraverseLQueue(LQueue* q) {// ��������
	{
		Node* temp = (Node*)malloc(sizeof(Node*));
        temp = q->front->next;
		while (temp != NULL)
		{
            //printf("%d\n", temp->type);
        if (temp->type==1) {
            //����һ���µ������������洢���Ƶ�����  
            int copiedIntValue; 
            // ʹ��memcpy��������
            memcpy(&copiedIntValue, temp->data, sizeof(int));
            printf("%d-->", copiedIntValue);
            temp = temp->next;
            //printf("%d\n", temp->data);
        }
        else if (temp->type == 2) {
            //����һ���µĸ������������洢���Ƶ�����  
            float copiedFloatValue;
            // ��void�ĵ�ַ����int*ָ�� 
            float* floatValue;
            floatValue = (float*)temp->data;
            // ʹ��memcpy��������  
            memcpy(&copiedFloatValue, temp->data, sizeof(float));
            printf("%f-->", copiedFloatValue);
        }
        else if (temp->type == 3) {
            //����һ���µ��ַ��������洢���Ƶ�����  
            char copiedCharValue;
            // ��void�ĵ�ַ����int*ָ�� 
            char* charValue;
            charValue = (char*)temp->data;
            // ʹ��memcpy��������  
            memcpy(&copiedCharValue, temp->data, sizeof(char[100]));
            printf("%s-->", copiedCharValue);
        }
			/*temp = temp->next;*/
		}
		printf("NULL\n");
	}
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q

 *  @notice      : None
 */
//void LPrint(void* q);

Node* LQueue_Search(LQueue *q, void* x) // ��ʽ���еĲ���
{
    Node* cur = q->front;
    p = 0;
    while (cur) // curָ��NULLʱ�˳�ѭ��
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
void search(LQueue* q);
int getInput(int type, void* data);
void convere();
int main() {
    printf("\n\n\n\n");
    LQueue* q = (LQueue*)malloc(sizeof(LQueue*));
    printf("��ʽ������ADT\n\n1.��ʼ������\n2.�ÿն���\n3.���\n4.����\n5.��������\n6.��������\n7.�˳�(����������)\n");
    printf("������һ����(1~7):");
    int x;
    while (scanf_s("%d", &x) == 0)
    {
        rewind(stdin);
        printf("�����������ʹ���\n");
        printf("������һ����(1~7):");
    }
    while (x > 2)
    {
        rewind(stdin);
        printf("���ȴ������У�\n");
        printf("������һ����(1~7):");
        while (scanf_s("%d", &x) == 0)
        {
            rewind(stdin);
            printf("�����������ʹ���\n");
            printf("������һ����(1~7):");
        }
    }
    if (x == 1)
    {
        system("cls");
        InitLQueue(q);
    }
    else {
        printf("���ȴ�������\n");
        printf("������һ����(1~7):");
        while (scanf_s("%d", &x) == 0)
        {
            rewind(stdin);
            printf("�����������ʹ���\n");
            printf("������һ����(1~7):");
        }
    }
    system("cls");
    printf("���д����ɹ�!\n");
    printf("\n\n\n");
    printf("��ʽ������ADT\n\n1.��ʼ������\n2.�ÿն���\n3.���\n4.����\n5.��������\n6.��������\n7.�˳�(����������)\n");
    printf("������һ����(1~7):");
    while (scanf_s("%d", &x) == 0)
    {
        rewind(stdin);
        printf("�����������ʹ���\n");
        printf("������һ����(1~7):");
    }
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
            ClearLQueue(q);
            printf("���ÿն��У�");
        }
        else if (x == 3)
        {
            system("cls");
            convere();
            if (Type == 1) {
                // �������ĵ�ַ����void*ָ��  
                genericPointer = (void*)&intValue;
            }
            if (Type == 2) {
                // ���������ĵ�ַ����void*ָ��
                genericPointer = (void*)&floatValue;
            }
            if (Type == 3) {
                genericPointer = (void*)&charValue;
            }
            EnLQueue(q, genericPointer);
            printf("�¶������£�\n");
            TraverseLQueue(q);
        }
        else if (x == 6)
        {
            system("cls");
            TraverseLQueue(q);
        }
        //else if (x == 7) // �ÿ������˳�
        //{
        //    system("cls");
        //    ////DestoryLQueue(q);
        //    break;
        //}
        else if (x > 7)
        {
            system("cls");
            printf("���๦�ܾ����ڴ���");
        }
        printf("\n\n\n");
        printf("��ʽ������ADT\n\n1.��ʼ������\n2.�ÿն���\n3.���\n4.����\n5.��������\n6.��������\n7.�˳�(����������)\n");
        printf("������һ����(1~7):");
        scanf_s("%d", &x);
    }
    system("pause");
    return 0;
 }
 
 void search(LQueue *q)
 {
     printf("��������Ҫ���ҽ���������ֵ��");
     int x;
     while (scanf_s("%d", &x) == 0)
     {
         rewind(stdin);
         printf("�����������ʹ���\n");
         printf("��������Ҫ���ҽ���������ֵ��");
     }
     LQueue_Search(q, x);
     if (LQueue_Search(q, x) == NULL)
         printf("���������ڸ�����");
     else
         printf("��ֵ�Ŷ����е�%dλ\n", p);
 }

 int getInput(int type, void* data) { 
     switch (type)
     {
     case 1: {
         int* intValue = (int*)data;
         printf("������һ������: ");
         while (scanf_s("%d", intValue) == 0)
         {
             rewind(stdin);
             printf("�����������ʹ���\n");
             printf("������һ��������");
         }
         break;
     }
     case 2: {
         float* floatValue = (float*)data;
         printf("������һ��������: ");
         while (scanf_s("%f", floatValue) == 0)
         {
             rewind(stdin);
             printf("�����������ʹ���\n");
             printf("������һ����������");
         }
         break;
     }
     case 3: {
         char* charValue = (char*)data;
         printf("������һ���ַ�: ");
         while (scanf_s("%s", charValue) == 0)
         {
             rewind(stdin);
             printf("�����������ʹ���\n");
             printf("������һ���ַ�����");
         }// ע��ո��������κοհ��ַ�  
         break;
     }
     }                 // ������Ӹ������͵�case  
        //default:
        //    printf("��Ч����������\n");
        //    result = -1; // ��Ч���ͣ����ش���  
        //}

        // ������ܵ��������  
        /*if (result != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != eof);
        }*/
     return 0;
 }
void convere() {
      printf("����������Ҫ�������ݵ���������(1:���� 2:������ 3:�ַ���)��");
      while (scanf_s("%d", &Type) == 0|| Type >3)
      {
          rewind(stdin);
          printf("����ӦΪ1~3��\n");
          printf("����������Ҫ�������ݵ��������ͣ�");
      }
      if (Type == 1) {
          getInput(1, &intValue);
      }
      if (Type == 2) {
          getInput(2, &floatValue);
      }
      if (Type == 3) {
          getInput(3, &charValue);
      }
 }
//else if (x == 4)
        //{
        //    system("cls");
        //    void* head = DeLQueue(q);
        //    printf("����Ϊ%d", head);
        //    //????????????
        //}
        //else if (x == 5)
        //{
        //    system("cls");
        //    search(q);
        //}