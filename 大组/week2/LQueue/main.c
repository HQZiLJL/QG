#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LQueue.h"

int p = 0;

// ʹ��void*���洢��Щ��ַ  
void* genericPointer;
//int intValue;
//float floatValue;
//char charValue;
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
void DestoryLQueue(LQueue* q) {
	Node* r = (Node*)malloc(sizeof(Node*));
	r = q->front->next;
	while (q->rear != q->front) {
		q->front->next = r->next;
		if (r->next == NULL)//!!!!!!!!!!!!!!!!!!
			q->rear = q->front;
		//(q->front->data--);
		//free(r);
		r = r->next;
	}
}

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
    if (q->rear == NULL) {
        q->front = q->rear = t;
    }
    else {
        q->rear->next = t;//data���
        q->rear = t;
    }

    return 1;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
void* DeLQueue(LQueue* q) {
	if (IsEmptyLQueue(q)) //�ж϶����Ƿ��
	{
		printf("The Q is empty!\n");
		return NULL;
	}
	//�ƶ���ͷָ��
	Node* r = q->front;
	void* e = r->data;//ȡ��ͷԪ��
	q->front = q->front->next;
	if (r->next == NULL)//!!!!!!!!!!!!!!!!!!
		q->rear = q->front;
	//q->front->data--;
	//free(r);
    r->next = NULL;
	return e;
}

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
        next = q->front;
        if (q->front == NULL&&q->rear==NULL)
            printf("�ö��б������ǿ�~");
        else
            while (next == NULL) 
            {
			    //next = q->front->next;
			    next->data = 0;
			    next=next->next;
		    }
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
            int* intData = (int*)temp->data;
            printf("%d-->", *intData);  
            //printf("%d..", temp);
            //printf("%d..", temp->data);
            //temp->data = (void*)intData;
        }
        else if (temp->type == 2) {
            //����һ���µĸ������������洢���Ƶ�����  
            float copiedFloatValue;
            // ʹ��memcpy��������  
            memcpy(&copiedFloatValue, temp->data, sizeof(float));
            printf("%f-->", copiedFloatValue);
        }
        else if (temp->type == 3) {
            //����һ���µ��ַ��������洢���Ƶ�����  
            char copiedCharValue[200];
            // ʹ��memcpy��������  
            memcpy(&copiedCharValue, temp->data, 200*sizeof(char));
            printf("%s-->", copiedCharValue);
        }
			temp = temp->next;
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
        if (cur->type == 1) {
            //����һ���µ������������洢���Ƶ�����  
            int* intData = (int*)cur->data;
            int* intc = (void*)x;
            if (*intData == *intc)
            {
                return cur;
            }
        }
        else if (cur->type == 2) {
            //����һ���µĸ������������洢���Ƶ�����  
            float* floatData = (float*)cur->data;
            float* floatc = (float*)x;
            if (*floatData == *floatc)
            {
                return cur;
            }
        }
        else if (cur->type == 3) {
            //����һ���µ��ַ��������洢���Ƶ�����  
            char* charData = (char*)cur->data;
            char* charc = (char*)x;
            if (*charData == *charData)
            {
                return cur;
            }
            if (cur->data == x)
            {
                return cur;
            }
        }
        cur = cur->next;
        q++;
    }
    return NULL;
}
void search(LQueue* q);
void* getInput(int type);
void* convere();
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
            printf("����������Ҫ�������ݵ���������(1:���� 2:������ 3:�ַ���)��");
            EnLQueue(q, convere());
            printf("�¶������£�");
            TraverseLQueue(q);
        }
        else if (x == 4)
        {
            system("cls");
            void* e=DeLQueue(q);
            int *a = (int*)e;
            printf("��ͷԪ��ֵΪ%d",a);
        }
        else if (x == 5)
        {
            system("cls");
            search(q);
            
        }
        else if (x == 6)
        {
            system("cls");
            TraverseLQueue(q);
        }
        else if (x == 7) // �ÿ������˳�
        {
            system("cls");
            DestoryLQueue(q);
            printf("�������ÿգ�\n");
            break;
        }
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
     printf("����������Ҫ�������ݵ���������(1:���� 2:������ 3:�ַ���)��");
     Node* node = LQueue_Search(q, convere());
     if (node == NULL)
         printf("���������ڸ�����");
     else
         printf("��ֵ�Ŷ����е�%dλ\n", p+1);
 }

 void* getInput(int type) { 
     void* get;
     switch (type)
     {
     case 1: {
         int* intValue = (int*)malloc(sizeof(int));
         printf("������һ������: ");
         while (scanf_s("%d", intValue) == 0)
         {
             rewind(stdin);
             printf("�����������ʹ���\n");
             printf("������һ��������");
         }
         get = (void*)intValue;
         return get;
     }
     case 2: {
         float* floatValue = (float*)malloc(sizeof(float));
         printf("������һ��������: ");
         while (scanf_s("%f", floatValue) == 0)
         {
             rewind(stdin);
             printf("�����������ʹ���\n");
             printf("������һ����������");
         }
         get = (void*)floatValue;
         return get;
     }
     case 3: {
         char* charValue = (char*)malloc(100);
         if (charValue == NULL) {
             printf("�ڴ����ʧ��\n");
             return 1;
         }
         printf("������һ���ַ���: ");
         // ʹ��scanf��ȡ���뵽myString��  
         fgets(charValue, 100, stdin);

         // ȥ�����ܴ��ڵĻ��з�  
         charValue[strcspn(charValue, "\n")] = 0;
         // ע�⣺%s�����ȡ�ո������Ҫ��ȡ�ո���ʹ����������������fgets  

         // ��ӡ�ַ���  
         printf("��������ַ�����: %s\n", charValue);
//         char *charValue = (char*)malloc(sizeof(char));
//         //int q = 0;
//;        printf("������һ���ַ���: ");
//         //fflush(stdin);
//
//         fgets(charValue, sizeof(charValue)*100, stdin);
//         //while ((charValue[q++] = getchar()) != '\n');
//         //q--;/*
//         //charValue[q] = 0;*/
//         //while (scanf_s("%s", charValue) == 0)
//         //{
//         //    fflush(stdin);
//         //    printf("�����������ʹ���\n");
//         //    printf("������һ���ַ�����");
//         //}// ע��ո��������κοհ��ַ�  
         get = (void*)charValue;
         return get;
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
void* convere() {
      
      while (scanf_s("%d", &Type) == 0|| Type >3)
      {
          rewind(stdin);
          printf("����ӦΪ1~3��\n");
          printf("����������Ҫ�������ݵ��������ͣ�");
      }
      //printf("\n");
      if (Type == 1) {
          return getInput(1);
      }
      if (Type == 2) {
          return getInput(2);
      }
      if (Type == 3) {
          return getInput(3);
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