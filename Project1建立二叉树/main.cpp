#include "function.h"

int main() {
	BiTree pnew;
	int i, j, pos;
	char c;
	BiTree tree = NULL;//������Ϊ��
	ptag_t phead = NULL, ptail = NULL, listpnew, pcur;//ptag�Ǹ������нṹ�� phead���Ƕ���ͷ��tail�Ƕ���β
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
}