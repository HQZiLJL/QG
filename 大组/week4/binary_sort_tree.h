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

// ��������������ڵ�Ľṹ�� 
typedef struct Treenode 
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;
typedef struct BTREE {
    TreeNode* root;
}BTREE;
//����
typedef struct Node
{
    TreeNode* node;        // ������ָ��
    struct Node* next;        // ָ��ǰ������һ���
}Node;

typedef struct Lqueue
{
    Node* front;   // ��ͷ
    Node* rear;    // ��β
    int length; // ���г���
} LQueue;

//ջ
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
//�ݹ�ǰ�����
void preorderTraversal(TreeNode* node, void (*visit)(TreeNode*));
//�ݹ��������
void inorderTraversal(TreeNode* node, void (*visit)(TreeNode*));
// �ݹ�ĺ������
void postorderTraversal(TreeNode* node, void (*visit)(TreeNode*));
Status BST_levelOrder(BTREE* tree, void(*visit)(TreeNode*));
// �����������ڵ�  
TreeNode* CreateNode(int val);
// ����ڵ㵽����������  
void Insert(BTREE* tree, int val);
//�ǵݹ�ǰ�����
void PreOrderTraversal(BTREE* tree, void (*visit)(TreeNode*));
//�ǵݹ��������
void InOrderTraversal(BTREE* tree, void (*visit)(TreeNode*));
// �ǵݹ�ĺ������
void PostOrderTraversal(BTREE* tree, void (*visit)(TreeNode*));	

//����
Status IsEmpty(LQueue* q);
void push(LQueue* q, TreeNode* node);
TreeNode* pull(LQueue* q);

//ջ
void InitStack(LinkStack* s);                          // ��ʼ��ջ
int StackEmpty(LinkStack* s);                          // �ж�ջ�Ƿ�Ϊ��
void Push(LinkStack* s, TreeNode* e);                  // ��ջ
TreeNode* Pop(LinkStack* s);                           // ��ջ
       
#endif //BINARYSORTTREE_BINARY_SORT_TREE_H