#pragma once
#include<iostream>
using namespace std;

#define BinNodePosi BinNode*

//BST�ڵ�Ľṹ��
struct BinNode {
	
	BinNode(int data) {

		data_ = data;
		lc = NULL;
		rc = NULL;
	}

	int data_;//�ؼ���
	BinNodePosi lc = NULL;//�����
	BinNodePosi rc = NULL;//�Ҷ���
};

class BST {

public:

	//����������ͨ���������ɾ���ڵ�
	~BST();
	//�ݹ飺������v�в��ҹؼ���e
	BinNodePosi &SearchIn(BinNodePosi &v, const int e, BinNodePosi &hot);
	//ͨ������SearchIn�㷨��ʵ��BST�ı�׼�ӿ�Search()
	BinNodePosi &Search(const int e);
	//BST�в����½ڵ�e�Ĺ���
	bool Insert(const int e);
	//ͨ������BST�ĺ������ɾ��BST�еĽڵ�
	void Release();
	//�ݹ飺BST�������������ӡ�ڵ㣩
	void TravIn_R(BinNodePosi x);
	//�ݹ飺BST�ĺ��������ɾ���ڵ㣩
	void TravPost_R(BinNodePosi x);
	//ͨ������TravIn_R��BST�еĹؼ�����С����ش�ӡ����
	void PrintBST();
	//�ж�BST�Ƿ�Ϊ��
	bool empty() { return !root_; }

private:

	BinNodePosi root_ = NULL;//����������ظ��ڵ�
	BinNodePosi hot_ = NULL;//��SearchIn���������ڴ洢��ǰ�ڵ�
};