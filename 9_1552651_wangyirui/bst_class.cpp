#include<string>
#include"bst_class.h"

//����������ͨ���������ɾ���ڵ�
BST::~BST() {

	Release();
}

//�ݹ飺������v�в��ҹؼ���e
BinNodePosi &BST::SearchIn(BinNodePosi &v, const int e, BinNodePosi &hot) {

	//�ݹ�������ڵ�Ϊ�ջ��ڽڵ��в��ҵ��ؼ���
	if (!v || (e == v->data_))
		return v;//���ڶ����������δ���ҵ��ؼ���ʱ���ص���һ����ָ��

	hot = v;//һ��������ȼ��µ�ǰ�ڵ�

	//�ݹ����
	return SearchIn(((e < v->data_) ? v->lc : v->rc), e, hot);
}

//ͨ������SearchIn�㷨��ʵ�ֶ���������ı�׼�ӿ�Search()
//�ڶ���������в��ҹؼ���e
BinNodePosi &BST::Search(const int e) {

	//����Ŀ��ڵ������
	return SearchIn(root_, e, hot_=NULL);
}

//����������в����½ڵ�e�Ĺ���
bool BST::Insert(const int e) {

	//�������ڸ��ڵ㣬�򽫴˽ڵ���Ϊ���ڵ�
	if (!root_) {
		auto root = new BinNode(e);
		root_ = root;
		return true;
	}

	//���ҹؼ���e�Ƿ����
	auto x = Search(e);
	//�����ڣ�����ʧ�ܣ�����
	if (x)
		return false;

	//�������ڣ�����ڵ�e
	x = new BinNode(e);

	//���ڵ�e������������
	if (e < hot_->data_)
		hot_->lc = x;
	else
		hot_->rc = x;
	
	return true;//���ز���ɹ�
}

void BST::Release() {

	if (root_)
		TravPost_R(root_);
	return;
}

//�ݹ飺������������������(��ӡ�ڵ�)
void BST::TravIn_R(BinNodePosi x) {

	if (!x)
		return;

	TravIn_R(x->lc);
	cout << x->data_ << "->";
	TravIn_R(x->rc);
	return;
}

//�ݹ飺BST�ĺ��������ɾ���ڵ㣩
void BST::TravPost_R(BinNodePosi x) {

	if (!x)
		return;

	TravPost_R(x->lc);
	TravPost_R(x->rc);
	delete x;
	return;
}

//ͨ������TravIn_R������������еĹؼ�����С����ش�ӡ����
void BST::PrintBST() {

	TravIn_R(root_);
	return;
}