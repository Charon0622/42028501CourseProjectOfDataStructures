#include"tree_class.h"

Tree::~Tree() {

	RecursionForRemove(root_);
}

PtrToNode Tree::Find(string name, PtrToNode t) {


	if (t->name_ == name)
		return t;

	PtrToNode tmp = NULL;
	PtrToNode p = NULL;
	if (t->firstchild_ != NULL)
		for (p = t->firstchild_; p != NULL; p = p->nextsibling_) {
			tmp = Find(name, p);
			if (tmp != NULL)
				break;
		}

	return tmp;
}

void Tree::Init(string name) {

	root_ = new TreeNode;
	root_->name_ = name;

	cout << "�˼��׵������ǣ�" << root_->name_ << endl;
}

void Tree::BuildFamily(string dadname, int sonnum, string *sonname) {

	PtrToNode dad = Find(dadname, root_);

	if (dad == NULL) {
		printf("�����в����ڴ��ˣ�\n");
		return;
	}

	if (dad->firstchild_ != NULL) {
		printf("�������м�ͥ�������ظ�������\n");
		return;
	}

	PtrToNode son = new TreeNode;
	son->name_ = sonname[0];
	dad->firstchild_ = son;
	PtrToNode pre = dad->firstchild_;
	for (int i = 1; i < sonnum; ++i, pre = pre->nextsibling_) {
		son = new TreeNode;
		son->name_ = sonname[i];
		son->presibling_ = pre;
		pre->nextsibling_ = son;
	}
	return;
}

void Tree::AddChild(string dadname, string sonname) {

	PtrToNode dad = Find(dadname, root_);

	if (dad == NULL) {
		printf("�����в����ڴ��ˣ�\n");
		return;
	}

	PtrToNode son = new TreeNode;
	son->name_ = sonname;

	PtrToNode pre = dad->firstchild_;
	if (pre == NULL)
		dad->firstchild_ = son;
	else {
		while (pre->nextsibling_ != NULL)
			pre = pre->nextsibling_;
		son->presibling_ = pre;
		pre->nextsibling_ = son;
	}

	return;
}

void Tree::RecursionForRemove(PtrToNode t) {

	if (t->firstchild_ == NULL) {
		delete t;
		return;
	}
	for (PtrToNode p = t->firstchild_; p != NULL;) {
		PtrToNode next = p->nextsibling_;
		RecursionForRemove(p);
		p = next;
	}
	return;
}

void Tree::Remove(string name) {

	PtrToNode dad = Find(name, root_);
	if (dad == NULL) {
		printf("�����в����ڴ��ˣ�\n");
		return;
	}

	PtrToNode pre = dad->presibling_;
	PtrToNode next = dad->nextsibling_;
	if (pre != NULL)
		pre->nextsibling_ = next;
	if (next != NULL)
		next->presibling_ = pre;

	RecursionForRemove(dad);
	return;
}

void Tree::Modify(string oldname,string newname) {

	PtrToNode dad = Find(oldname, root_);
	if (dad == NULL) {
		printf("�����в����ڴ��ˣ�\n");
		return;
	}
	dad->name_ = newname;
	return;
}

void Tree::PrintAncestor() {

	cout << "�˼��׵������ǣ�" << root_->name_ << endl;
}

void Tree::PrintSon(string name) {

	PtrToNode dad = Find(name, root_);
	if (dad->firstchild_ == NULL) {
		cout << dad->name_ << "������\n";
		return;
	}
	cout << dad->name_ << "�ĵ�һ�������ǣ�";
	PtrToNode p = NULL;
	for (PtrToNode p = dad->firstchild_; p != NULL; p = p->nextsibling_)
		cout << p->name_ << "    ";
	printf("\n");

	return;
}

void Tree::PrintNewName(string oldname, string newname) {

	PtrToNode dad = Find(newname, root_);
	if (dad != NULL)
		cout << oldname << "�Ѹ���Ϊ" << dad->name_ << endl;
}