#include<iostream>
#include<string>
#include<map>
#include<queue>
using namespace std;
const int maxn = 100;

#define INF 1 << 30

struct node {
	int vnum;
	int key;//���Ѿ����ʹ��Ķ���ߵĳ�����Сֵ
	friend bool operator<(node a, node b) {
		return a.key > b.key;
	}
};

int n;//�������
int rootnum;//��ʼ�㣬����С�������ĸ��ڵ�
int graph[maxn][maxn];//�ڽӱ��洢������Ƿ������Լ������ߵĳ��ȵ���Ϣ
string vname[maxn];//�������ֶ�Ӧ�ڵ����
bool visited[maxn];//�����Ƿ���ʹ�
int dad[maxn];//��������С�������еĸ��׽ڵ�
node v[maxn];//prim�㷨�и�����״̬
map<int, int> tree;//�洢��С�������ı߼��ߵ�������
priority_queue <node> q;//ѡ����֪����

void prim(int beginnum){

	for (int i = 0; i < n; ++i) {
		v[i].vnum = i;
		v[i].key = INF;
		dad[i] = -1;
		visited[i] = false;
	}

	v[beginnum].key = 0;
	q.push(v[beginnum]);

	while (!q.empty()) {

		node cur_nd = q.top();
		q.pop();
		int cur_vnum = cur_nd.vnum;
		int dad_vnum = dad[cur_vnum];
		if (dad_vnum != -1)
			tree.insert(make_pair(dad_vnum, cur_vnum));
		if (visited[cur_vnum])
			continue;
		visited[cur_vnum] = true;

		for (int i = 0; i < n; ++i) {

			if (i != cur_vnum && !visited[i] && graph[cur_vnum][i] < v[i].key) {

				dad[i] = cur_vnum;
				v[i].key = graph[cur_vnum][i];
				q.push(v[i]);
			}
		}
	}
}


int main() {

	printf("\n**             �������ģ��ϵͳ            **\n");
	printf("=============================================\n");
	printf("**              A---������������           **\n");
	printf("**              B---��ӵ����ı�           **\n");
	printf("**              C---������С������         **\n");
	printf("**              D---��ʾ��С������         **\n");
	printf("**              E---�˳�����               **\n");
	printf("=============================================\n");

	char op;
	while (true) {

		printf("\n��ѡ�������");
		scanf("%c", &op);

		if (op == 'A') {

			printf("�����붥�������");
			scanf("%d", &n);
			printf("������������������ƣ�\n");
			for (int i = 0; i < n; ++i)
				cin >> vname[i];
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					graph[i][j] = INF;
			getchar();
		}

		if (op == 'B') {
			string v1, v2;
			int v1num, v2num;
			int len;
			while (true) {
				printf("�������������㼰�ߣ�");
				cin >> v1 >> v2 >> len;
				if (v1 == "?")
					break;
				for (int i = 0; i < n; ++i) {
					if (vname[i] == v1)
						v1num = i;
					if (vname[i] == v2)
						v2num = i;
				}
				graph[v1num][v2num] = len;
				graph[v2num][v1num] = len;
			}
			getchar();
		}
		if (op == 'C') {
			string root;		
			printf("��������ʼ���㣺");
			cin >> root;
			getchar();
			for (int i = 0; i < n; ++i) {
				if (vname[i] == root) {
					rootnum = i;
					break;
				}
			}
			prim(rootnum);
			printf("����prim��С��������\n");
		}
		if (op == 'D') {
			printf("��С�������Ķ��㼰��Ϊ��\n");
			for (auto vpair : tree) {
				int v1num = vpair.first;
				int v2num = vpair.second;
				cout << vname[v1num] << "-<" << graph[v1num][v2num] << ">->" << vname[v2num] << "	";
			}
			cout << endl;
			getchar();
		}
		if (op == 'E')
			break;
	}
}