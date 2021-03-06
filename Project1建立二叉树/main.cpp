#define _CRT_SECURE_NO_WARNINGS
#include "function.h"


//前序遍历
void preOrder(BiTree p) {
	if (NULL != p) {
		putchar(p->c);
		preOrder(p->lchild);
		preOrder(p->rchild);
	}
}
//中序遍历  hdibjeafcg
void InOrder(BiTree p)
{
	if (p != NULL)
	{
		InOrder(p->lchild);
		putchar(p->c);
		InOrder(p->rchild);
	}
}
//hidjebfgca  后序遍历
void PostOrder(BiTree p)
{
	if (p != NULL)
	{
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		putchar(p->c);
	}
}


//中序遍历    使用辅助栈
void InOrder2(BiTree T) {
	SqStack S;
	InitStack(S); BiTree p = T;
	while (p || !StackEmpty(S)) {
		if (p)
		{//当一个结点不为空，压栈，并取左孩子
			Push(S, p);
			p = p->lchild;
		}
		else {//弹出栈中元素并打印，获取打印元素的右结点
			Pop(S, p); putchar(p->c);
			p = p->rchild;//没有左孩子时，为NULL
		}
	}
}

//层序遍历   使用辅助队列
void LevelOrder(BiTree T)
{
	LinkQueue Q;//辅助队列
	InitQueue(Q);//初始化队列
	BiTree p;
	EnQueue(Q, T);//树根入队
	while (!IsEmpty(Q))
	{
		DeQueue(Q, p);//出队当前结点并打印
		putchar(p->c);
		if (p->lchild != NULL) //入队左孩子
			EnQueue(Q, p->lchild);
		if (p->rchild != NULL)  //入队右孩子
			EnQueue(Q, p->rchild);
	}
}

//初始化二叉树
//void InitBiTree(BiTree &T) {     //ptag_t 辅助队列可以在函数内实现
//
//}

int main() {
	BiTree pnew;       
	int i, j, pos;
	char c;
	BiTree tree = NULL;//树根，为空
	ptag_t phead = NULL, ptail = NULL, listpnew = NULL ,pcur = NULL;//ptag是辅助队列结构体 phead就是队列头，tail是队列尾
	//abcddfghij 将要输入的元素                                     //输入效果，层序输入，没有排序
	while (scanf("%c", &c) != EOF) {
		if ('\n' == c) {
			break;
		}
		pnew = (BiTree)calloc(1, sizeof(BiTNode));//树的结点,calloc,默认BiTree的左右子树全是null
		//calloc 申请空间，全赋0                 //(struct BiTNode* lchild)也在BiTree结构体中
		pnew->c = c;//放入数据
		listpnew = (ptag_t)calloc(1, sizeof(tag));//给辅助队列中的元素，申请空间
		listpnew->p = pnew;//队列里放结点地址   p是struct tag结构体中 BiTree树的结点
		if (NULL == tree) {//树根为空
			tree = pnew;             //结构体 示意图见 笔记
			phead = listpnew;
			ptail = listpnew;
			pcur = listpnew;
			continue;               //回到读取数据
		}
		else {                      //树根非空
			ptail->pnext = listpnew;  //没有赋值的结点 next 为NULL
			ptail = listpnew;         //尾结点永远指向最后结点
		}//pcur始终指向要插入的结点的位置
		if (NULL == pcur->p->lchild) {//若当前所指的元素的左子树没有元素，就把新扫描到的元素放入该位置
			pcur->p->lchild = pnew;   // tree = pnew,已经被指向tree ,BiTree tree 建立二叉树
		}
		else if(NULL == pcur->p->rchild)
		{
			pcur->p->rchild = pnew;
			pcur = pcur->pnext;       //此时，pcur->p->l/rchild  = null
		}
	}
	printf("--------前序遍历----------\n");//也叫先序遍历，先打印当前结点，打印左孩子，打印右孩子
	preOrder(tree);
	printf("\n--------中序遍历------------\n");//先打印左孩子，打印父亲，打印右孩子
	InOrder(tree);
	printf("\n--------后序遍历------------\n");//先打印左孩子，打印右孩子，最后打印父亲
	PostOrder(tree);
	printf("\n--------中序遍历非递归------\n");//重要性低
	InOrder2(tree);
}