/***************************************************************************************
 *    File Name                :    LQueue.h
 *    CopyRight                :
 *
 *    SYSTEM                   :   
 *    Create Data              :    2024.3.31
 *    Author/Corportation      :    Chuan Shi
 *
 *
 *--------------------------------Revision History--------------------------------------
 *    No    version        Data            Revised By            Item            Description
 *
 *
 ***************************************************************************************/

 /**************************************************************
  *    Multi-Include-Prevent Section
  **************************************************************/
#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED


  /**************************************************************
   *    Struct Define Section
   **************************************************************/
   // 链式队列结构
typedef int ElemType;
typedef struct node
{
    void* data;        // 数据域指针
    struct node* next; 
    int type;// 指向当前结点的下一结点
} Node;

typedef struct Lqueue
{
    Node* front;   // 队头
    Node* rear;    // 队尾
    size_t length; // 队列长度
} LQueue;

typedef enum
{
    FALSE = 0,
    TRUE = 1
} Status;
char type;
char datatype[30];

/**************************************************************
 *    Prototype Declare Section
 **************************************************************/

 /**
  *  @name        : void InitLQueue(LQueue *Q)
  *    @description : 初始化队列
  *    @param         Q 队列指针Q
  *  @notice      : None
  */
void InitLQueue(LQueue* q);

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue* q);

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue* q);

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
void* GetHeadLQueue(LQueue* q);

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
void* LengthLQueue(LQueue* q);

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue* q, void* data);

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
void* DeLQueue(LQueue* q);

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue* q);

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
//, void (*foo)(void* q)
Status TraverseLQueue(LQueue* q);

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q

 *  @notice      : None
 */
//void LPrint(void* q);
Node* LQueue_Search(LQueue* q, void* x);
/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#endif // LQUEUE_H_INCLUDED


