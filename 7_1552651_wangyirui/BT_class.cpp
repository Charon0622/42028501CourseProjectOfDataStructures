#include "BT_class.h"

//���ʲ���ӡ��ӡ�ڵ�
void BT::visit(pNode x) {

	if (x->pr_ > 0)
		printf("%c", x->opr_);
	if (x->pr_ < 0)
		if (x->opd_ < 0 || x->opd_ > 9)
			printf("%c%d%c", '(', x->opd_, ')');
		else
			printf("%d", x->opd_);
}

//�������
void BT::travPre_R(pNode x) {

	if (!x)
		return;
	visit(x);
	travPre_R(x->lc_);
	travPre_R(x->rc_);
}

//�������
void BT::travIn_R(pNode x) {

	if (!x)
		return;
	travIn_R(x->lc_);
	travIn_R(x->rc_);
	visit(x);
}

//������ն�����
void BT::empty(pNode x) {

	if (!x)
		return;
	empty(x->lc_);
	empty(x->rc_);
	delete x;

}