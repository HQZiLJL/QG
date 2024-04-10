//
// Created by eke_l on 2024/4/7.
//
#ifndef BINARYSORTTREE_BINARY_SORT_TREE_H
#define BINARYSORTTREE_BINARY_SORT_TREE_H
typedef int ElemType;
typedef enum Status
{
    ERROR = 0,
    SUCCESS = 1
} Status;

// 定义二叉排序树节点的结构体 
typedef struct Treenode 
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;
typedef struct BTREE {
    TreeNode* root;
}BTREE;
//队列
typedef struct Node
{
    TreeNode* node;        // 数据域指针
    struct Node* next;        // 指向当前结点的下一结点
}Node;

typedef struct Lqueue
{
    Node* front;   // 队头
    Node* rear;    // 队尾
    int length; // 队列长度
} LQueue;

//栈
typedef struct StackNode
{
    TreeNode* data;
    int visited;
    struct StackNode* next;
}LinkStackPtr;

typedef struct LinkStack
{
    LinkStackPtr* top;
    int count;
}LinkStack;
/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
Status BST_init(BTREE* tree);

/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
Status BST_insert(BTREE* tree, ElemType);

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
int BST_delete(TreeNode*, ElemType);

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
TreeNode* BST_search(BTREE* tree, ElemType);

/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_levelOrder(BTREE* tree, void(*visit)(TreeNode*));
//递归前序遍历
void preorderTraversal(TreeNode* node, void (*visit)(TreeNode*));
//递归中序遍历
void inorderTraversal(TreeNode* node, void (*visit)(TreeNode*));
// 递归的后序遍历
void postorderTraversal(TreeNode* node, void (*visit)(TreeNode*));
Status BST_levelOrder(BTREE* tree, void(*visit)(TreeNode*));
// 创建二叉树节点  
TreeNode* CreateNode(int val);
// 插入节点到二叉排序树  
void Insert(BTREE* tree, int val);
//非递归前序遍历
void PreOrderTraversal(BTREE* tree, void (*visit)(TreeNode*));
//非递归中序遍历
void InOrderTraversal(BTREE* tree, void (*visit)(TreeNode*));
// 非递归的后序遍历
void PostOrderTraversal(BTREE* tree, void (*visit)(TreeNode*));	

//队列
Status IsEmpty(LQueue* q);
void push(LQueue* q, TreeNode* node);
TreeNode* pull(LQueue* q);

//栈
void InitStack(LinkStack* s);                          // 初始化栈
int StackEmpty(LinkStack* s);                          // 判断栈是否为空
void Push(LinkStack* s, TreeNode* e);                  // 入栈
TreeNode* Pop(LinkStack* s);                           // 出栈
       
#endif //BINARYSORTTREE_BINARY_SORT_TREE_H