#include "Tree.h"

bool Tree::isOperator(char c)
{
	if (c == '+' || c == '-' ||
		c == '*' || c == '/')
		return true;
	return false;
}

void Tree::printTreePreorder(TreeNode* root, int space, ostream& ans)
{
	// Условние выхода из функции, т.к. она рекурсивная
	if (!root)
		return;
	// Определение того, сколько пробелов добавлять для более "глубокого" уровня дерева
	int COUNT = 3;
	// Увеличение количества пробелов в данном уровне дерева
	space += COUNT;
	// Печать пробелов
	for (int i = COUNT; i < space; ++i)
		ans << " ";
	// Вывод значения узла
	ans << root->value << endl;
	// Рекурсивый вызов функции для левого узла
	printTreePreorder(root->left, space, ans);
	// Рекурсивый вызов функции для левого узла
	printTreePreorder(root->right, space, ans);
}

void Tree::printTree(TreeNode* root, int space, ostream& ans)
{
	// Условние выхода из функции, т.к. она рекурсивная
	if (!root)
		return;
	// Определение того, сколько пробелов добавлять для более "глубокого" уровня дерева
	int COUNT = 9;
	// Увеличение количества пробелов в данном уровне дерева
	space += COUNT;
	// Рекурсивый вызов функции для левого узла
	printTree(root->left, space, ans);
	// Печать пробелов
	for (int i = COUNT; i < space; ++i)
		ans << " ";
	// Вывод значения узла
	ans << root->value << endl;
	// Рекурсивый вызов функции для левого узла
	printTree(root->right, space, ans);
}

TreeNode* Tree::newNode(char v)
{
	// Создаём новый узел
	TreeNode* temp = new TreeNode;
	// Ссылки на дочерние элементы устанавливаем в nullptr
	temp->left = temp->right = nullptr;
	// Устанавливаем переданное в функцию значение в информационную часть узла
	temp->value = v;
	// Возвращаем узел
	return temp;
}

Tree::Tree(string postfix)
{
	stack<TreeNode*> st; // Стек для операндов
	TreeNode* t, * t1, * t2; // Временные переменные

	// Обходим выражение в постфиксной форме
	for (int i = 0; i < postfix.length(); i++)
	{
		// Если знак не является знаком операции => является операндом
		if (!isOperator(postfix[i])) {
			// То создаём новый узел со значением операнда
			t = newNode(postfix[i]);
			// И добавляем его в стек
			st.push(t);
		}
		// Если знак является знаком операции
		else {
			// То создаём новый узел со значением операции
			t = newNode(postfix[i]);
			
			// Получаем последние две цифры в стеке и удаляем их их из него
			t1 = st.top();
			st.pop();
			t2 = st.top();
			st.pop();

			// Устанавливаем те две цифры как дочерние узлы
			t->right = t1;
			t->left = t2;

			// Добавляем полученный узел в стек
			st.push(t);
		}
	}

	// Получаем самый верхний узел (корневой) из стека
	t = st.top();
	// Удаляем его из стека, т.е. стек остаётся пустым
	st.pop();

	// Устанавливаем значение корневого узла в переменную класса для хранения корневого узла
	this->root = t; 
}

string Tree::toString()
{
	stringstream ans; // Создания stringstream для конструирования строки структуры дерева
	printTree(this->root, 0, ans);
	return ans.str(); // Преобразование stringstream в string
}

string Tree::toStringPreorder()
{
	stringstream ans; // Создания stringstream для конструирования строки структуры дерева
	printTreePreorder(this->root, 0, ans);
	return ans.str(); // Преобразование stringstream в string
}
