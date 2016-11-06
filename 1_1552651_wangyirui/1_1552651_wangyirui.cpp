#include<iostream>
#include<string>
#include"examinee_class.h"
#include"examineelist_class.h"

using namespace std;

int main() {
	
	cout << "�����뽨��������Ϣϵͳ��" << endl
		<< "�����뿼�������� "<<flush;
	
	int sum;
	cin >> sum;
	//the total number is illegal
	while (sum <= 0) {

		cout << endl << "����Ƿ����֣����������룺 "<<flush;
		cin >> sum;
	}

	cout << "����������Ҫ����Ŀ����Ŀ��ţ��������Ա����估�������" << endl;

	int num, age, index;
	string name, gender, category;
	Examinee *examinee;
	ExamineeList *examinee_list = &ExamineeList::Instance();//create the linked list

	//add nodes to the linked list
	for (int i = 0; i < sum; ++i) {

		cin >> num >> name >> gender >> age >> category;
		examinee = new Examinee(num, name, gender, age, category);
		examinee_list->Insert(i + 1, examinee);
	}

	//print the list
	examinee_list->Output();
	cout << "��ѡ����Ҫ���еĲ�����1Ϊ���룬2Ϊɾ����3Ϊ���ң�4Ϊ�޸ģ�5Ϊͳ�ƣ�0Ϊȡ��������" << "\n\n"
		<< "��ѡ����Ҫ���еĲ����� " << flush;

	//store the operation type
	int operation;

	do {
		cin >> operation;

		while (operation < 0 || operation>5) {

			cout << '\n' << "����Ƿ����֣����������룺 "<<flush;
			cin >> operation;
		}
		
		//cancel
		if (operation == 0) {
			return 0;
		}

		//insert
		if (operation == 1) {

			cout << "��������Ҫ���뿼����λ�ã� "<<flush;
			cin >> index;

			if (index > examinee_list->total() + 1)
				cout << '\n' << "�ڴ�λ�ò���Ϊ�Ƿ�����" << endl;

			else {
				cout << "����������Ҫ����Ŀ����Ŀ��ţ��������Ա����估�������" << endl;
				cin >> num >> name >> gender >> age >> category;
				examinee = new Examinee(num, name, gender, age, category);
				examinee_list->Insert(index, examinee);
				examinee_list->Output();
			}
		}

		//delete
		if (operation == 2) {

			cout << "������Ҫɾ��������ѧ�ţ� " << flush;
			cin >> index;
			examinee_list->Delete(index);
			examinee_list->Output();
		}

		//search
		if (operation == 3) {

			cout << "������Ҫ���ҵĿ����Ŀ��ţ� " << flush;
			cin >> index;
			examinee_list->SearchOutput(index);
		}

		//modify
		if (operation == 4) {

			cout << "������Ҫ�޸ĵĿ����Ŀ��ţ� " << flush;
			cin >> index;
			cout << "����������Ҫ����Ŀ����Ŀ��ţ��������Ա����估�������" << endl;
			cin >> num >> name >> gender >> age >> category;
			examinee = new Examinee(num, name, gender, age, category);
			examinee_list->Modify(index, examinee);
			examinee_list->Output();
		}

		// statistics
		if (operation == 5) {

			sum = examinee_list->total();
			cout << '\n' << "������" << sum << "λ����" << endl;
			examinee_list->Output();
		}

		cout << "��ѡ����Ҫ���еĲ�����1Ϊ���룬2Ϊɾ����3Ϊ���ң�4Ϊ�޸ģ�5Ϊͳ�ƣ�0Ϊȡ��������" << "\n\n"
			<< "��ѡ����Ҫ���еĲ����� " << flush;

	} while (operation != 0);

	return 0;
}