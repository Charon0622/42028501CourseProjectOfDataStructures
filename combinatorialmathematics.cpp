#include<iostream>
#include<ctime>
using namespace std;

int cnt;

//bool scheme[200];//true��ʾ50Ԫ��false��ʾ100Ԫ
int n;//2n��ʾ����
int k;//ʣ��50����
int done;//�ѹ�Ʊ����
int res_100, res_50;//ʣ���ֳ�/100Ԫ/50Ԫ������
void search(int flag) {

	if (res_50 == 1 && flag) {
		/*scheme[done] = true;*/
		++done;
		--res_50;
		++k;
		++cnt;
		/*printf("\b����%d��\b", cnt);
		for (int i = 0; i < done; ++i) {
			printf("	��%d�ˣ�", i + 1);
			scheme[i] ? printf("%d", 50) : printf("%d", 100);
		}
		for (int i = done + 1; i < 2 * b; ++i) {
			printf("	��%d�ˣ�", i);
			printf("%d", 100);
		}*/
		return;
	}

	if (!k && !flag) {
		++done;
		--res_100;
		--k;
		return;
	}
	if (flag) {
		--res_50;
		/*scheme[done] = true;*/
		++done;
		++k;
	}
	else {
		--res_100;
		/*scheme[done] = false;*/
		++done;
		--k;
	}

	if (res_50) {
		search(true);
		++res_50;
		--done;
		--k;
	}
	if (res_100) {
		search(false);
		++res_100;
		--done;
		++k;
	}
	return;
}

int s_f[100], sum[100];
void stackmodel() {
	
	sum[0] = sum[1] = 1;
	for (int j = 2; j <= n; ++j) {
		for (int i = 1; i <= j; ++i) {
			s_f[i] = sum[i - 1] * sum[j - i];
			sum[j] += s_f[i];
		}
	}
	cnt = sum[n];
	return;
}

int r_f[100][100];
void recursion() {
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (!j)
				r_f[i][j] = 1;
			else if (i < j)
				r_f[i][j] = 0;
			else
				r_f[i][j] = r_f[i][j - 1] + r_f[i - 1][j];
		}
	}
	cnt = r_f[n][n];
	return;
}


int recurrence(int a, int b) {
	
	if (a < b)
		return 0;
	if (!b)
		return 1;
	return recurrence(a, b - 1) + recurrence(a - 1, b);
}

int Cpermutation[100][100];
//����C���� (n, r) = (n - 1, r) + (n - 1, r - 1)
//����C���� (n, r)�ĺ���
int permutation(int a, int b) {
	for (int i = 0; i <= a; ++i) {
		for (int j = 0; j <= b; ++j) {
			if (!j)
				Cpermutation[i][j] = 1;
			else if (i < j)
				Cpermutation[i][j] = 0;
			else
				Cpermutation[i][j] = Cpermutation[i - 1][j] + Cpermutation[i - 1][j - 1];
		}
	}
	return Cpermutation[a][b];
}

void combination() {
	cnt = permutation(2 * n, n) / (n + 1);
}

int main() {

	printf("��2n���Ŷӹ�Ʊ��������n��");
	scanf("%d", &n);

	printf("\n**             ��Ʊ����������             **\n");
	printf("=============================================\n");
	printf("**               ��ѡ���㷨               **\n");
	printf("**              1---��������              **\n");
	printf("**              2---ջģ��                **\n");
	printf("**              3---�ݹ��㷨              **\n");
	printf("**              4---�����㷨              **\n");
	printf("**              5---����㷨              **\n");
	printf("=============================================\n");
	int op;
	while (true) {
		printf("��ѡ���㷨��");
		scanf("%d", &op);
		cnt = 0;
		time_t t_start, t_end;
		t_start = time(NULL);
		if (op == 1) {
			res_50 = n;
			res_100 = n;
			done = 0;
			k = 0;
			search(true);
		}
		else if (op == 2)
			stackmodel();
		else if (op == 3)
			recursion();
		else if (op == 4)
			cnt = recurrence(n, n);
		else if (op == 5)
			combination();
		t_end = time(NULL);
		int t = difftime(t_end, t_start);
		printf("nΪ%dʱ������%d�ַ���������ʱ��Ϊ%ds\n", n, cnt, t);
	}
}