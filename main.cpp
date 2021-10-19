#include <iostream>
#include <stack>
#include "TreeNode.h"
#include "Tree.h"

using namespace std;

// ������� ��� ����������� ���������� ��������
int prec(char c) {
	if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

// ������, ������������, �������� �� ���� ������ ��������
bool isOperator(char c) {
	if (c == '+' || c == '-' ||
		c == '*' || c == '/')
		return true;
	return false;
}

// ������� ��� �������� ��������� �� ��������� ����� � �����������
string infixToPostfix(string s) {

	stack<char> st; // ���� ��� �������� ��������
	string result; // ������ ��� ����������� �����

	for (int i = 0; i < s.length(); i++) {
		char c = s[i];

		if (c >= '0' && c <= '9')
			result += c;
		else {
			while (!st.empty() && prec(s[i]) <= prec(st.top())) {
				result += st.top();
				st.pop();
			}
			st.push(c);
		}
	}

	while (!st.empty()) {
		result += st.top();
		st.pop();
	}

	return result;
}

// ������� ��� �������� ��������� �� ���������� ����� � �����������
string prefixToPostfix(string s) {
	stack<string> st; // ���� ��� �������� ���������

	for (int i = s.length() - 1; i >= 0; i--)
	{
		if (isOperator(s[i])) {
			string op1 = st.top();
			st.pop();
			string op2 = st.top();
			st.pop();

			string temp = op1 + op2 + s[i];

			st.push(temp);
		}
		else {
			if (('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z'))
				st.push(string(1, s[i]));
		}
	}

	return st.top();
}

int main() {
	// ���� ��� ������������ �������� �������
	string infix = "1+2+3*4-5/6"; // ��������� � ��������� �����
	string postfix = infixToPostfix(infix); // ������� ��������� � ����������� �����
	Tree t1 = Tree(&postfix[0]); // ����������� � ������������� ������ �������

	cout << "Base task. Infix expression: " << infix << endl;

	cout << "Expression tree: " << endl;
	cout << t1.toString(); // ��������� ������ ������ ������� � � �����

	cout << endl << endl;

	// ���� ��� ������������ ��������������� ������� (11 �������)
	string prefix = "+a+b-*cd/ef"; // ��������� � ���������� �����
	postfix = prefixToPostfix(prefix); // ������� ��������� � ����������� �����
	Tree t2 = Tree(&postfix[0]); // ����������� � ������������� ������ �������

	cout << "Individual task. Prefix expression: " << prefix << endl;

	cout << "Expression tree " << endl;
	cout << t2.toStringPreorder() << endl; // ��������� ������ ������ ������� (����������� ������ ������� � �������) � � �����
	return 0;
}
