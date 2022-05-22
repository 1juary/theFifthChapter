#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef struct BSTNode {//���ı�׼�ṹ��
	KeyType key;
	struct BSTNode* lchild, * rchild;
}BSTNode,*BiTree;

int BST_insert(BiTree& T, KeyType k) {
	if (NULL == T) {
		T = (BiTree)malloc(sizeof(BSTNode));//����ռ�����
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
		return BST_Search_recursion(T->lchild, key, p);
	}if (key > T->key) {
		return BST_Search_recursion(T->rchild, key, p);
	}
	else {
		return p;
	}
}
int main() {
	BiTree T;//ָ������
	BiTree parent;
	BiTree search;
	KeyType str[] = { 54,20,66,40,28,79,58 };
	Creat_BST(T, str,7);
	printf("\n");
	search = BST_Search(T, 40, parent);
	if (search)
	{
		printf("�ҵ���Ӧ����㣬ֵ=%d\n", search->key);
	}
	else {
		printf("δ�ҵ���Ӧ���\n");
	}
}