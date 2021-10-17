#pragma once

#include "TreeNode.h"
#include <string>
#include <sstream>
#include <stack>

using namespace std;

class Tree
{
private:
	// Ссылка на корневой узел дерева
	TreeNode* root;
	// Фунция, определяющая, является ли знак знаком операции
	bool isOperator(char c);
	// Функция для построения вывода структуры дерева
	void printTree(TreeNode* root, int space, ostream& ans);
	// Функция для построения вывода структуры дерева посредством прямого обхода в глубину
	void printTreePreorder(TreeNode* root, int space, ostream& ans);
	// Функция для создания нового узла
	TreeNode* newNode(char v);
public:
	// Конструктор дерева, в котором оно и создаётся
	Tree(string postfix);
	// Функция для получения вывода структуры дерева
	string toString();
	// Функция для получения вывода структуры дерева посредством прямого обхода в глубину
	string toStringPreorder();
};

