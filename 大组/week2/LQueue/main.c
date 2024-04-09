#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LQueue.h"

int p = 0;

// 使用void*来存储这些地址  
void* genericPointer;
//int intValue;
//float floatValue;
//char charValue;
int Type;

/**
  *  @name        : void InitLQueue(LQueue *Q)
  *    @description : 初始化队列
  *    @param         Q 队列指针Q
  *  @notice      : None
  */
void InitLQueue(LQueue* q) {
	//将链队列置空
	//q=(LQueue*)malloc(sizeof(LQueue));
	//将队列头尾指针置为空
	Node* t = (Node*)malloc(sizeof(Node*));
	t->next = NULL;
	q->front = q->rear = t;
	q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *q)
 *    @description : 销毁队列
 *    @param         q 队列指针q
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
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue* q) {
	// 判断队列是否为空
	if (q->front == q->rear)
		return 1;
	return 0;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
void* GetHeadLQueue(LQueue* q) {
	if (IsEmptyLQueue(q) == 1)//若为空队
		return NULL;
	else
		return (q->front->next->data);
}

/*
 *  @name        : int LengthLQueue(LQueue *q)
 *    @description : 确定队列长度
 *    @param         q 队列指针q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
void* LengthLQueue(LQueue* q) {
	// 取队列中元素个数
	return(q->front->data);
}
	//取队头元素的值：静态操作


/*
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         q 队列指针q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue* q, void* data) {        //将元素data入队
    Node* t=(Node*)malloc(sizeof(Node*));
    t->data = data;
    t->type = Type;
	t->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = t;
    }
    else {
        q->rear->next = t;//data入队
        q->rear = t;
    }

    return 1;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
void* DeLQueue(LQueue* q) {
	if (IsEmptyLQueue(q)) //判断队列是否空
	{
		printf("The Q is empty!\n");
		return NULL;
	}
	//移动队头指针
	Node* r = q->front;
	void* e = r->data;//取队头元素
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
 *    @description : 清空队列
 *    @param         q 队列指针q
 *  @notice      : None
 */
void ClearLQueue(LQueue* q) { 
	{
		LQueue* q = (LQueue*)malloc(sizeof(LQueue*));
		Node* next = (Node*)malloc(sizeof(Node*));
        next = q->front;
        if (q->front == NULL&&q->rear==NULL)
            printf("该队列本来就是空~");
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
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
//, void (*foo)(void* q)
Status TraverseLQueue(LQueue* q) {// 遍历队列
	{
		Node* temp = (Node*)malloc(sizeof(Node*));
        temp = q->front->next;
		while (temp != NULL)
		{
            //printf("%d\n", temp->type);
        if (temp->type==1) {
            //创建一个新的整数变量来存储复制的内容  
            int* intData = (int*)temp->data;
            printf("%d-->", *intData);  
            //printf("%d..", temp);
            //printf("%d..", temp->data);
            //temp->data = (void*)intData;
        }
        else if (temp->type == 2) {
            //创建一个新的浮点数变量来存储复制的内容  
            float copiedFloatValue;
            // 使用memcpy复制内容  
            memcpy(&copiedFloatValue, temp->data, sizeof(float));
            printf("%f-->", copiedFloatValue);
        }
        else if (temp->type == 3) {
            //创建一个新的字符变量来存储复制的内容  
            char copiedCharValue[200];
            // 使用memcpy复制内容  
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
 *    @description : 操作函数
 *    @param         q 指针q

 *  @notice      : None
 */
//void LPrint(void* q);

Node* LQueue_Search(LQueue *q, void* x) // 泛式队列的查找
{
    Node* cur = q->front;
    p = 0;
    while (cur) // cur指向NULL时退出循环
    {   
        if (cur->type == 1) {
            //创建一个新的整数变量来存储复制的内容  
            int* intData = (int*)cur->data;
            int* intc = (void*)x;
            if (*intData == *intc)
            {
                return cur;
            }
        }
        else if (cur->type == 2) {
            //创建一个新的浮点数变量来存储复制的内容  
            float* floatData = (float*)cur->data;
            float* floatc = (float*)x;
            if (*floatData == *floatc)
            {
                return cur;
            }
        }
        else if (cur->type == 3) {
            //创建一个新的字符变量来存储复制的内容  
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
    printf("泛式链队列ADT\n\n1.初始化队列\n2.置空队列\n3.入队\n4.出队\n5.查找数据\n6.遍历队列\n7.退出(并销毁链表)\n");
    printf("请输入一个数(1~7):");
    int x;
    while (scanf_s("%d", &x) == 0)
    {
        rewind(stdin);
        printf("输入数据类型错误！\n");
        printf("请输入一个数(1~7):");
    }
    while (x > 2)
    {
        rewind(stdin);
        printf("请先创建队列！\n");
        printf("请输入一个数(1~7):");
        while (scanf_s("%d", &x) == 0)
        {
            rewind(stdin);
            printf("输入数据类型错误！\n");
            printf("请输入一个数(1~7):");
        }
    }
    if (x == 1)
    {
        system("cls");
        InitLQueue(q);
    }
    else {
        printf("请先创建队列\n");
        printf("请输入一个数(1~7):");
        while (scanf_s("%d", &x) == 0)
        {
            rewind(stdin);
            printf("输入数据类型错误！\n");
            printf("请输入一个数(1~7):");
        }
    }
    system("cls");
    printf("队列创建成功!\n");
    printf("\n\n\n");
    printf("泛式链队列ADT\n\n1.初始化队列\n2.置空队列\n3.入队\n4.出队\n5.查找数据\n6.遍历队列\n7.退出(并销毁链表)\n");
    printf("请输入一个数(1~7):");
    while (scanf_s("%d", &x) == 0)
    {
        rewind(stdin);
        printf("输入数据类型错误！\n");
        printf("请输入一个数(1~7):");
    }
    while (1)
    {
        if (x == 1)
        {
            system("cls");
            printf("队列已创建成功，无需重复创建。\n");
        }
        else if (x == 2)
        {
            system("cls");
            ClearLQueue(q);
            printf("已置空队列！");
        }
        else if (x == 3)
        {
            system("cls");
            printf("请输入你想要输入数据的数据类型(1:整型 2:浮点型 3:字符型)：");
            EnLQueue(q, convere());
            printf("新队列如下：");
            TraverseLQueue(q);
        }
        else if (x == 4)
        {
            system("cls");
            void* e=DeLQueue(q);
            int *a = (int*)e;
            printf("队头元素值为%d",a);
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
        else if (x == 7) // 置空链表并退出
        {
            system("cls");
            DestoryLQueue(q);
            printf("队列已置空！\n");
            break;
        }
        else if (x > 7)
        {
            system("cls");
            printf("更多功能敬请期待！");
        }
        printf("\n\n\n");
        printf("泛式链队列ADT\n\n1.初始化队列\n2.置空队列\n3.入队\n4.出队\n5.查找数据\n6.遍历队列\n7.退出(并销毁链表)\n");
        printf("请输入一个数(1~7):");
        scanf_s("%d", &x);
    }
    system("pause");
    return 0;
 }
 
 void search(LQueue *q)
 {
     printf("请输入你想要查找数据的数据类型(1:整型 2:浮点型 3:字符型)：");
     Node* node = LQueue_Search(q, convere());
     if (node == NULL)
         printf("此链表不存在该数！");
     else
         printf("该值排队列中第%d位\n", p+1);
 }

 void* getInput(int type) { 
     void* get;
     switch (type)
     {
     case 1: {
         int* intValue = (int*)malloc(sizeof(int));
         printf("请输入一个整数: ");
         while (scanf_s("%d", intValue) == 0)
         {
             rewind(stdin);
             printf("输入数据类型错误！\n");
             printf("请输入一个整数：");
         }
         get = (void*)intValue;
         return get;
     }
     case 2: {
         float* floatValue = (float*)malloc(sizeof(float));
         printf("请输入一个浮点数: ");
         while (scanf_s("%f", floatValue) == 0)
         {
             rewind(stdin);
             printf("输入数据类型错误！\n");
             printf("请输入一个浮动数：");
         }
         get = (void*)floatValue;
         return get;
     }
     case 3: {
         char* charValue = (char*)malloc(100);
         if (charValue == NULL) {
             printf("内存分配失败\n");
             return 1;
         }
         printf("请输入一个字符串: ");
         // 使用scanf读取输入到myString中  
         fgets(charValue, 100, stdin);

         // 去除可能存在的换行符  
         charValue[strcspn(charValue, "\n")] = 0;
         // 注意：%s不会读取空格，如果需要读取空格请使用其他方法，比如fgets  

         // 打印字符串  
         printf("你输入的字符串是: %s\n", charValue);
//         char *charValue = (char*)malloc(sizeof(char));
//         //int q = 0;
//;        printf("请输入一个字符串: ");
//         //fflush(stdin);
//
//         fgets(charValue, sizeof(charValue)*100, stdin);
//         //while ((charValue[q++] = getchar()) != '\n');
//         //q--;/*
//         //charValue[q] = 0;*/
//         //while (scanf_s("%s", charValue) == 0)
//         //{
//         //    fflush(stdin);
//         //    printf("输入数据类型错误！\n");
//         //    printf("请输入一个字符数：");
//         //}// 注意空格来跳过任何空白字符  
         get = (void*)charValue;
         return get;
     }
     }                 // 可以添加更多类型的case  
        //default:
        //    printf("无效的数据类型\n");
        //    result = -1; // 无效类型，返回错误  
        //}

        // 清除可能的输入错误  
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
          printf("输入应为1~3！\n");
          printf("请输入你想要输入数据的数据类型：");
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
        //    printf("队首为%d", head);
        //    //????????????
        //}
        //else if (x == 5)
        //{
        //    system("cls");
        //    search(q);
        //}