#pragma once

#include "TreeNode.h"
#include <string>
#include <sstream>
#include <stack>

using namespace std;

class Tree
{
private:
	// ������ �� �������� ���� ������
	TreeNode* root;
	// ������, ������������, �������� �� ���� ������ ��������
	bool isOperator(char c);
	// ������� ��� ���������� ������ ��������� ������
	void printTree(TreeNode* root, int space, ostream& ans);
	// ������� ��� ���������� ������ ��������� ������ ����������� ������� ������ � �������
	void printTreePreorder(TreeNode* root, int space, ostream& ans);
	// ������� ��� �������� ������ ����
	TreeNode* newNode(char v);
public:
	// ����������� ������, � ������� ��� � ��������
	Tree(string postfix);
	// ������� ��� ��������� ������ ��������� ������
	string toString();
	// ������� ��� ��������� ������ ��������� ������ ����������� ������� ������ � �������
	string toStringPreorder();
};

