#include"BT_class.h"

const int maxlen = 100;//�û�������ʽ����󳤶�
char inexpr[maxlen];//�洢�û�����ı��ʽ
pNode expr[maxlen];//�洢������ı��ʽ
int inexprcnt = 0;//�û�����ı��ʽ�ĳ���
int exprcnt = 0;//������ı��ʽ�ĳ���

BT bt;

void buildtree(pNode opr, pNode sucopd, pNode preopd) {

	opr->lc_ = preopd;
	opr->rc_ = sucopd;

}

void stackprocess(pNode *expr, int cnt, pNode &root) {

	stack<pNode> operands;//��ջ
	stack<pNode> operators;//��ջ
	pNode cur;//��ǰ�����Node
	int index = 0;

	while (index != cnt) {

		cur = expr[index];

		//����ǰ����
		if (cur->opr_=='(') {
			//����ƥ�����ţ���flag == 0ʱƥ�䵽��ȷ��')'
			int flag = 1;
			pNode tmp[maxlen];//�洢�����ڵı��ʽ
			int tmpcnt = 0;//�����ڱ��ʽ�ĳ���
			pNode tmproot = NULL;//�����ڱ��ʽ�������󷵻صĸ��ڵ�
			while (true) {

				++index;//��ȡ�����ڱ��ʽ��һ�����ֻ����

				//����һ��')'��flag�Լ�1
				if (expr[index]->opr_ == ')') {
					--flag;
					if (!flag)
						break;	//��flag == 0ʱƥ�䵽��ȷ��')'�����������������ݵ�ѭ��	
				}
				//����һ��'('�� flag�Լ�1
				if (expr[index]->opr_ == '(')
					++flag;

				//���ν����������ݴ���һ������
				tmp[tmpcnt++] = expr[index];
			}
			//���������ݵݹ����stackprocess����
			stackprocess(tmp, tmpcnt, tmproot);
			//�������ڱ��ʽ�������󷵻صĸ��ڵ�ѹ����ջ
			operands.push(tmproot);

			delete cur;
			delete expr[index];

		}
		//����ǲ�����
		else if (cur->pr_ > 0) {
			auto pre = expr[index - 1];
			if (!operators.empty() && operators.top()->pr_ < cur->pr_) {
				while (true) {
					auto opr = operators.top();
					operators.pop();
					auto sucopd = operands.top();
					operands.pop();
					auto preopd = operands.top();
					operands.pop();
					buildtree(opr, sucopd, preopd);//����������һ�����Ź���һ����
					//��¼���ĸ��ڵ�
					root = opr;
					//�����ɵ���ѹ����ջ
					operands.push(opr);		
					//��ջֱ��ջ�����ȼ����ڵ�ǰ����������������
					pre = operators.top();//���Ŀǰ��ջ������
					if (pre->pr_ >= cur->pr_)
						break;
				}
			}
			//����ǰ�����ѹջ
			operators.push(cur);
		}
		//����ǲ�������ֱ��ѹջ
		else if (cur->pr_ < 0)
			operands.push(cur);
		++index;
	}
	while (!operators.empty()) {
		auto opr = operators.top();
		operators.pop();
		auto sucopd = operands.top();
		operands.pop();
		auto preopd = operands.top();
		operands.pop();
		buildtree(opr, sucopd, preopd);//����������һ�����Ź���һ����
		root = opr;//��¼���ĸ��ڵ�
	   //�����ɵ���ѹ����ջ
		operands.push(opr);
	}
	root = operands.top();//���ڵ�Ϊ�������������ʽ����ջ��Ψһ��Ԫ��
}

void setinex() {

	int i = 0;
	while (i != inexprcnt) {
		pNode op = new Node;
		if (isdigit(inexpr[i])) {
			char num[maxlen];//�洢���ֵ��ַ���
			//ֱ�������������ֵ��ַ�
			int j = 0;
			while (isdigit(inexpr[i])) {
				num[j++] = inexpr[i++];
			}
			op->setNode(atoi(num), -1);//���洢���ֵ��ַ���ת��Ϊint������
			memset(num, 0, sizeof(num));
			expr[exprcnt++] = op;//������ʽ����
		}
		else {

			//���ݲ�ͬ�ļ�������������ȼ�

			if (inexpr[i] == '(' || inexpr[i] == ')') {
				op->setNode(inexpr[i], 0);
				expr[exprcnt++] = op;
			}

			if (inexpr[i] == '-') {
				//�жϴ�'-'Ϊ����
				if (i == 0 || !isdigit(inexpr[i - 1]) || inexpr[i + 1] == '(') {
					op->setNode(-1, -1);
					expr[exprcnt++] = op;//���ڴ����ı��ʽ�����з�������-1
					pNode op2 = new Node;
					op2->setNode('*', 2);
					expr[exprcnt++] = op2;//���ڴ����ı��ʽ�����з��������*
				}
				
				else {
					op->setNode(inexpr[i], 3);
					expr[exprcnt++] = op;
				}
			}

			if (inexpr[i] == '+') {
				op->setNode(inexpr[i], 3);
				expr[exprcnt++] = op;
			}

			if (inexpr[i] == '*' || inexpr[i] == '/') {
				op->setNode(inexpr[i], 2);
				expr[exprcnt++] = op;
			}
			++i;
		}
		
	}
}



int main() {

	printf("��������ʽ�� ");

	//���벢�洢�û�����ı��ʽ
	while (true){
		char c;
		scanf("%c", &c);
		if (c == '\n')
			break;
		inexpr[inexprcnt++] = c;
	}

	setinex();

	stackprocess(expr, exprcnt, bt.root_);

	printf("\n\n�������ʽ�� ");
	bt.travPre_R(bt.root_);

	printf("\n\n��׺���ʽ�� ");
	int i = 0;
	while (i != inexprcnt) {
		printf("%c", inexpr[i]);
		++i;
	}

	printf("\n\n�沨�����ʽ�� ");
	bt.travIn_R(bt.root_);


	printf("\n\n");

	return 0;
}