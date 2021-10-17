#include <iostream>
#include <stack>
#include "TreeNode.h"
#include "Tree.h"

using namespace std;

// Функция для определения приоритета операции
int prec(char c) {
	if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

// Фунция, определяющая, является ли знак знаком операции
bool isOperator(char c) {
	if (c == '+' || c == '-' ||
		c == '*' || c == '/')
		return true;
	return false;
}

// Функция для перевода выражения из инфиксной формы в постфиксную
string infixToPostfix(string s) {

	stack<char> st; // Стек для хранения операций
	string result; // Строка для постфиксной формы

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

// Функция для перевода выражения из префиксной формы в постфиксную
string prefixToPostfix(string s) {
	stack<string> st; // Стек для хранения операндов

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
	// Блок для демонстрации базового задания
	string infix = "1+2+3*4-5/6"; // Выражение в инфиксной форме
	string postfix = infixToPostfix(infix); // Перевод выражения в постфиксную форму
	Tree t1 = Tree(&postfix[0]); // Определение и инифиализация дерева решения

	cout << "Base task. Infix expression: " << infix << endl;

	cout << "Expression tree: " << endl;
	cout << t1.toString(); // Получение строки дерева решения и её вывод

	cout << endl << endl;

	// Блок для демонстрации индивидуального задания (11 вариант)
	string prefix = "+a+b-*cd/ef"; // Выражение в префиксной форме
	postfix = prefixToPostfix(prefix); // Перевод выражения в постфиксную форму
	Tree t2 = Tree(&postfix[0]); // Определение и инифиализация дерева решения

	cout << "Individual task. Prefix expression: " << prefix << endl;

	cout << "Expression tree " << endl;
	cout << t2.toStringPreorder() << endl; // Получение строки дерева решения (построенную прямым обходом в глубину) и её вывод
	return 0;
}
