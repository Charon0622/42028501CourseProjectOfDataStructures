#include"passenger_class.h"
#include"passengerlist_class.h"

int main() {

	int total, startnum, deathnum, residue;

	cout << "����N��Χ��һȦ���ӵ�S���˿�ʼ���α�������M���˳��֣�������һ�˿�ʼ���������ѭ����ֱ��ʣ��K��Ϊֹ" << "\n\n"
		<< "������������Ϸ��������N��" << flush;
	cin >> total;
	while (total < 1) {
		cout << "�����������Ϊ�Ƿ����֣����������룺" << flush;
		cin >> total;
	}

	cout << "��������Ϸ��ʼ��λ��S��  " << flush;
	cin >> startnum;
	while (startnum < 1 || startnum > total) {
		cout << "�����������Ϊ�Ƿ����֣����������룺" << flush;
		cin >> startnum;
	}

	cout << "��������������M��        " << flush;
	cin >> deathnum;
	while (deathnum < 1 || deathnum > total) {
		cout << "�����������Ϊ�Ƿ����֣����������룺" << flush;
		cin >> deathnum;
	}

	cout << "������ʣ�������������   " << flush;
	cin >> residue;
	while (residue < 0 || residue > total) {
		cout << "�����������Ϊ�Ƿ����֣����������룺" << flush;
		cin >> residue;
	}

	cout << endl;
	
	if (residue == 0) {
		cout << "���ź����������Ҵ���" << endl;
		return 0;
	}

	if (total == residue) {
		cout << "���˵��ǣ������˶������" << endl;
		return 0;
	}

	//initialize the linked list with arguments offered
	PassengerList passengerlist(total, startnum, deathnum, residue);

	passengerlist.Create();
	passengerlist.Kill();
	passengerlist.SurvivalListOutput();

	return 0;
}