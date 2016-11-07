#include<string>
#include"bst_class.h"

int main() {

	cout << "\n**               ����������               **"
		<< "\n============================================"
		<< "\n**             1 --- ��������������       **"
		<< "\n               2 --- ����Ԫ��             **"
		<< "\n               3 --- ��ѯԪ��             **"
		<< "\n               4 --- �˳�����             **"
		<< "\n============================================"
		<< endl;

	BST bst;

	while (true) {

		string operate;
		int num;

		cout << "\n\nPlease select: " << flush;
		cin >> operate;

		//���û�����1����ʼ��������������
		if (operate == "1") {

			cout << "Please input key to create Bsort_Tree:" << endl;
			while (cin >> num && num) {

				bool flag = bst.Insert(num);

				if (!flag)
					cout << "The input key<" << num << ">is have in" << endl;
			}
			cout << "Bsort_Tree is:" << endl;
			if (bst.empty())
				cout << "The Bsort_Tree is empty!" << endl;
			else
				bst.PrintBST();
		}
		
		//���û�����2����ʼ����Ԫ��
		else if (operate == "2") {

			cout << "Please input key which inserted: " << flush;
			cin >> num;

			bool flag = bst.Insert(num);

			if (!flag)
				cout << "The input key<" << num << ">is have in" << endl;

			cout << "Bsort_Tree is:" << endl;
			if (bst.empty())
				cout << "The Bsort_Tree is empty!" << endl;
			else
				bst.PrintBST();
		}

		//���û�����3����ʼ��ѯԪ��
		else if (operate == "3") {

			cout << "Please input key which searched: " << flush;
			cin >> num;

			bool flag = bst.Search(num);
			if (flag)
				cout << "search success!" << endl;
			else
				cout << num << " not exist!" << endl;
		}

		//���û�����4������ѭ�����˳�����
		else if (operate == "4")
			break;

		else
			cout << "������Ĳ�������Ƿ������������룡" << endl;
	}
	return 0;
}