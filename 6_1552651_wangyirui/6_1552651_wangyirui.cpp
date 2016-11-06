#include"tree_class.h"
#include<vector>

int main() {

	Tree tree;

	string ancestorname, operate;
	printf("\n**               ���׹���ϵͳ              **\n");
	printf("=============================================\n");
	printf("**            ��ѡ��Ҫִ�еĲ���           **\n");
	printf("**              A---���Ƽ���               **\n");
	printf("**              B---��Ӽ�ͥ��Ա           **\n");
	printf("**              C---��ɢ�ֲ���ͥ           **\n");
	printf("**              D---���ļ�ͥ��Ա����       **\n");
	printf("**              E---�˳�����               **\n");
	printf("=============================================\n");
	printf("���Ƚ���һ�����ף�\n���������ȵ�������");
	cin >> ancestorname;
	tree.Init(ancestorname);

	while (true) {

		printf("\n��ѡ��Ҫִ�еĲ�����");
		cin >> operate;

		if (operate == "A") {
			string dadname, sonname;
			int sonnum;
			vector<string> sonnames;
			printf("������Ҫ������ͥ���˵�������");
			cin >> dadname;
			while (true) {
				cout << "������" << dadname << "�Ķ�Ů������";
				scanf("%d", &sonnum);
				if (sonnum > 0)
					break;
				printf("��������ַǷ������������룡��\n");
			}
			cout << "����������" << dadname << "�Ķ�Ů��������";
			for (int i = 0; i < sonnum; ++i) {
				cin >> sonname;
				sonnames.push_back(sonname);
			}
			tree.BuildFamily(dadname, sonnum, &sonnames[0]);
			tree.PrintSon(dadname);
		}
		else if (operate == "B") {
			string dadname, sonname;
			printf("������Ҫ��Ӷ���(��Ů��)���˵�������");
			cin >> dadname;
			cout << "������" << dadname << "����Ӷ���(��Ů��)��������";
			cin >> sonname;
			tree.AddChild(dadname, sonname);
			tree.PrintSon(dadname);
		}
		else if (operate == "C") {
			string dadname;
			printf("������Ҫ��ɢ��ͥ���˵�������");
			cin >> dadname;
			cout << "Ҫ��ɢ��ͥ�����ǣ�" << dadname << endl;
			tree.PrintSon(dadname);
			tree.Remove(dadname);
		}
		else if (operate == "D") {
			string oldname, newname;
			printf("������Ҫ�����������˵�Ŀǰ������");
			cin >> oldname;
			printf("��������ĺ��������");
			cin >> newname;
			tree.Modify(oldname, newname);
			tree.PrintNewName(oldname, newname);
		}
		else if (operate == "E")
			break;
		else {
			printf("������Ĳ�������Ƿ������������룡\n");
		}
	}
}