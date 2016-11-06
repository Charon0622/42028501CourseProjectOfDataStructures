#include<iostream>
#include<stack>
#include<cstring>
#include<queue>
using namespace std;

class Node {

public:

	char opr_= NULL;//������
	int opd_ = 0;//������
	int pr_ = -2;//���ȼ�,�����������ȼ�Ϊ-1
	Node* lc_ = NULL;
	Node* rc_ = NULL;

	void setNode(char opr, int pr) {
		opr_ = opr;
		pr_ = pr;
	}

	void setNode(int opd, int pr) {
		opd_ = opd;
		pr_ = pr;
	}

};

typedef Node* pNode;

class BT {
public:

	pNode root_ = NULL;//���ʽ���ĸ��ڵ�

	void visit(pNode x);//���ʲ���ӡ��ӡ�ڵ�
	void travPre_R(pNode x);//�������
	void travIn_R(pNode x);//�������
	void empty(pNode x);//������ն�����

	~BT() { empty(root_); }
};