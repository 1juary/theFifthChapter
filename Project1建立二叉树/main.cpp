#include "function.h"

int main() {
	BiTree pnew;
	int i, j, pos;
	char c;
	BiTree tree = NULL;//树根，为空
	ptag_t phead = NULL, ptail = NULL, listpnew, pcur;//ptag是辅助队列结构体 phead就是队列头，tail是队列尾
	//abcddfghij 将要输入的元素
	while (scanf("%c", &c) != EOF) {
		if ('\n' == c) {
			break;
		}
		pnew = (BiTree)calloc(1, sizeof(BiTNode));
		//calloc 申请空间，全赋0
		pnew->c = c;//放入数据
		listpnew = (ptag_t)calloc(1, sizeof(tag));//给队列中的元素，申请空间
		listpnew->p = pnew;//队列里放结点地址
		if (NULL == tree) {//树根为空
			tree = pnew;
			phead = listpnew;
			ptail = listpnew;
			pcur = listpnew;
			continue;//回到读取数据
		}
		else {//树根非空
			ptail->pnext = listpnew;
			ptail = listpnew;
		}//pcur始终指向要插入的结点的位置
		if (NULL == pcur->p->lchild) {//若当前所指的元素的左子树没有元素，就把新扫描到的元素放入该位置
			pcur->p->lchild = pnew;
		}
		else if(NULL == pcur->p->rchild)
		{
			pcur->p->rchild = pnew;
			pcur = pcur->pnext;
		}

	}
}