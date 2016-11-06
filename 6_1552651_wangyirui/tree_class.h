#pragma once
#include<iostream>
#include<string>
using namespace std;

typedef struct TreeNode *PtrToNode;

struct  TreeNode{

	string name_;
	PtrToNode firstchild_ = NULL;                                 //��һ������
	PtrToNode presibling_ = NULL;                                 //ǰһ���ֵܽ���
	PtrToNode nextsibling_ = NULL;                                //��һ���ֵܽ���
};

class Tree {
public:
	~Tree();
	PtrToNode Find(string name, PtrToNode t);                     //����������Ѱ�ҽڵ�
	void Init(string name);                                       //��ʼ����������ڵ�
	void BuildFamily(string dadname, int sonnum, string *sonname);//���Ƽ�ͥ
	void AddChild(string dadname, string sonname);                //��Ӽ�ͥ��Ա
	void Remove(string name);                                     //��ɢ�ֲ���ͥ
	void RecursionForRemove(PtrToNode);                           //����remove�ĵݹ麯��
	void Modify(string oldname, string newname);                  //���ļ�ͥ��Ա����
	void PrintAncestor();                                         //��ӡ����
	void PrintSon(string name);                                   //��ӡ����
	void PrintNewName(string oldname, string name);               //��ӡ����ǰ�������
private:
	PtrToNode root_ = NULL;                                       //����
};
