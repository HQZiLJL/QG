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

// ����������ݹ飩  
void preorderTraversal(TreeNode* node, void (*visit)(TreeNode*)) {
    if (node != NULL) {
        visit(node);
        //printf("%d->", tree->root->val);
        preorderTraversal(node->left, visit);
        preorderTraversal(node->right, visit);
    }
}

// ����������ݹ飩  
void inorderTraversal(TreeNode* node, void (*visit)(TreeNode*)) {
    if (node == NULL)
        return;
    inorderTraversal(node->left,visit);
    visit(node);
    //printf("%d->", tree->root->val);
    inorderTraversal(node->right,visit);
}

// ����������ݹ飩  
void postorderTraversal(TreeNode* node, void (*visit)(TreeNode*)) {
    if (node == NULL)
        return;
    postorderTraversal(node->left, visit);
    postorderTraversal(node->right, visit);
    visit(node);
    //printf("%d ", tree->root->val);
}

//����
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
        q->rear->next = newnode;//data���
        q->rear = newnode;
    }
}

TreeNode* pull(LQueue* q) {
    if (IsEmpty(q))
        return NULL;
    if (q->front == q->rear) {
        // ֻ��һ���ڵ�����  
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
//��α���
// ��Ҫһ����������ʱ�洢��һ��ڵ�
//����˳��ͽ���
//�뿪������˳��һ�£��Ƚ��ȳ�
Status BST_levelOrder(BTREE* tree, void(*visit)(TreeNode*)) {
    LQueue* q = (LQueue*)malloc(sizeof(LQueue));
    if (q != NULL) {
        q->front = NULL;
        q->rear = NULL;
        q->length = 0;
    }
    else {
        // �����ڴ����ʧ�ܵ����  
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
//��ѯ����
TreeNode* BST_search(TreeNode* tree, ElemType key)
{
    TreeNode* node = tree;
    q = 1;
    while (node != NULL)
    {
        //1,�ж�Ҫ���ҵĹؼ���ֵ�뵱ǰ�ڵ�ֵ�Ƿ���ͬ������ֱͬ�ӷ���
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
//��������
Status BST_insert(BTREE* tree,ElemType key) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = key;
    node->left = NULL;
    node->right = NULL;
    if (tree->root->val == NULL) {
        //����
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
//ɾ������int* a
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
    //���ܲ��Ҳ���ָ���ؼ���ֵ��Ӧ�Ľڵ�
    if (node == NULL)
        return 0;
    //2.��鵱ǰ��ɾ�ڵ��Ƿ��������������
    if (node->left == NULL || node->right == NULL) 
    {
        TreeNode* subnode=(TreeNode*)malloc(sizeof(TreeNode));
        //*subnode = malloc(sizeof(TreeNode));
        subnode->val = NULL;
        subnode->left = NULL;
        subnode->right = NULL;
        if (node->left == NULL)
            //��ɾ�ڵ�������Ϊ�գ������������
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
    //�������������ڣ�������������Ҹýڵ������ڵ㣨ǰ��/��̣�
    TreeNode* replacer = node;
    BTREE* replacerParent = (BTREE*)malloc(sizeof(BTREE));
    replacerParent->root= parent;
    //����ֱ��ǰ��
    temp= node->left;
    //temp= node->right;
    while (temp != NULL) {
        replacerParent = replacer;
        replacer = temp;
        temp = temp->right;
        //temp= temp->left;
    }
    //3.�ݹ�ɾ��������ɾ������ڵ�
    BST_delete(replacerParent, replacer->val);
     //4.ʹ������ڵ㻻��ԭ���Ĵ�ɾ�ڵ�
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

// ��ʼ��ջ  
void InitStack(LinkStack* s) {
    s->top = NULL;
    s->count = 0;
}

// �ж�ջ�Ƿ�Ϊ��  
int StackEmpty(LinkStack* s) {
    return s->count;
}

// ��ջ  
void Push(LinkStack* s,TreeNode* e) {
    LinkStackPtr* node = (LinkStackPtr*)malloc(sizeof(LinkStackPtr));
    node->data = e;
    //node->next = s->top;
    s->top = node;
    s->count++;
    //printf("%d", s->count);
}

// ��ջ  
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
// ���ջ  
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

// ����ջ  
void DestroyStack(LinkStack* s) {
    ClearStack(s);
}

// �����������ڵ�  
TreeNode* CreateNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// ����ڵ㵽����������  
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

void PreOrderTraversal(BTREE* tree, void (*visit)(TreeNode*))//�ǵݹ�ǰ�����
{
    if (tree == NULL || tree->root == NULL)
    {
        printf("NULL");
        return;
    }

    TreeNode* stack[100]; // �������߶Ȳ�����100  
    int top = -1;
    TreeNode* p = tree->root;

    while (p != NULL || top != -1) //ֱ��pΪNULL����ջ�ս���
    {
        while (p != NULL) // �����������������ڵ�ѹ��ջ  
        {
            visit(p);         // ��ӡ�ڵ�  
            stack[++top] = p;//��ֹ����ԭ��ֵ������Խ��
            p = p->left;
        }
        if (top != -1) {    // ����ջ��Ԫ�أ���ת��������  
            p = stack[top--];
            p = p->right;
        }
    }
}
// ����������ǵݹ飩  
//void reOrderTraversal(BTREE* tree) {//�������
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
//            printf("%d-->", p->val); // ���ʽڵ�  
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
//            free(nodePtr); // �ͷ�֮ǰ����Ľڵ�  
//        }
//    }
//    //ClearStack(s);
//}

void InOrderTraversal(BTREE* tree, void (*visit)(TreeNode*))//�ǵݹ��������
{
    if (tree == NULL || tree->root == NULL) {
        printf("NULL");
        return;
    }
    TreeNode* stack[100]; // ����ջ�Ĵ�С�㹻��  
    int top = -1;
    TreeNode* cur = tree->root;

    while (cur != NULL || top != -1) {
        // �����������������ڵ�ѹ��ջ  
        while (cur != NULL) {
            stack[++top] = cur;
            cur = cur->left;
        }
        // ����ջ��Ԫ�ز�����  
        cur = stack[top--];
        visit(cur);
        // ת��������  
        cur = cur->right;
    }
}

// ����������ǵݹ飩  
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
//            printf("%d-->", nodePtr->data->val); // ���ʽڵ�  
//            if (nodePtr->data == NULL) break;
//            else p = nodePtr->data->right;
//        }
//    }
//}

void PostOrderTraversal(BTREE* tree, void (*visit)(TreeNode*)) {	// �ǵݹ�ĺ������
    TreeNode* root = tree->root;
    if (tree == NULL || tree->root == NULL) {
        printf("NULL");
        return;
    }
    TreeNode* stack1[100], * stack2[100];
    int top1 = -1, top2 = -1;
    TreeNode* p, temp;

    stack1[++top1] = root; // �����ڵ�ѹ��stack1  

    while (top1 != -1) {
        // ����stack1��ջ��Ԫ��  
        p = stack1[top1--];

        // ��pѹ��stack2����ʾp�ĺ������Ӧ����������֮��  
        stack2[++top2] = p;

        // �ȴ������������ٴ�������������Ϊջ�Ǻ����ȳ��ģ�  
        if (p->right != NULL) {
            stack1[++top1] = p->right;
        }
        if (p->left != NULL) {
            stack1[++top1] = p->left;
        }
    }

    // ����stack2�еĽڵ㣬���������ǣ���������˳��  
    while (top2 != -1) {
        p = stack2[top2--];
        visit(p); // ���ʽڵ�  
    }

}
// �����������-��-����(������룩
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
//        // �����ǰ�ڵ�û�з��ʹ���������û���������������������Ѿ������ʹ�  
//        if (!visited && (p->right == NULL || p->right == node)) {
//            printf("%d-->", p->val); // ���ʽڵ�  
//            node = p;
//        }
//        else {
//            // ���򣬰ѵ�ǰ�ڵ���Ϊδ���ʣ�������ѹ��ջ  
//            Stack_push(s, p, 1);
//            // �����ǰ�ڵ���������������������Ϊ��ǰ�ڵ�  
//            if (p->right != NULL) {
//                p = p->right;
//                // ������������������  
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
    printf("������ADT\n\n1.��ʼ��������\n2.��������\n3.��������\n4.ɾ������\n5.�������\n6.�������\n7.�������\n8.��α���\n9.�������(�ǵݹ�)\n10.�������(�ǵݹ�)\n11.�������(�ǵݹ�)\n12.�˳�(���ÿ�����)\n");
    printf("������һ����(1~12):");
    int x;
    while (scanf_s("%d", &x) == 0)
    {
        rewind(stdin);
        printf("�����������ʹ���\n");
        printf("������һ����(1~11):");
    }
    while (x > 1)
    {
        rewind(stdin);
        printf("���ȴ�����������\n");
        printf("������һ����(1~11):");
        while (scanf_s("%d", &x) == 0)
        {
            rewind(stdin);
            printf("�����������ʹ���\n");
            printf("������һ����(1~11):");
        }
    }
    if (x == 1)
    {
        system("cls");
        BST_init(tree);
    }
    system("cls");
    printf("�����������ɹ���");
    printf("\n\n\n");
    printf("������ADT\n\n1.��ʼ��������\n2.��������\n3.��������\n4.ɾ������\n5.�������\n6.�������\n7.�������\n8.��α���\n9.�������(�ǵݹ�)\n10.�������(�ǵݹ�)\n11.�������(�ǵݹ�)\n12.�˳�(���ÿ�����)\n");
    printf("������һ����(1~12):");
    scanf_s("%d", &x);
    while (1)
    {
        if (x == 1)
        {
            system("cls");
            printf("�������Ѵ����ɹ��������ظ�������\n");
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
        else if (x == 5)//�������
        {
            system("cls");
            preorderTraversal(tree->root, traverse);
        }
        else if (x == 6)//�������
        {
            system("cls");
            inorderTraversal(tree->root, traverse);
        }
        else if (x == 7) //�������
        {
            system("cls");
            postorderTraversal(tree->root, traverse);
        }
        else if (x == 8) //��α���
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
        else if (x == 12) // �ÿ������˳�
        {
            system("cls");
            break;
        }
        else if (x > 12)
        {
            system("cls");
            printf("���๦�ܾ����ڴ���");
        }
        printf("\n\n\n");
        printf("������ADT\n\n1.��ʼ��������\n2.��������\n3.��������\n4.ɾ������\n5.�������\n6.�������\n7.�������\n8.��α���\n9.�������(�ǵݹ�)\n10.�������(�ǵݹ�)\n11.�������(�ǵݹ�)\n12.�˳�(���ÿ�����)\n");
        printf("������һ����(1~12):");
        scanf_s("%d", &x);
    }
    system("pause");
    return 0;
}

void search(BTREE* tree)
{
    printf("��������Ҫ�������ݣ�");
    int x;
    while (scanf_s("%d", &x) == 0)
    {
        rewind(stdin);
        printf("�����������ʹ���\n");
        printf("��������Ҫ�������ݣ�");
    }
    TreeNode* node = BST_search(tree->root,x);
    if (node == NULL)
        printf("�˶����������ڸ�����");
    else
        printf("��%dλ����\n", q);
}

void insert(BTREE* tree)
{

    printf("������������ݣ�");
    int x;
    while (scanf_s("%d", &x) == 0)
    {
        rewind(stdin);
        printf("�����������ʹ���\n");
        printf("������������ݣ�");
    }
    BST_insert(tree, x);
    printf("�¶��������£�\n");
    inorderTraversal(tree->root, traverse);
}
void delete(BTREE* tree)
{
    printf("������ɾ�������ݣ�");
    int x;
    while (scanf_s("%d", &x) == 0)
    {
        rewind(stdin);
        printf("�����������ʹ���\n");
        printf("������ɾ�������ݣ�");
    }
    BST_delete(tree,x);
    printf("�¶��������£�\n");
    inorderTraversal(tree->root, traverse);
    printf("NULL");
}

