#include<iostream>
using namespace std;

char chessboard[50][50];                                         //����
int position[50];                                                //��¼ÿ�лʺ��λ��
bool column_available[50];                                       //��¼�����Ƿ��Ѵ��ڻʺ�

int n;
int cnt;

bool diagonal_availabe(int ln, int col) {                        //�ӶԽ��߽Ƕȿ��Ƿ����ڴ�λ�÷��ûʺ�

	for (int i = 0; i < ln; ++i)
		if (ln - i == col - position[i] || ln - i == position[i] - col)
			return false;
	
	return true;
}

void DFS(int ln) {

	if (ln == n) {                                               //ȫ��������ӡ����
		 
		++cnt;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j)
				cout << chessboard[i][j] << ' ';
			cout << endl;
		}
		cout << endl;
		return;
	}

	for (int i = 0; i < n; ++i) {

		if (column_available[i] && diagonal_availabe(ln, i)) {   //�кͶԽ��߶�����Ҫ��
			column_available[i] = false;
			chessboard[ln][i] = 'X';
			position[ln] = i;
			DFS(ln + 1);                                         //�ݹ�
			column_available[i] = true;                          //����
			chessboard[ln][i] = '0';
		}
	}
	return;
}

int main() {

	cout << "����N��N�����̣�����N���ʺ�Ҫ�����лʺ���ͬһ�С��к�ͬһб���ϣ�\n\n"
		<< "������ʺ�ĸ����� " << flush;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) 
			chessboard[i][j] = '0';	

		column_available[i] = true;
	}
	DFS(0);
	cout << "����" << cnt << "�ֽⷨ��" << endl;

	return 0;
}