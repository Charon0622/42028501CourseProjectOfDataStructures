#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

int main() {

	map<string, size_t> article;
	string filename;

	cout << "�ؼ��ּ���ϵͳ\n"
		<< "�������ļ����� " << flush;

	cin >> filename;
	ofstream outfile(filename);
	cout << "\n������һ��Ӣ�ģ� " << endl;

	string word;
	char letter;
	getchar();
	//���ı����ַ������ļ���
	while (scanf("%c", &letter) != EOF) 
		outfile << letter;

	outfile.close();
	cout << "�����ı��ѱ������ı��ļ�\"src.txt\"�С�\n\n" << endl;

	ifstream infile(filename);
	string keyword;
	cout << "������Ҫ�����Ĺؼ��֣� " << flush;
	//�����û�����Ĺؼ���
	cin >> keyword;
	cout << "��ʾԴ�ļ�\"" << filename << "\":\n" << endl;

	//���ļ��е��ı����ַ������룬���ַ������д���
	while (infile >> word) {
		string realword;
		//�������еı�����ȥ��
		for (auto it = word.begin(); it != word.end(); it++) {
			if ((it == word.begin() || it == word.end() - 1) && ispunct(*it))
				continue;
			realword += *it;
		}
		//������תΪȫСд��ĸ
		transform(realword.begin(), realword.end(), realword.begin(), ::tolower);
		//���õ��ʲ�����map�У��򽫸ý����ʷ���map�У�����map��ֵ�Լ�һ
		++article[realword];
		cout << word << " ";
	}
	
	//���û�����Ĺؼ���תΪȫСд��ĸ
	transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);
	
	//��map�������û�����Ĺؼ���
	auto it = article.find(keyword);
	cout << "\n\n��Դ�ļ��й��������� " << it->second << "���ؼ���\"" << keyword << "\"" << endl;

	return 0;
}