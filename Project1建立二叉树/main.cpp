#define _CRT_SECURE_NO_WARNINGS
#include "function.h"


//ǰ�����
void preOrder(BiTree p) {
	if (NULL != p) {
		putchar(p->c);
		preOrder(p->lchild);
		preOrder(p->rchild);
	}
}
//�������  hdibjeafcg
void InOrder(BiTree p)
{
	if (p != NULL)
	{
		InOrder(p->lchild);
		putchar(p->c);
		InOrder(p->rchild);
	}
}
//hidjebfgca  �������
void PostOrder(BiTree p)
{
	if (p != NULL)
	{
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		putchar(p->c);
	}
}


//�������
void InOrder2(BiTree T) {
	SqStack S;
	InitStack(S); BiTree p = T;
	while (p || !StackEmpty(S)) {
		if (p)
		{//��һ����㲻Ϊ�գ�ѹջ����ȡ����
			Push(S, p);
			p = p->lchild;
		}
		else {//����ջ��Ԫ�ز���ӡ����ȡ��ӡԪ�ص��ҽ��
			Pop(S, p); putchar(p->c);
			p = p->rchild;//û������ʱ��ΪNULL
		}
	}
}

//�������
void LevelOrder(BiTree T)
{
	LinkQueue Q;//��������
	InitQueue(Q);//��ʼ������
	BiTree p;
	EnQueue(Q, T);//�������
	while (!IsEmpty(Q))
	{
		DeQueue(Q, p);//���ӵ�ǰ��㲢��ӡ
		putchar(p->c);
		if (p->lchild != NULL) //�������
			EnQueue(Q, p->lchild);
		if (p->rchild != NULL)  //����Һ���
			EnQueue(Q, p->rchild);
	}
}

int main() {
	BiTree pnew;
	int i, j, pos;
	char c;
	BiTree tree = NULL;//������Ϊ��
	ptag_t phead = NULL, ptail = NULL, listpnew = NULL ,pcur = NULL;//ptag�Ǹ������нṹ�� phead���Ƕ���ͷ��tail�Ƕ���β
	//abcddfghij ��Ҫ�����Ԫ��
while (scanf("%c", &c) != EOF) {
		if ('\n' == c) {
			break;
		}
		pnew = (BiTree)calloc(1, sizeof(BiTNode));
		//calloc ����ռ䣬ȫ��0
		pnew->c = c;//��������
		listpnew = (ptag_t)calloc(1, sizeof(tag));//�������е�Ԫ�أ�����ռ�
		listpnew->p = pnew;//������Ž���ַ
		if (NULL == tree) {//����Ϊ��
			tree = pnew;
			phead = listpnew;
			ptail = listpnew;
			pcur = listpnew;
			continue;//�ص���ȡ����
		}
		else {//�����ǿ�
			ptail->pnext = listpnew;
			ptail = listpnew;
		}//pcurʼ��ָ��Ҫ����Ľ���λ��
		if (NULL == pcur->p->lchild) {//����ǰ��ָ��Ԫ�ص�������û��Ԫ�أ��Ͱ���ɨ�赽��Ԫ�ط����λ��
			pcur->p->lchild = pnew;
		}
		else if(NULL == pcur->p->rchild)
		{
			pcur->p->rchild = pnew;
			pcur = pcur->pnext;
		}
	}
	printf("--------ǰ�����----------\n");//Ҳ������������ȴ�ӡ��ǰ��㣬��ӡ���ӣ���ӡ�Һ���
	preOrder(tree);
	printf("\n--------�������------------\n");//�ȴ�ӡ���ӣ���ӡ���ף���ӡ�Һ���
	InOrder(tree);
	printf("\n--------�������------------\n");//�ȴ�ӡ���ӣ���ӡ�Һ��ӣ�����ӡ����
	PostOrder(tree);
	printf("\n--------��������ǵݹ�------\n");//��Ҫ�Ե�
	InOrder2(tree);
}