#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef struct BSTNode {//树的标准结构体
	KeyType key;
	struct BSTNode* lchild, * rchild;
}BSTNode,*BiTree;

int BST_insert(BiTree& T, KeyType k) {
	if (NULL == T) {
		T = (BiTree)malloc(sizeof(BSTNode));//申请空间作根
		T->key = k;
		T->lchild = T->rchild = NULL;//进入递归时，左右子树设为null
		return 1;//表示插入成功
	}
	else if (k == T->key)//与根元素相同
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
//查找
BiTree BST_Search(BiTree T, KeyType key, BiTree& p) { // p是为返回根值
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
//查找 递归法
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
	BiTree T;//指向树根
	BiTree parent;
	BiTree search;
	KeyType str[] = { 54,20,66,40,28,79,58 };
	Creat_BST(T, str,7);
	printf("\n");
	search = BST_Search(T, 40, parent);
	if (search)
	{
		printf("找到对应父结点，值=%d\n", search->key);
	}
	else {
		printf("未找到对应结点\n");
	}
}