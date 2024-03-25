/***************************************************************************************
 *	File Name				:	dulinklist.h
 *	CopyRight				:	2024 QG Studio
 *	SYSTEM					:   win11
 *	Create Data				:	2024.3.21
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/

/**************************************************************
 *	Multi-Include-Prevent Section
 **************************************************************/

#ifndef DULINKEDLIST_H_INCLUDED
#define DULINKEDLIST_H_INCLUDED

/**************************************************************
 *	Macro Define Section
 **************************************************************/

#define OVERFLOW -1

/**************************************************************
 *	Struct Define Section
 **************************************************************/

// define element type
typedef int ElemType;

// define struct of linked list
typedef struct DuLNode
{
	ElemType data;
	struct DuLNode *prior, *next;
} DuLNode, *DuLinkList;

typedef struct DoubleList
{
	int data;
	DuLNode *front;
	DuLNode *tail;
} DuList;

// define Status �궨�岿�� ---bool
#define bool char
#define true 1
#define false 0

/**************************************************************
 *	Prototype Declare Section
 **************************************************************/

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
bool InitDuLinkList(DuLinkList L);

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
bool LocalDeleteElem_Del(DuLinkList L, ElemType i, ElemType *e);

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
bool HeadInsert_DuLinkList(DuLinkList L, ElemType count, ElemType o);
/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
bool TailInsertDuLinkList(DuLinkList L, ElemType count, ElemType o);

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
bool LocalDeleteElem(DuLinkList L, ElemType i, ElemType *e);

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
bool PrintDuLinkList(DuLinkList L);
bool DeleTail(DuLinkList L);
bool HeadTail(DuLinkList L);
DuLNode *find(DuLinkList L, ElemType dat);
bool insert(DuLinkList L, DuLNode *iterator, ElemType dat);

DuLNode *GetElem(DuLinkList L, ElemType i); //
bool DestroyDuLinkList(DuLinkList L);

/**************************************************************
 *	End-Multi-Include-Prevent Section
 **************************************************************/
#endif