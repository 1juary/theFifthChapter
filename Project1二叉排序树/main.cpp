#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef struct BSTNode {//���ı�׼�ṹ��
	KeyType key;
	struct BSTNode* lchild, * rchild;
}BSTNode,*BiTree;

int BST_insert(BiTree& T, KeyType k) {//�����ʱ����������õ��ݹ�
	if (NULL == T) {
		T = (BiTree)malloc(sizeof(BSTNode));//����ռ�����,��һ��Ԫ�أ������Ϊ�����
		T->key = k;
		T->lchild = T->rchild = NULL;//����ݹ�ʱ������������Ϊnull
		return 1;//��ʾ����ɹ�
	}
	else if (k == T->key)//���Ԫ����ͬ
		return 0;
	else if (k < T->key)
		return BST_insert(T->lchild, k);
	else
		return BST_insert(T->rchild, k);
}

void Creat_BST(BiTree& T, KeyType str[], int n) {
	T = NULL;
	int i = 0;
	while (i < n) {
		BST_insert(T, str[i]);
		i++;
	}
}
//����
BiTree BST_Search(BiTree T, KeyType key, BiTree& p) { // p��Ϊ���ظ�ֵ
	p = NULL;
	while (T != NULL && key != T->key) {
		p = T;
		if (key < T->key)
			T = T->lchild;
		else if(key > T->key)
			T = T->rchild;
		return T;
	}
}
//���� �ݹ鷨
BiTree BST_Search_recursion(BiTree T, KeyType key, BiTree& p) {
	p = T;
	if (T == NULL)
		return p;
	if (key < T->key) {
		return BST_Search_recursion(T->lchild, key, p);//��parent������T����᷵���Լ�
	}if (key > T->key) {
		return BST_Search_recursion(T->rchild, key, p);
	}
	else {
		return p;
	}
}
//�������
void InOrder(BiTree T) {
	if (NULL != T) {//�ݹ���Ҫ��������
		InOrder(T->lchild);
		printf("%3d", T->key);
		InOrder(T->rchild);
	}
}
//ǰ�����
void PreOrder(BiTree T) {
	if (NULL != T) {
		printf("%3d", T->key);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
void DeleteNode(BiTree& root, KeyType x) {//�е㸴��
	if (NULL == root) {
		return;
	}
	if (x < root->key) DeleteNode(root->lchild, x);
	else if (x > root->key) DeleteNode(root->rchild, x);
	else {//�ҵ�����Ӧ��Ԫ�أ�����Ҷ�ӽ��
		if (NULL == root->lchild) {
			BiTree tempNode = root;
			root = root->rchild;
			free(tempNode);
		}
		else if (NULL == root->rchild) {
			BiTree tempNode = root;
			root = root->lchild;
			free(tempNode);
		}
		else {
			BiTree tempNode = root->lchild;
			if (NULL != tempNode->rchild) {
				tempNode = tempNode->rchild;//�����ҵ���ֵ��Ҷ�ӽ��
			}
			root->key = tempNode->key;
			DeleteNode(root->lchild, tempNode->key);//���½���ݹ�
		}
	}
}
int main() {
	BiTree T;//ָ������
	BiTree parent;
	BiTree search;
	KeyType str[] = { 54,20,66,40,28,79,58 };
	Creat_BST(T, str,7);
	InOrder(T);
	printf("\n");
	PreOrder(T);
	printf("\n");
	search = BST_Search(T, 40, parent);
	if (search)
	{
		printf("�ҵ���Ӧ����㣬ֵ=%d\n", search->key);
	}
	else {
		printf("δ�ҵ���Ӧ���\n");
	}
	DeleteNode(T, 20);
	InOrder(T);
	printf("\n");
	system("pause");
}