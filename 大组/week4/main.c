#include <stdio.h>  
#include <stdlib.h>  
#include "binary_sort_tree.h"
int q ;
void traverse(TreeNode* node) {
    printf("%d-->", node->val);
}

Status BST_init(BTREE* tree) {
    tree->root = (TreeNode*)malloc(sizeof(TreeNode));
    tree->root->val =NULL;
    tree->root->left = NULL;
    tree->root->right = NULL;
}

// 先序遍历（递归）  
void preorderTraversal(TreeNode* node, void (*visit)(TreeNode*)) {
    if (node != NULL) {
        visit(node);
        //printf("%d->", tree->root->val);
        preorderTraversal(node->left, visit);
        preorderTraversal(node->right, visit);
    }
}

// 中序遍历（递归）  
void inorderTraversal(TreeNode* node, void (*visit)(TreeNode*)) {
    if (node == NULL)
        return;
    inorderTraversal(node->left,visit);
    visit(node);
    //printf("%d->", tree->root->val);
    inorderTraversal(node->right,visit);
}

// 后序遍历（递归）  
void postorderTraversal(TreeNode* node, void (*visit)(TreeNode*)) {
    if (node == NULL)
        return;
    postorderTraversal(node->left, visit);
    postorderTraversal(node->right, visit);
    visit(node);
    //printf("%d ", tree->root->val);
}

//队列
Status IsEmpty(LQueue* q) {
    if (q->front == NULL&&q->rear== NULL)
        return 1;
    return 0;
}
void push(LQueue* q, TreeNode* node) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->node = node;
    newnode->next = NULL;
    if (q->rear == NULL && q->front == NULL) {
        q->front = q->rear = newnode;
    }
    else {
        q->rear->next = newnode;//data入队
        q->rear = newnode;
    }
}

TreeNode* pull(LQueue* q) {
    if (IsEmpty(q))
        return NULL;
    if (q->front == q->rear) {
        // 只有一个节点的情况  
        Node* temp = q->front;
        q->front = q->rear = NULL;
        temp->next = NULL;
        return temp->node;
    }
    Node* temp = q->front;
    q->front = q->front->next;
    temp->next = NULL;
    return temp->node;
}
//层次遍历
// 需要一个容器，临时存储上一层节点
//遍历顺序和进入
//离开容器的顺序一致：先进先出
Status BST_levelOrder(BTREE* tree, void(*visit)(TreeNode*)) {
    LQueue* q = (LQueue*)malloc(sizeof(LQueue));
    if (q != NULL) {
        q->front = NULL;
        q->rear = NULL;
        q->length = 0;
    }
    else {
        // 处理内存分配失败的情况  
        return 0;
    }
    push(q,tree->root);
    while (!IsEmpty(q)) {
        TreeNode* node = pull(q);
        visit(node);
        if (node->left!=NULL)
            push(q, node->left);
        if (node->right != NULL)
            push(q, node->right);
    }
}
//查询数据
TreeNode* BST_search(TreeNode* tree, ElemType key)
{
    TreeNode* node = tree;
    q = 1;
    while (node != NULL)
    {
        //1,判断要查找的关键字值与当前节点值是否相同，若相同直接返回
        if (key == node->val) {
            return node;
        }
        else if (key < node->val) {
            node = node->left;
            q++;
        }
        else {
            node = node->right;
            q++;
        }
            
    }
    return node;
}
//插入数据
Status BST_insert(BTREE* tree,ElemType key) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = key;
    node->left = NULL;
    node->right = NULL;
    if (tree->root->val == NULL) {
        //空树
        tree->root->val = node->val;
        return 1;
    }
    TreeNode *pos = tree->root, *parent = NULL;
    pos = tree->root;
    while(pos != NULL ) {
        parent = pos;
        if (key < pos->val) {
            pos = pos->left;
        }
        else if (key > pos->val) {
            pos = pos->right;
        }
        else
            return 0;
    }
    if (key < parent->val) {
        parent->left = node;
    }
    else if (key > parent->val) {
        parent->right = node;
    }
    return 1;
}
//删除数据int* a
//int *a=45;
// 
//*a=45;
//TreeNode* *tree->root
//* *tree->root
int BST_delete(BTREE* tree, ElemType key) {
    //*tree->root = malloc(sizeof(TreeNode));
    TreeNode* node = NULL, * parent = NULL, * temp = tree->root;
    while (temp != NULL) {
        if (key == temp->val) {
            node = temp;
            break;
        }
        parent = temp;
        if (key < temp->val) {
            temp = temp->left;
        }
        else
            temp = temp->right;
    }
    //可能查找不到指定关键字值对应的节点
    if (node == NULL)
        return 0;
    //2.检查当前待删节点是否符合如下条件：
    if (node->left == NULL || node->right == NULL) 
    {
        TreeNode* subnode=(TreeNode*)malloc(sizeof(TreeNode));
        //*subnode = malloc(sizeof(TreeNode));
        subnode->val = NULL;
        subnode->left = NULL;
        subnode->right = NULL;
        if (node->left == NULL)
            //待删节点左子树为空，用右子树替代
            subnode = node->right;
        else
            subnode = node->right;
        if (parent != NULL) {
            if (parent->left == node)
                parent->left = subnode;
            else
                parent->right = subnode;
        }
        else
            tree->root = subnode;
        return 1;
    }
    //左右子树都存在，按中序遍历查找该节点的替代节点（前驱/后继）
    TreeNode* replacer = node;
    BTREE* replacerParent = (BTREE*)malloc(sizeof(BTREE));
    replacerParent->root= parent;
    //查找直接前驱
    temp= node->left;
    //temp= node->right;
    while (temp != NULL) {
        replacerParent = replacer;
        replacer = temp;
        temp = temp->right;
        //temp= temp->left;
    }
    //3.递归删除操作：删除替代节点
    BST_delete(replacerParent, replacer->val);
     //4.使用替代节点换掉原来的待删节点
     if (parent != NULL) {   
         if (parent->left == node) 
         {
             parent->left = NULL;
             parent->left = replacer;
         }
         else
         {
             parent->right = NULL;
             parent->right = replacer;
         }
     }
     else {
         tree->root = node;
     }
     replacer->left = node->left;
     replacer->right = node->right;
     node->left = NULL;
     node->right = NULL;
     return 1;
}

// 初始化栈  
void InitStack(LinkStack* s) {
    s->top = NULL;
    s->count = 0;
}

// 判断栈是否为空  
int StackEmpty(LinkStack* s) {
    return s->count;
}

// 入栈  
void Push(LinkStack* s,TreeNode* e) {
    LinkStackPtr* node = (LinkStackPtr*)malloc(sizeof(LinkStackPtr));
    node->data = e;
    //node->next = s->top;
    s->top = node;
    s->count++;
    //printf("%d", s->count);
}

// 出栈  
TreeNode* Pop(LinkStack* s) {
    TreeNode* e = (TreeNode*)malloc(sizeof(TreeNode));
    if (!StackEmpty(s)) {
        return NULL;
    }
    LinkStackPtr* node = (LinkStackPtr*)malloc(sizeof(LinkStackPtr));
    node->next = NULL;
    node = s->top;
    e = node->data;
    s->top = node->next;
    free(node);
    s->count--;
    return e;
}
// 清除栈  
void ClearStack(LinkStack* s) {
    LinkStackPtr* p, * q;
    p = s->top;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
    s->top = NULL;
    s->count = 0;
}

// 销毁栈  
void DestroyStack(LinkStack* s) {
    ClearStack(s);
}

// 创建二叉树节点  
TreeNode* CreateNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 插入节点到二叉排序树  
void Insert(BTREE* tree, int val) {
    TreeNode** p = &(tree->root);
    TreeNode* node = CreateNode(val);
    while (*p) {
        if (val < (*p)->val) {
            p = &(*p)->left;
        }
        else {
            p = &(*p)->right;
        }
    }
    *p = node;
}

void PreOrderTraversal(BTREE* tree, void (*visit)(TreeNode*))//非递归前序遍历
{
    if (tree == NULL || tree->root == NULL)
    {
        printf("NULL");
        return;
    }

    TreeNode* stack[100]; // 假设树高度不超过100  
    int top = -1;
    TreeNode* p = tree->root;

    while (p != NULL || top != -1) //直到p为NULL并且栈空结束
    {
        while (p != NULL) // 遍历左子树，并将节点压入栈  
        {
            visit(p);         // 打印节点  
            stack[++top] = p;//防止覆盖原来值和数组越界
            p = p->left;
        }
        if (top != -1) {    // 弹出栈顶元素，并转向右子树  
            p = stack[top--];
            p = p->right;
        }
    }
}
// 先序遍历（非递归）  
//void reOrderTraversal(BTREE* tree) {//错误代码
//    if (tree == NULL || tree->root == NULL) {
//        return;
//    }
//    LinkStack *s=(LinkStack*)malloc(sizeof(LinkStack));
//    InitStack(s);
//    TreeNode* p = tree->root;
//    LinkStackPtr* nodePtr = (LinkStackPtr*)malloc(sizeof(LinkStackPtr));
//    nodePtr->data = p;
//    nodePtr->next = NULL;
//    Push(s, nodePtr);
//    while (p!=NULL||StackEmpty(s)) {
//        while (p != NULL) {
//            Pop(s);
//            printf("%d-->", p->val); // 访问节点  
//            if(p->right != NULL) Push(s, p->right); 
//            if(p->left != NULL) Push(s, p->left);
//            p = p->left;
//        }
//        if (StackEmpty(s)) {
//            nodePtr = (LinkStackPtr*)malloc(sizeof(LinkStackPtr));
//            nodePtr->data = NULL;
//            //nodePtr->next = NULL;
//            nodePtr->data = Pop(s);
//            printf("%d-->", nodePtr->data->val);
//            if (nodePtr->data == NULL) break;
//            else p = nodePtr->data->left ? nodePtr->data->left : nodePtr->data->right;
//            free(nodePtr); // 释放之前分配的节点  
//        }
//    }
//    //ClearStack(s);
//}

void InOrderTraversal(BTREE* tree, void (*visit)(TreeNode*))//非递归中序遍历
{
    if (tree == NULL || tree->root == NULL) {
        printf("NULL");
        return;
    }
    TreeNode* stack[100]; // 假设栈的大小足够大  
    int top = -1;
    TreeNode* cur = tree->root;

    while (cur != NULL || top != -1) {
        // 遍历左子树，并将节点压入栈  
        while (cur != NULL) {
            stack[++top] = cur;
            cur = cur->left;
        }
        // 弹出栈顶元素并访问  
        cur = stack[top--];
        visit(cur);
        // 转向右子树  
        cur = cur->right;
    }
}

// 后序遍历（非递归）  
//void PostOrderTraversal(BTREE* tree) {
//    if (tree == NULL || tree->root == NULL) {
//        return;
//    }
//    LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
//    InitStack(s);
//    TreeNode* p = tree->root;
//    while (p || !StackEmpty(s)) {
//        while (p) {
//            Push(s, p);
//            p = p->left;
//        }
//        if (StackEmpty(s)) {
//            LinkStackPtr* nodePtr = (LinkStackPtr*)malloc(sizeof(LinkStackPtr));
//            nodePtr->data = Pop(s);
//            printf("%d-->", nodePtr->data->val); // 访问节点  
//            if (nodePtr->data == NULL) break;
//            else p = nodePtr->data->right;
//        }
//    }
//}

void PostOrderTraversal(BTREE* tree, void (*visit)(TreeNode*)) {	// 非递归的后序遍历
    TreeNode* root = tree->root;
    if (tree == NULL || tree->root == NULL) {
        printf("NULL");
        return;
    }
    TreeNode* stack1[100], * stack2[100];
    int top1 = -1, top2 = -1;
    TreeNode* p, temp;

    stack1[++top1] = root; // 将根节点压入stack1  

    while (top1 != -1) {
        // 弹出stack1的栈顶元素  
        p = stack1[top1--];

        // 将p压入stack2，表示p的后序遍历应该在其子树之后  
        stack2[++top2] = p;

        // 先处理右子树，再处理左子树（因为栈是后入先出的）  
        if (p->right != NULL) {
            stack1[++top1] = p->right;
        }
        if (p->left != NULL) {
            stack1[++top1] = p->left;
        }
    }

    // 弹出stack2中的节点，并访问它们（逆后序遍历顺序）  
    while (top2 != -1) {
        p = stack2[top2--];
        visit(p); // 访问节点  
    }

}
// 后序遍历（左-右-根）(错误代码）
//void ostOrderTraversal(BTREE* tree) {
//    if (tree == NULL || tree->root == NULL) {
//        return;
//    }
//    LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
//    InitStack(s);
//    TreeNode* p = tree->root;
//    TreeNode* node = NULL;
//    TreeNode* n = p;
//    while (p != NULL) {
//
//        Stack_push(s, p, 0);
//        p = p->left;
//    }
//    while (StackEmpty(s)) {
//        int visited = (int*)malloc(sizeof(int));
//        visited = 0;
//        Stack_pop(s, &p,visited);
//        if (p == 0) p = n;
//        //if (p == NULL) return NULL;
//        // 如果当前节点没有访问过，并且它没有右子树，或者右子树已经被访问过  
//        if (!visited && (p->right == NULL || p->right == node)) {
//            printf("%d-->", p->val); // 访问节点  
//            node = p;
//        }
//        else {
//            // 否则，把当前节点标记为未访问，并重新压入栈  
//            Stack_push(s, p, 1);
//            // 如果当前节点有右子树，则将右子树设为当前节点  
//            if (p->right != NULL) {
//                p = p->right;
//                // 遍历右子树的左子树  
//                while (p != NULL) {
//                    Stack_push(s, p, 0);
//                    p = p->left;
//                }
//            }
//        }
//    }
//}
void search(BTREE* tree);
void insert(BTREE* tree);
void delete(BTREE* tree);
int main()
{
    BTREE* tree = (BTREE*)malloc(sizeof(BTREE));
    printf("\n\n\n\n");
    printf("二叉树ADT\n\n1.初始化二叉树\n2.查找数据\n3.插入数据\n4.删除数据\n5.先序遍历\n6.中序遍历\n7.后序遍历\n8.层次遍历\n9.先序遍历(非递归)\n10.中序遍历(非递归)\n11.后序遍历(非递归)\n12.退出(并置空链表)\n");
    printf("请输入一个数(1~12):");
    int x;
    while (scanf_s("%d", &x) == 0)
    {
        rewind(stdin);
        printf("输入数据类型错误！\n");
        printf("请输入一个数(1~11):");
    }
    while (x > 1)
    {
        rewind(stdin);
        printf("请先创建二叉树！\n");
        printf("请输入一个数(1~11):");
        while (scanf_s("%d", &x) == 0)
        {
            rewind(stdin);
            printf("输入数据类型错误！\n");
            printf("请输入一个数(1~11):");
        }
    }
    if (x == 1)
    {
        system("cls");
        BST_init(tree);
    }
    system("cls");
    printf("二叉树创建成功！");
    printf("\n\n\n");
    printf("二叉树ADT\n\n1.初始化二叉树\n2.查找数据\n3.插入数据\n4.删除数据\n5.先序遍历\n6.中序遍历\n7.后序遍历\n8.层次遍历\n9.先序遍历(非递归)\n10.中序遍历(非递归)\n11.后序遍历(非递归)\n12.退出(并置空链表)\n");
    printf("请输入一个数(1~12):");
    scanf_s("%d", &x);
    while (1)
    {
        if (x == 1)
        {
            system("cls");
            printf("二叉树已创建成功，无需重复创建。\n");
        }
        else if (x == 2)
        {
            system("cls");
            search(tree);
        }
        else if (x == 3)
        {
            system("cls");
            insert(tree);
        }
        else if (x == 4)
        {
            system("cls");
            delete(tree);
        }
        else if (x == 5)//先序遍历
        {
            system("cls");
            preorderTraversal(tree->root, traverse);
        }
        else if (x == 6)//中序遍历
        {
            system("cls");
            inorderTraversal(tree->root, traverse);
        }
        else if (x == 7) //后序遍历
        {
            system("cls");
            postorderTraversal(tree->root, traverse);
        }
        else if (x == 8) //层次遍历
        {
            system("cls");
            BST_levelOrder(tree, traverse);
        }
        else if (x == 9) 
        {
            system("cls");
            PreOrderTraversal(tree, traverse);
        }
        else if (x == 10)
        {
            system("cls");
            InOrderTraversal(tree, traverse);
        }
        else if (x == 11) 
        {
            system("cls");
            PostOrderTraversal(tree, traverse);

        }
        else if (x == 12) // 置空链表并退出
        {
            system("cls");
            break;
        }
        else if (x > 12)
        {
            system("cls");
            printf("更多功能敬请期待！");
        }
        printf("\n\n\n");
        printf("二叉树ADT\n\n1.初始化二叉树\n2.查找数据\n3.插入数据\n4.删除数据\n5.先序遍历\n6.中序遍历\n7.后序遍历\n8.层次遍历\n9.先序遍历(非递归)\n10.中序遍历(非递归)\n11.后序遍历(非递归)\n12.退出(并置空链表)\n");
        printf("请输入一个数(1~12):");
        scanf_s("%d", &x);
    }
    system("pause");
    return 0;
}

void search(BTREE* tree)
{
    printf("请输入想要查找数据：");
    int x;
    while (scanf_s("%d", &x) == 0)
    {
        rewind(stdin);
        printf("输入数据类型错误！\n");
        printf("请输入想要查找数据：");
    }
    TreeNode* node = BST_search(tree->root,x);
    if (node == NULL)
        printf("此二叉树不存在该数！");
    else
        printf("第%d位数字\n", q);
}

void insert(BTREE* tree)
{

    printf("请输入插入数据：");
    int x;
    while (scanf_s("%d", &x) == 0)
    {
        rewind(stdin);
        printf("输入数据类型错误！\n");
        printf("请输入插入数据：");
    }
    BST_insert(tree, x);
    printf("新二叉树如下：\n");
    inorderTraversal(tree->root, traverse);
}
void delete(BTREE* tree)
{
    printf("请输入删除的数据：");
    int x;
    while (scanf_s("%d", &x) == 0)
    {
        rewind(stdin);
        printf("输入数据类型错误！\n");
        printf("请输入删除的数据：");
    }
    BST_delete(tree,x);
    printf("新二叉树如下：\n");
    inorderTraversal(tree->root, traverse);
    printf("NULL");
}

